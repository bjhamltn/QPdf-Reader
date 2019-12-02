#include "pdfprovider.h"
int tocId =0;
void lock_mutex(void *user, int lock)
{
    Q_UNUSED(lock)
    QMutex *mutex = static_cast<QMutex*>(user);
    mutex->lock();
}

void unlock_mutex(void *user, int lock)
{
    Q_UNUSED(lock)
    QMutex *mutex = static_cast<QMutex*>(user);
    mutex->unlock();
}

QString cleanRequestUrl(QString url){
    QString cmd(url);
    QUrl requestedUrl =  QUrl(cmd);
    QUrlQuery requestParams(requestedUrl);
    QString scale = requestParams.queryItemValue("scale");
    requestParams.removeQueryItem("ssid");
    requestedUrl.setQuery(requestParams.toString());
    return requestedUrl.toString();
}

PdfProvider::PdfProvider(QQuickImageProvider::ImageType type): QQuickImageProvider(type)
{
    mm = new QMutex(QMutex::Recursive);
    pagecnt = 0;
    filename = "";
    defaultwidth = 600;
    defaultheight = 700;
    fzimage = nullptr;
    fitWidth =true;
    fileloaded = false;
    dropIMG = false;
    neg = false;
    searchTerm="";
}

bool PdfProvider::isfitWidth(){
    return  fitWidth;
}

void PdfProvider::setNegMode(bool isNegative){
    neg = isNegative;
}

void PdfProvider::setFitToOption(int fit){
    switch(fit){
    case Fit_Width:
        fitWidth=true;
        break;
    case Fit_Height:
        fitWidth=false;
        break;
    default:
        fitWidth=false;
        break;
    }
}

void PdfProvider::setDefaultwidth(int w)
{
    defaultwidth = w;
}

void PdfProvider::setDefaultheight(int h)
{
    defaultheight = h;
}

bool PdfProvider::getNeg()
{
    return  neg;
}

int PdfProvider::getPageCnt()
{
    return pagecnt;
}

QString PdfProvider::getFileName()
{
    return filename;
}

void PdfProvider::loadFile(QString fpath){



    if(dropIMG)
    {
        fz_drop_pixmap(ctx,fzimage);
        dropIMG = false;
        delete tm;
    }
    if(fileloaded)
    {
        fz_drop_document(ctx, doc);
        fz_drop_context(ctx);
        pagecnt = 0;
        fileloaded = false;
    }




    filenamepath = std::move(fpath);
    QByteArray inBytes;
    inBytes = filenamepath.toUtf8();

    fz_locks_context locks;
    locks.user = mm;
    locks.lock = lock_mutex;
    locks.unlock = unlock_mutex;

    ctx = fz_new_context(nullptr, &locks, FZ_STORE_UNLIMITED);
    if (!ctx)
    {
        fileloaded = false;
        return;
    }
    fz_try(ctx){
        fz_register_document_handlers(ctx);
    }
    fz_catch(ctx)
    {
        fz_drop_context(ctx);
        fileloaded = false;
        return;
    }
    fz_try(ctx){
        doc = fz_open_document(ctx, inBytes.constData());
    }
    fz_catch(ctx)
    {
        fz_drop_context(ctx);
        fileloaded = false;
        return;
    }

    fz_try(ctx){
        pagecnt = fz_count_pages(ctx, doc);
    }
    fz_catch(ctx)
    {
        fz_drop_document(ctx, doc);
        fz_drop_context(ctx);
        fileloaded = false;
        return;
    }

    fz_try(ctx){
        pdf_document *docPdf = pdf_open_document(ctx, inBytes.constData());
        fz_outline *outline = pdf_load_outline(ctx, docPdf);
        tm = new TreeModel("Bookmarks");
        tocId = 0;
        printTOC(outline,ctx, tm->getRootItem());
        pdf_drop_document(ctx,docPdf);
        fz_drop_outline(ctx,outline);
    }
    fz_catch(ctx){
        fileloaded = false;
        return;
    }
    pageNumbers.clear();
    fz_page *page = fz_load_page(ctx, doc, 0);
    fz_rect page_bbox = fz_bound_page(ctx, page);
    fz_drop_page(ctx,page);
    for (int i=0;i<pagecnt;i++)
    {
        QVariantMap pg;
        pg.insert("name",i);
        pg.insert("width",page_bbox.x1);
        pg.insert("height",page_bbox.y1);
        pg.insert("cropFactor",0.0f);
        pg.insert("links",QVariantMap());
        pageNumbers.append(pg);
    }
    fileloaded = true;
}

QVariantList PdfProvider::getpageNumbers(){
    return pageNumbers;
}


void PdfProvider::printTOC(fz_outline* outline, fz_context* ctx, TreeItem *parentItem)
{
    while(outline != nullptr)
    {
        QList<QVariant> rr;
        rr << outline->title;
        rr << outline->page+1;
        int depth = 0;
        TreeItem *p = parentItem->parentItem();
        while(p != nullptr)
        {
            p = p->parentItem();
            depth++;
        }
        rr << depth;
        rr << tocId++;

        parentItem->appendChild(new TreeItem(rr, parentItem));
        if(outline->down != nullptr)
        {
            printTOC(outline->down, ctx, parentItem->getChildren().last());
        }

        if(outline->next)
        {
            outline = outline->next;
        }
        else {
            break;
        }
    }
}

fz_buffer* PdfProvider::writeSvg(  fz_context* ctx, fz_document* doc, int pageNbr,  fz_matrix ctm)
{
    fz_page* page = fz_load_page(ctx,doc, pageNbr);
    fz_rect brect = (fz_bound_page(ctx,page));
    fz_buffer *jj =fz_new_buffer(ctx, 500000);
    fz_output* output = fz_new_output_with_buffer(ctx,jj);
    fz_device* device = fz_new_svg_device(ctx, output, brect.x1 - brect.x0, brect.y1 - brect.y0, 1, 0);
    fz_run_page_contents(ctx, page, device, ctm, nullptr);
    fz_drop_device(ctx, device);
    fz_drop_page(ctx, page);
    return jj;
}

QImage PdfProvider::requestImage_WithRectHighlights(const QString &id,   QList<QPair<QString, QRect>> rects)
{
    const QSize requestedSize(0,0);
    QImage ii( requestImage(id, new QSize(),  requestedSize) );
    QPainter painter(&ii);
    QPen pen(Qt::green, 1);
    painter.setPen(pen);
    painter.drawRect(rects[0].second);
    return ii;
}



QPixmap PdfProvider::requestPixmap(const QString &id, QSize *size, const QSize &requestedSize){


    QString url = cleanRequestUrl(id);
    //    if(imageIndex.keys().contains(url))
    //    {
    //        QPixmap pixelmap = imageIndex.value(url);
    //        QtConcurrent::run(this, &PdfProvider::preloadPages,url);
    //        return  pixelmap;
    //    }
    QImage image = requestImageFinal( url, size, requestedSize);
    QPixmap pixelmap = QPixmap::fromImage(image);
    return  pixelmap;
}

QImage PdfProvider::requestImage(const QString &id, QSize *size, const QSize &requestedSize){
    return requestImageFinal( id, size, requestedSize);
}

QImage PdfProvider::requestImageFinal(const QString &id, QSize *size, const QSize &requestedSize)
{
    Q_UNUSED(size)
    Q_UNUSED(requestedSize)
    if(!fileloaded)
    {
        QImage image(10, 10, QImage::Format_RGB888);
        return image;
    }

    if(filenamepath=="")
    {
        return QImage();
    }


    if(dropIMG)
    {
        fz_drop_pixmap(ctx,fzimage);
    }


    QUrl requestedUrl =  QUrl(id);
    QUrlQuery requestParams(requestedUrl);
    QString scale = requestParams.queryItemValue("scale");
    QString angle =  requestParams.queryItemValue("angle");
    int pageNbr =  requestedUrl.path().toInt();

    QImage img = pagetoImage(pageNbr, scale, angle.toInt());

    return  img;
}

void PdfProvider::preloadPages(const QString &id){
    QUrl requestedUrl =  QUrl(id);
    QUrlQuery requestParams(requestedUrl);
    QString scale = requestParams.queryItemValue("scale");

    int pageNbr =  requestedUrl.path().toInt()+1;

    requestedUrl.setPath(QString::number(pageNbr));

    QString idNext = requestedUrl.toString();

    QImage img = pagetoImage(pageNbr, scale);
    if(!imageIndex.keys().contains(requestedUrl.toString()))
    {
        imageIndex.insert(requestedUrl.toString(),QPixmap::fromImage(img));
    }
}

QImage PdfProvider::pagetoImage(int pageNbr, QString scale, int angle)
{
    float zoom = 1.0f;
    if(scale!=""){
        zoom = scale.toFloat();
    }

    fz_page *page = fz_load_page(ctx, doc, pageNbr);
    fz_rect page_bbox = fz_bound_page(ctx, page);
    QVariantMap pageInfo =  static_cast<QVariant>( pageNumbers.at(pageNbr)).toMap();
    if(scale=="")
    {
        int defaultwidth_use = defaultwidth;
        int defaultheight_use = defaultheight;

        if(angle == 90 || angle == 270)
        {
            //std::swap(defaultwidth_use,defaultheight_use);
            if(isfitWidth())
            {
                zoom = defaultwidth_use/page_bbox.y1;
            }
            else
            {
                zoom = defaultheight_use/page_bbox.x1;
            }
        }
        else{
            if(isfitWidth())
            {
                zoom = defaultwidth_use/page_bbox.x1;
            }
            else
            {
                zoom = defaultheight_use/page_bbox.y1;
            }
        }
    }

    fz_matrix ctm = fz_scale(  devicePixelRatio *zoom,devicePixelRatio*zoom);
    ctm = fz_pre_rotate(ctm, static_cast<float>(angle));
    fz_try(ctx){
        fzimage = fz_new_pixmap_from_page(ctx,page,ctm, fz_device_rgb(ctx), 0);
    }
    fz_catch(ctx)
    {
        QImage img(10, 10, QImage::Format_RGB888);
        return img;
    }



    fz_clear_pixmap_with_value(ctx, fzimage, 0xff);
    fz_device *device = fz_new_draw_device(ctx,ctm, fzimage);

    ctm = fz_scale(1,1);
    fz_run_page(ctx, page, device, ctm, nullptr);

    if(neg){
        //fz_invert_pixmap(ctx,fzimage);
    }

    int width = fz_pixmap_width(ctx, fzimage);
    int height = fz_pixmap_height(ctx, fzimage);
    fz_rect pageRect = fz_bound_page(ctx, page);

    /// \brief get page links
    ///
    fz_link *pageLinks = fz_load_links(ctx, page);
    QVariantList pdfLinks;
    QTransform qMat_scale = QTransform::fromScale(qreal(zoom), qreal(zoom));


    //smart crop code start///////////////////
    /// \brief smartCropping
    ///
    QImage workerImage;
    if(smartCropping)
    {
        fz_stext_page *text = fz_new_stext_page(ctx, pageRect);
        fz_stext_options *opts = new fz_stext_options();
        opts->flags = FZ_STEXT_PRESERVE_IMAGES | FZ_STEXT_PRESERVE_WHITESPACE;
        fz_device * devv = fz_new_stext_device(ctx, text, opts);
        fz_run_page(ctx,page,devv,fz_identity, nullptr);
        fz_stext_block  *block;
        std::vector<float> xPos;
        std::vector<float> yPos;

        for (block = text->first_block; block; block = block->next)
        {
            if( block->type == 1){
                xPos.push_back(block->bbox.x0);
                xPos.push_back(block->bbox.x1);
                yPos.push_back(block->bbox.y0);
                yPos.push_back(block->bbox.y1);
            }
            else{
                fz_stext_line *line = new fz_stext_line();
                for(line = block->u.t.first_line; line ; line = line->next)
                {
                    fz_stext_char *cch = new fz_stext_char();
                    QString dd ="";
                    for(cch=line->first_char; cch; cch = cch->next)
                    {
                        char c = static_cast<char>(cch->c);
                        dd.append(c);
                    }
                    float x = line->first_char->quad.ul.x;
                    float y = line->first_char->quad.ul.y;
                    float x2 = line->last_char->quad.lr.x;
                    float y2 = line->last_char->quad.lr.y;
                    xPos.push_back(x);
                    xPos.push_back(x2);
                    yPos.push_back(y);
                    yPos.push_back(y2);
                }
            }
        }
        std::sort(xPos.begin(), xPos.end());
        std::sort(yPos.begin(), yPos.end());
        float  cropScale = 1;
        QRect rectCrop_Zero = QRect(int(xPos.at(0))-10,int(yPos.at(0)),int(xPos.back()) - int(xPos.at(0))+20,int(yPos.back()) - int(yPos.at(0))+10);
        QRect rectCrop = QRect(int(xPos.at(0))-10,int(yPos.at(0)),int(xPos.back()) - int(xPos.at(0))+20,int(yPos.back()) - int(yPos.at(0))+10);
        int cropOffset_X = rectCrop.x();
        int cropOffset_Y = rectCrop.y();
        QRect baseRect =QRect(0,0,rectCrop.width(),rectCrop.height());
        QTransform rTransform = QTransform::fromScale(1,1).rotate(angle);
        baseRect = rTransform.mapRect(baseRect);
        rTransform =QTransform::fromScale(1,1).translate(0 - baseRect.topLeft().x(), 0 -  baseRect.topLeft().y());
        baseRect = rTransform.mapRect(baseRect);

        bool isRotated = false;
        if(angle == 90){
            isRotated = true;
            int pageH = static_cast<int>(pageRect.y1);
            QPoint trls = rectCrop.bottomLeft();
            rTransform = QTransform::fromScale(1,1).translate(pageH-trls.y(),trls.x());
            rectCrop = rTransform.mapRect(baseRect);
        }
        else if(angle == 180){

            int pageH = static_cast<int>(pageRect.y1);
            int pageW = static_cast<int>(pageRect.x1);
            QPoint trls = rectCrop.bottomRight();
            rTransform = QTransform::fromScale(1,1).translate( pageW - trls.x(), pageH - trls.y()  );
            rectCrop = rTransform.mapRect(baseRect);
        }
        else if(angle == 270){
            isRotated = true;
            int pageW = static_cast<int>(pageRect.x1);
            QPoint trls = rectCrop.topRight();
            rTransform = QTransform::fromScale(1,1).translate( trls.y(), pageW - trls.x()  );
            rectCrop = rTransform.mapRect(baseRect);
        }
        if(isRotated){
            cropScale = isfitWidth() ? width /float(rectCrop.width()): height / float(rectCrop.height());
            if( rectCrop.width() < rectCrop.height())
            {
                cropScale =  width /float(rectCrop.width());
            }
        }
        else{
            cropScale = isfitWidth() ? width /float(rectCrop.width()): height / float(rectCrop.height());
            if( rectCrop.width() > rectCrop.height())
            {
                cropScale =  width /float(rectCrop.width());
            }
        }



        QTransform qMat = QTransform::fromScale(qreal(cropScale), qreal(cropScale));
        QRect rectCrop2 = qMat.mapRect(rectCrop);


        fz_matrix ctm2 = fz_scale(cropScale,cropScale);
        ctm2 = fz_pre_rotate(ctm2, angle);
        QImage imageCrop = pagetoImage(ctm2 ,page);


        if(searchTerm!="")
        {
            QPainter painter(&imageCrop);
            QPen pen( QBrush(QColor(0,0,0x80)) , 1 );
            painter.setPen(pen);
            painter.setBrush(QBrush(QColor(0,0,0x80,81)));
            fz_stext_page * stextPage = fz_new_stext_page_from_page(ctx,page,nullptr);
            fz_quad quadhits[512];
            int hits = fz_search_stext_page(ctx,stextPage,searchTerm.toLatin1().constData(),quadhits,512);
            for(int i=0; i < hits; i++)
            {
                fz_quad hit_bbox = quadhits[i];
                int x =  int(hit_bbox.ul.x);
                int y =  std::min( int(hit_bbox.ul.y) , int(hit_bbox.ur.y));
                int ww = int(hit_bbox.lr.x - hit_bbox.ul.x)+pen.width();
                int hh = std::abs( int(round(hit_bbox.lr.y - hit_bbox.ul.y)))+pen.width();
                QRect rect(x,y,ww,hh);

                baseRect =QRect(0,0,rect.width(),rect.height());
                QTransform rTransform = QTransform::fromScale(1,1).rotate(angle);
                baseRect = rTransform.mapRect(baseRect);
                rTransform =QTransform::fromScale(1,1).translate(0 - baseRect.topLeft().x(), 0 -  baseRect.topLeft().y());
                baseRect = rTransform.mapRect(baseRect);

                if(angle == 90){
                    int pageH = static_cast<int>(pageRect.y1);
                    QPoint trls = rect.bottomLeft();
                    rTransform = QTransform::fromScale(1,1).translate(pageH-trls.y(),trls.x());
                    rect = rTransform.mapRect(baseRect);
                }
                else if(angle == 180){
                    int pageH = static_cast<int>(pageRect.y1);
                    int pageW = static_cast<int>(pageRect.x1);
                    QPoint trls = rect.bottomRight();
                    rTransform = QTransform::fromScale(1,1).translate( pageW - trls.x(), pageH - trls.y()  );
                    rect = rTransform.mapRect(baseRect);
                }
                else if(angle == 270){
                    int pageW = static_cast<int>(pageRect.x1);
                    QPoint trls = rect.topRight();
                    rTransform = QTransform::fromScale(1,1).translate( trls.y(), pageW - trls.x()  );
                    rect = rTransform.mapRect(baseRect);
                }
                rect = qMat.mapRect(rect);
                painter.drawRect(rect);
            }
            fz_drop_stext_page(ctx,stextPage);
        }


        while(pageLinks != nullptr){
            QString uri(pageLinks->uri);
            if(uri.startsWith("#"))
            {
                QRect linkRect( int(pageLinks->rect.x0- cropOffset_X)
                                ,int(pageLinks->rect.y0- cropOffset_Y),
                                int(pageLinks->rect.x1- pageLinks->rect.x0),
                                int(pageLinks->rect.y1 -pageLinks->rect.y0));



                QTransform rTransform = QTransform::fromScale(1,1).rotate(angle);

                baseRect = QRect(0,0,linkRect.width(),linkRect.height());
                baseRect = rTransform.mapRect(baseRect);
                rTransform = QTransform::fromScale(1,1).translate(0 - baseRect.topLeft().x(), 0 -  baseRect.topLeft().y());
                baseRect = rTransform.mapRect(baseRect);

                if(angle == 90){
                    int pageH = rectCrop_Zero.height();
                    QPoint trls = linkRect.bottomLeft();
                    rTransform = QTransform::fromScale(1,1).translate(pageH-trls.y(),trls.x());
                    linkRect = rTransform.mapRect(baseRect);
                }
                else if(angle == 180){
                    int pageH = rectCrop_Zero.height();
                    int pageW = rectCrop_Zero.width();
                    QPoint trls = linkRect.bottomRight();
                    rTransform = QTransform::fromScale(1,1).translate( pageW - trls.x(), pageH - trls.y()  );
                    linkRect = rTransform.mapRect(baseRect);
                }
                else if(angle == 270){
                    int pageW = rectCrop_Zero.width();
                    QPoint trls = linkRect.topRight();
                    rTransform = QTransform::fromScale(1,1).translate( trls.y(), pageW - trls.x()  );
                    linkRect = rTransform.mapRect(baseRect);
                }




                linkRect = qMat.mapRect(linkRect);
                QString linkedPage = uri.split(",").at(0).mid(1);
                QVariantMap l;
                l.insert("page",linkedPage.toInt());
                l.insert("pos",linkRect);
                pdfLinks.append(l);
            }
            pageLinks = pageLinks->next;
        }
        pageInfo["links"]= pdfLinks;


        workerImage = imageCrop.copy(rectCrop2);





    }
    //smart crop code end///////////////////
    else{
        workerImage = QImage(std::move(fzimage->samples) ,width, height, static_cast<int>(fzimage->stride), QImage::Format_RGB888);
        if(searchTerm!=""){
            QPainter painter(&workerImage);
            QPen pen( QBrush(QColor(0,0,0x80)) , 1 );
            painter.setPen(pen);
            painter.setBrush(QBrush(QColor(0,0,0x80,81)));
            fz_stext_page * stextPage = fz_new_stext_page_from_page(ctx,page,nullptr);
            fz_quad quadhits[512];
            int hits = fz_search_stext_page(ctx,stextPage,searchTerm.toLatin1().constData(),quadhits,512);
            qMat_scale = QTransform::fromScale(qreal(zoom), qreal(zoom));
            for(int i=0; i < hits; i++)
            {
                fz_quad hit_bbox = quadhits[i];
                int x =  int(hit_bbox.ul.x);
                int y =  std::min( int(hit_bbox.ul.y) , int(hit_bbox.ur.y));
                int ww = int(hit_bbox.lr.x - hit_bbox.ul.x)+pen.width();
                int hh = std::abs( int(round(hit_bbox.lr.y - hit_bbox.ul.y)))+pen.width();
                QRect rect(x,y,ww,hh);

                QRect baseRect =QRect(0,0,rect.width(),rect.height());
                QTransform rTransform = QTransform::fromScale(1,1).rotate(angle);
                baseRect = rTransform.mapRect(baseRect);
                rTransform =QTransform::fromScale(1,1).translate(0 - baseRect.topLeft().x(), 0 -  baseRect.topLeft().y());
                baseRect = rTransform.mapRect(baseRect);

                if(angle == 90){
                    int pageH = static_cast<int>(pageRect.y1);
                    QPoint trls = rect.bottomLeft();
                    rTransform = QTransform::fromScale(1,1).translate(pageH-trls.y(),trls.x());
                    rect = rTransform.mapRect(baseRect);
                }
                else if(angle == 180){
                    int pageH = static_cast<int>(pageRect.y1);
                    int pageW = static_cast<int>(pageRect.x1);
                    QPoint trls = rect.bottomRight();
                    rTransform = QTransform::fromScale(1,1).translate( pageW - trls.x(), pageH - trls.y()  );
                    rect = rTransform.mapRect(baseRect);
                }
                else if(angle == 270){
                    int pageW = static_cast<int>(pageRect.x1);
                    QPoint trls = rect.topRight();
                    rTransform = QTransform::fromScale(1,1).translate( trls.y(), pageW - trls.x()  );
                    rect = rTransform.mapRect(baseRect);
                }



                rect = qMat_scale.mapRect(rect);
                painter.drawRect(rect);
            }
            fz_drop_stext_page(ctx,stextPage);

        }
        while(pageLinks != nullptr){
            QString uri(pageLinks->uri);
            if(uri.startsWith("#"))
            {
                QRect linkRect( int(pageLinks->rect.x0)
                                ,int(pageLinks->rect.y0),
                                int(pageLinks->rect.x1- pageLinks->rect.x0),
                                int(pageLinks->rect.y1 -pageLinks->rect.y0));

                QRect baseRect = QRect(0,0,linkRect.width(),linkRect.height());
                QTransform rTransform = QTransform::fromScale(1,1).rotate(angle);
                baseRect = rTransform.mapRect(baseRect);
                rTransform =QTransform::fromScale(1,1).translate(0 - baseRect.topLeft().x(), 0 -  baseRect.topLeft().y());
                baseRect = rTransform.mapRect(baseRect);

                if(angle == 90){
                    int pageH = static_cast<int>(pageRect.y1);
                    QPoint trls = linkRect.bottomLeft();
                    rTransform = QTransform::fromScale(1,1).translate(pageH-trls.y(),trls.x());
                    linkRect = rTransform.mapRect(baseRect);
                }
                else if(angle == 180){
                    int pageH = static_cast<int>(pageRect.y1);
                    int pageW = static_cast<int>(pageRect.x1);
                    QPoint trls = linkRect.bottomRight();
                    rTransform = QTransform::fromScale(1,1).translate( pageW - trls.x(), pageH - trls.y()  );
                    linkRect = rTransform.mapRect(baseRect);
                }
                else if(angle == 270){
                    int pageW = static_cast<int>(pageRect.x1);
                    QPoint trls = linkRect.topRight();
                    rTransform = QTransform::fromScale(1,1).translate( trls.y(), pageW - trls.x()  );
                    linkRect = rTransform.mapRect(baseRect);
                }




                linkRect = qMat_scale.mapRect(linkRect);
                QString linkedPage = uri.split(",").at(0).mid(1);
                QVariantMap l;
                l.insert("page",linkedPage.toInt());
                l.insert("pos",linkRect);
                pdfLinks.append(l);
            }
            pageLinks = pageLinks->next;
        }
        pageInfo["links"]= pdfLinks;
    }


    pageNumbers.replace(pageNbr, pageInfo);


    if(neg)
    {

        //        fz_stext_page *text = fz_new_stext_page(ctx, fz_bound_page(ctx, page));
        //        fz_stext_options *opts = new fz_stext_options();
        //        opts->flags = FZ_STEXT_PRESERVE_IMAGES | FZ_STEXT_PRESERVE_WHITESPACE;
        //        fz_device * devv = fz_new_stext_device(ctx, text, opts);
        //        fz_run_page(ctx,page,devv,fz_identity, nullptr);
        //        fz_stext_block  *block;
        //        std::vector<float> xPos;
        //        std::vector<float> yPos;
        //        QList<QImage> pageImages;
        //        QList<QRect> pageImagesRects;
        //        for (block = text->first_block; block; block = block->next)
        //        {
        //            if( block->type == 1){
        //               QRect imgRect = qMat.mapRect(QRect(int(block->bbox.x0),
        //                           int(block->bbox.y0),
        //                           int(block->bbox.x1 - block->bbox.x0),
        //                           int(block->bbox.y1 - block->bbox.y0)));
        //               pageImagesRects.append(imgRect);
        //               pageImages.append(workerImage.copy(imgRect));
        //            }
        //        }
        //        workerImage.invertPixels(QImage::InvertRgb);
        //        QPainter painter(&workerImage);
        //        for(int i=0; i<pageImages.length();i++)
        //        {
        //            painter.drawImage(pageImagesRects.at(i),pageImages.at(i));
        //        }
        workerImage.invertPixels(QImage::InvertRgb);
    }

    fz_drop_page(ctx,page);
    fz_drop_device(ctx,device);
    dropIMG = true;
    return workerImage;

}

QImage PdfProvider::pagetoImage(fz_matrix ctm, fz_page *page)
{
    fz_drop_pixmap(ctx,fzimage);
    fzimage = fz_new_pixmap_from_page(ctx,page,ctm, fz_device_rgb(ctx), 0);
    fz_clear_pixmap_with_value(ctx, fzimage, 0xff);
    fz_device *device = fz_new_draw_device(ctx,ctm, fzimage);
    ctm = fz_scale(1,1);
    fz_run_page(ctx, page, device, ctm, nullptr);
    int width = fz_pixmap_width(ctx, fzimage);
    int height = fz_pixmap_height(ctx, fzimage);
    QImage workerImage(std::move(fzimage->samples) ,width, height, fzimage->stride, QImage::Format_RGB888);
    fz_drop_device(ctx, device);
    return workerImage;
}

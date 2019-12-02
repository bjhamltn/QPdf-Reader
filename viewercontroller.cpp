#include "viewercontroller.h"
#include "tocmodel.h"

ViewerController::ViewerController(){}

void ViewerController::search(const QString searchTerm)
{
    if(searchFuture.isRunning())
    {
        searchFuture.cancel();
    }
    while (searchFuture.isRunning())
    {

    }
    workerList.clear();
    int pagecnt = 0;
    QByteArray inBytes;
    inBytes = filename.toUtf8();
    int workerCnt =1;

    m_ctx = fz_new_context(NULL, NULL, FZ_STORE_UNLIMITED);
    fz_register_document_handlers(m_ctx);
    m_doc = fz_open_document(m_ctx, inBytes.constData());

    pagecnt = fz_count_pages(m_ctx, m_doc);
    int jobSize = pagecnt/workerCnt;
    int re = pagecnt%workerCnt;

    fz_drop_document(m_ctx,m_doc);
    fz_drop_context(m_ctx);
    QList<QList<int>>jobs;
    int l=0;

    for(int i=0; i < workerCnt; i++)
    {
        auto *txtWrkr = new TextWorker();
        txtWrkr->name = QString(i);
        QList<int> job_x;
        for(int j=0;j<jobSize;j++)
        {
            job_x.append(l++);
        }
        jobs.append(job_x);
        QObject::connect(txtWrkr, SIGNAL(workresultready(QVariant)), engine->rootObjects().first(), SLOT(updateSearchResult(QVariant)));
        QObject::connect(txtWrkr, SIGNAL(workfinished()), this, SLOT(finished()));
        QObject::connect(txtWrkr, SIGNAL(workfinished()), engine->rootObjects().first(), SLOT(searchFinished()));
        workerList.append(txtWrkr);
    }
    if(re>0){
        while(jobs.last().length() < jobSize + re )
        {
            jobs.last().append(jobs.last().last()+1);
        }
    }
    for(int i=0;i<workerList.length();i++)
    {
        searchFuture = QtConcurrent::run(doTextWork, workerList.at(i), filename, jobs.at(i), searchTerm);
        workerList.at(i)->searchFuture = searchFuture;
    }

}

void ViewerController::setNegMode(QVariant isNegative){
    bool neg = isNegative.toBool();
    (this->pdfProvider)->setNegMode(neg);
}

void ViewerController::changeDefaultSize(QVariant w,QVariant h,QVariant fitmode){
    (this->pdfProvider)->setDefaultwidth(w.toInt());
    (this->pdfProvider)->setDefaultheight(h.toInt());
    (this->pdfProvider)->setFitToOption(fitmode.toInt());
}

void ViewerController::searhPDF(const QString term){
    this->search(term);
    this->pdfProvider->searchTerm = term;
}

void ViewerController::enableCropMode(QVariant isEnabled){
    this->pdfProvider->smartCropping = isEnabled.toBool();
}


void ViewerController::markText(QString searchTerm)
{
    this->pdfProvider->searchTerm = searchTerm;
    //    fz_stext_page * page = fz_new_stext_page_from_page_number(this->pdfProvider->ctx,this->pdfProvider->doc, pageNbr.toInt(), nullptr);
    //    fz_stext_block *block;
    //    fz_stext_line *line;
    //    QList<fz_rect> rects;
    //    fz_stext_char *ch;
    //    fz_buffer *buf;
    //    buf = fz_new_buffer(this->pdfProvider->ctx, 256);
    //    QList<QPair<QString, QRect>> pageContents;
    //    for (block = page->first_block; block; block = block->next)
    //    {
    //        if (block->type != FZ_STEXT_BLOCK_TEXT)
    //            continue;
    //        for (line = block->u.t.first_line; line; line = line->next)
    //        {
    //            rects.append( line->bbox );
    //            QRect rct( int(line->bbox.x0) ,int(line->bbox.y0),int( line->bbox.x1 - line->bbox.x0), int(line->bbox.y1- line->bbox.y0));
    //            for (ch = line->first_char; ch; ch = ch->next)
    //            {
    //                fz_append_rune(this->pdfProvider->ctx, buf, ch->c);
    //            }
    //            QString line( fz_string_from_buffer(this->pdfProvider->ctx, buf)  );
    //            QPair<QString, QRect>lineRect(line,rct);
    //            pageContents.append(lineRect);
    //            //line.append("\r\n");
    //            qDebug() <<  line;
    //        }
    //    }
    //    this->pdfProvider->requestImage_WithRectHighlights("1", pageContents);
    //    return rects;
}






QVariantList flattenTOC(TreeItem* ti, QVariantList flatToc)
{


    QList<TreeItem*> topSections = ti->getChildren();
    for (TreeItem* ii : topSections)
    {
        int k = ii->childCount();
        QVariantMap bm;
        bm.insert("title",ii->data(0));
        bm.insert("page",ii->data(1));
        bm.insert("depth",ii->data(2));
        bm.insert("kids",k);
        bm.insert("parent",ii->parentItem()->parentid());
        flatToc.append(bm);
        if(k > 0)
        {
            flatToc = flattenTOC(ii, flatToc);
        }
    }
    return flatToc;
}

QVariant ViewerController::getPageInfo(QVariant index)
{
   QVariant j = this->pdfProvider->pageInfo(index.toInt()) ;
   return  j;
}
void ViewerController::loadPdf(const QString filePath, QVariant width,QVariant height, QVariant fitMode)
{

    this->engine->rootContext()->setContextProperty("pageCnt", QVariant::fromValue(0));
    this->filename = filePath;
    this->pdfProvider->imageIndex.clear();
    (this->pdfProvider)->loadFile(filePath);
    (this->pdfProvider)->setDefaultwidth(width.toInt());
    (this->pdfProvider)->setDefaultheight(height.toInt());
    (this->pdfProvider)->setFitToOption(fitMode.toInt());
    QVariantList dataList= (this->pdfProvider)->getpageNumbers();
    this->pdfProvider->searchTerm = "";
    this->engine->rootContext()->setContextProperty("sourceinfo", QVariant::fromValue( dataList ));
    this->engine->rootContext()->setContextProperty("pageCnt", QVariant::fromValue( dataList.length()));
    this->engine->rootContext()->setContextProperty("pdfoutline", QVariant::fromValue((this->pdfProvider)->tm));

    TreeItem *ti =  this->pdfProvider->tm->getRootItem();
    QVariantList flatToc;
    flatToc = flattenTOC( ti,flatToc);
    TOCModel *tocModel = new TOCModel();

    for(QVariant bmd : flatToc)
    {
        QVariantMap bm = bmd.toMap();
        TOCItem tocItem(bm["title"].toString(), bm["page"].toInt(), bm["depth"].toInt(), bm["kids"].toInt(), bm["parent"].toInt(), bm["depth"].toInt()==0, false);
        tocModel->addContent(tocItem);
    }

    this->engine->rootContext()->setContextProperty("pdfoutline_flat", tocModel);


    return;
}

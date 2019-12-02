#include "textworker.h"
TextWorker::TextWorker(){}
void TextWorker::getText( QString filename,  QList<int> pages, QString searchTerm)
{
    QByteArray inBytes;
    inBytes = filename.toUtf8();
    fz_context *ctx;
    fz_document *doc;
    ctx = fz_new_context(NULL, NULL, FZ_STORE_UNLIMITED);
    fz_register_document_handlers(ctx);
    doc = fz_open_document(ctx, inBytes.constData());
    QString optStr = "preserve-ligatures=no, preserve-whitespace=yes, preserve-images=no, inhibit-spaces=no";
    fz_stext_options opts;
    fz_parse_stext_options(ctx, &opts,  optStr.toUtf8().constData());
    for(int i= pages.first(); i<=pages.last(); i++)
    {
        if(searchFuture.isCanceled())
        {
            return;
        }
        fz_page *page = fz_load_page(ctx,doc,i);
        fz_buffer *buff = fz_new_buffer_from_page(ctx, page,nullptr);
        QString pageText(fz_string_from_buffer(ctx,buff));
        fz_drop_buffer(ctx,buff);
        fz_drop_page(ctx,page);
        QVariantMap map;
        int hits = pageText.toLower().count(searchTerm.toLower());
        pageText = pageText.replace("\n\n", " ");
        pageText = pageText.replace("\n", " ");
        QString hay =pageText.toLower();
        searchTerm = searchTerm.toLower();
        if(hits > 0)
        {
            int  idx =0;
            while(hay.indexOf(searchTerm,idx) > -1 &&  idx < hay.length()-1)
            {
                idx = hay.indexOf(searchTerm,idx);
                int idx2 = hay.indexOf("",idx+searchTerm.length()-1);

                int leadingWordCnt = 3;
                while(hay.lastIndexOf(" ", idx-1) > -1 &&  leadingWordCnt > 0)
                {
                    idx = hay.lastIndexOf(" ", idx-1);
                    leadingWordCnt--;
                }

                int trailingWordCnt = 11;
                while(hay.indexOf(" ", idx2+1) > -1 &&  trailingWordCnt > 0)
                {
                    idx2 = hay.indexOf(" ", idx2+1);
                    trailingWordCnt--;
                }

                QString dd = pageText.mid(idx,idx2-idx);
                dd =dd.replace("\n\n", " ");
                idx = idx2;
                map.insert("result", dd);
                map.insert("hits", 1);
                map.insert("page", i+1);
                map.insert("worker",  this->name);

                emit workresultready(QVariant::fromValue(map));
                break;
            }

        }
        else{
            map.insert("result", "");
            map.insert("hits", 0);
            map.insert("page", i+1);
            map.insert("worker",  this->name);
            emit workresultready(QVariant::fromValue(map));
        }
    }
    fz_drop_document(ctx,doc);
    fz_drop_context(ctx);
    emit workfinished();
}



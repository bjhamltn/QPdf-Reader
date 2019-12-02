#ifndef ViewerController_H
#define ViewerController_H

#include <QObject>
#include <QVariant>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QRect>
#include <QDir>
#include <QDirIterator>

#include <QDebug>
#include <QtCore/QObject>
#include <QQmlContext>

#include <QFutureWatcher>
#include <QtConcurrent>
#include <future>
#include "treemodel.h"
#include "textworker.h"
#include "pdfprovider.h"
#include "dataobject.h"
#include <QVariantMap>
#include <mupdf/fitz.h>
#include <mupdf/pdf.h>
#include <mupdf/fitz/util.h>
#include <mupdf/fitz/document.h>

class ViewerController : public QObject{
    Q_OBJECT
public:
    PdfProvider *pdfProvider;
    QQmlApplicationEngine *engine;
    QFuture<void> searchFuture;
    explicit ViewerController();

signals:
    void notitfyResult(QVariant);

public slots:       
    Q_INVOKABLE QVariant getPageInfo(QVariant index);
    void loadPdf(QString, QVariant,QVariant,QVariant);
    void enableCropMode(QVariant);
    void searhPDF(QString);
    void markText(QString);
    void changeDefaultSize(QVariant,QVariant,QVariant);
    void setNegMode(QVariant isNegative);

    void finished()
    {
        qDeleteAll(workerList);
    }



public:

    fz_context *m_ctx;
    fz_document *m_doc;
    QString filename;
    QList<TextWorker*> workerList;

    void search(const QString searchTerm);

    Q_INVOKABLE void clearSearchTerm(){
        pdfProvider->searchTerm="";
    }

    Q_INVOKABLE void cancelSearch()
    {
           searchFuture.cancel();
    }
    static void doTextWork(TextWorker *worker, QString filePath, QList<int> pages, QString searchTerm)
    {
        worker->getText(filePath, pages, searchTerm);
    }


    static int line_length(fz_stext_line *line)
    {
        fz_stext_char *ch;
        int n = 0;
        for (ch = line->first_char; ch; ch = ch->next)
            ++n;
        return n;
    }


};

#endif

#ifndef TEXTWORKER_H
#define TEXTWORKER_H
#include <QObject>
#include <QVariantMap>
#include <future>
#include <mupdf/fitz.h>
#include <mupdf/pdf.h>
#include <mupdf/fitz/util.h>
#include <mupdf/fitz/document.h>
#include <QFutureWatcher>
class TextWorker: public QObject{
    Q_OBJECT
public:
    explicit TextWorker();
    QString name;
    QString searchTerm;
    QList<int> pagesNumbers;    
    QFuture<void> searchFuture;
signals:
    void workresultready(QVariant);
    void workfinished();

public:
    void getText( QString filename,  QList<int> pages, QString searchTerm);
};

#endif

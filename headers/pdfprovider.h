#ifndef PDFPROVIDER_H
#define PDFPROVIDER_H
#include <QString>
#include <QImage>
#include <mupdf/fitz.h>
#include <mupdf/pdf.h>
#include <mupdf/fitz/util.h>
#include <mupdf/fitz/document.h>
#include "treemodel.h"
#include <qquickimageprovider.h>
#include <QUrlQuery>
#include <QPainter>
#include <QPen>
#include <QFutureWatcher>
#include <QtConcurrent>
class PdfProvider : public QQuickImageProvider{

private:    
    int pagecnt;
    QString filename;
    QString filenamepath;
    QVariantList  pageNumbers;    
    int defaultwidth;
    int defaultheight;
    bool fileloaded;
    bool fitWidth;

    fz_pixmap *fzimage;
    bool dropIMG;
    bool neg;
public:
    QVariant pageInfo(int idx){
        return pageNumbers.at(idx);
    }
    float devicePixelRatio = 1;
    QMap<QString,QPixmap> imageIndex;
    QString searchTerm;
    bool smartCropping = false;
    fz_context *ctx;
    fz_document *doc;
    TreeModel *tm;
    enum FIT{
        Fit_Width,
        Fit_Height
    };


    PdfProvider(QQuickImageProvider::ImageType type);

    QMutex *mm;
    bool isfitWidth();
    void setNegMode(bool isNegative);
    void preloadPages(const QString &id);
    void setFitToOption(int fit);
    void setDefaultwidth(int w);
    void setDefaultheight(int h);
    bool getNeg();
    int getPageCnt();

    QString getFileName();

    void loadFile(QString fpath);
    QVariantList getpageNumbers();

    void printTOC(fz_outline* outline, fz_context* ctx, TreeItem *parentItem);

    fz_buffer* writeSvg(  fz_context* ctx, fz_document* doc, int pageNbr,  fz_matrix ctm);





public:
    QImage pagetoImage(int pageNbr,QString scale,  int angle=0);
    QImage pagetoImage( fz_matrix ctm, fz_page *page);
    QImage requestImageFinal(const QString &id, QSize *size, const QSize &requestedSize);
    QPixmap requestPixmap(const QString &id, QSize *size, const QSize &requestedSize);
    QImage requestImage(const QString &id, QSize *size, const QSize &requestedSize);
    QImage requestImage_WithRectHighlights(const QString &id,   QList<QPair<QString, QRect>> rects);

};
#endif

#include <imageview.h>





ImageView::ImageView(QQuickItem *parent) :
    QQuickItem(parent),
    m_color(Qt::red),
    m_needUpdate(true)
{
    setFlag(QQuickItem::ItemHasContents);
}

QSGNode *ImageView::updatePaintNode(QSGNode *oldNode, QQuickItem::UpdatePaintNodeData *updatePaintNodeData)
{
    Q_UNUSED(updatePaintNodeData)
    //QSGGeometryNode *root = static_cast<QSGGeometryNode *>(oldNode);
    QSGSimpleTextureNode *root = static_cast<QSGSimpleTextureNode *>(oldNode);

    if(!root) {
        root = new QSGSimpleTextureNode();

        QImage gssf("D:\\build-swipepages-Desktop_Qt_5_12_2_MSVC2017_32bit-Debug\\page_844.png");
        setWidth(gssf.width());
        setHeight(gssf.height());
        QSGTexture *texture = this->window()->createTextureFromImage(gssf);
        root->setTexture(texture);
//        root = new QSGGeometryNode;
//        QSGGeometry *geometry = new QSGGeometry(QSGGeometry::defaultAttributes_Point2D(), 3);
//        geometry->setDrawingMode(GL_TRIANGLE_FAN);
//        geometry->vertexDataAsPoint2D()[0].set(width() / 2, 0);
//        geometry->vertexDataAsPoint2D()[1].set(width(), height());
//        geometry->vertexDataAsPoint2D()[2].set(0, height());
//        root->setGeometry(geometry);
//        root->setFlag(QSGNode::OwnsGeometry);
//        root->setFlag(QSGNode::OwnsMaterial);
    }

    if(m_needUpdate) {
          root->setRect(boundingRect());
          return root;
//        QSGFlatColorMaterial *material = new QSGFlatColorMaterial;
//        material->setColor(m_color);
//        root->setMaterial(material);
//        m_needUpdate = false;
    }
    widthChanged();
    heightChanged();
    return root;
}


QColor ImageView::color() const
{
    return m_color;
}

void ImageView::setColor(const QColor &color)
{
    if(m_color != color) {
        m_color = color;
        m_needUpdate = true;
        update();
        colorChanged();
    }
}

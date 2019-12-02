
#ifndef TREEITEM_H
#define TREEITEM_H

#include <QList>
#include <QVariant>

class TreeItem: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString title READ title)
    Q_PROPERTY(int depth READ depth)
    Q_PROPERTY(int parentid READ parentid)
public:
    explicit TreeItem(const QList<QVariant> &data, TreeItem *parentItem = nullptr);
    ~TreeItem();

    TreeItem *parentItem();
    TreeItem *child(int row);
    QVariant data(int column) const;
    void appendChild(TreeItem *child);
    int childCount() const;
    int columnCount() const;
    int row() const;
    void addChild(TreeItem *el);
    QString title();
    int depth();
    int parentid();
    QList<TreeItem*> getChildren();
private:
    QList<TreeItem*> m_childItems;
    QList<QVariant> m_itemData;
    TreeItem *m_parentItem;
};

#endif // TREEITEM_H

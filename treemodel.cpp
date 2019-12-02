#include "treeitem.h"
#include "treemodel.h"


TreeModel::TreeModel(const QString &data, QObject *parent)
    : QAbstractItemModel(parent)
{
    QList<QVariant> rootData;
    rootData << data << "page";
    rootItem = new TreeItem(rootData);
}

TreeModel::~TreeModel()
{
    delete rootItem;
}

QHash<int, QByteArray> TreeModel::roleNames() const{
    QHash<int, QByteArray> roles;
    roles[TitleRole] = "section_title";
    roles[PageRole] = "page_number";
    return roles;
}

int TreeModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return static_cast<TreeItem*>(parent.internalPointer())->columnCount();
    else
       return rootItem->columnCount();
}

QString section_title(TreeItem *item) {
     return item->data(0).toString();
}
QString page_number(TreeItem *item) {
     return item->data(1).toString();
}

QVariant TreeModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    TreeItem *item = static_cast<TreeItem*>(index.internalPointer());
    if(role ==TitleRole)
    {
        return QVariant::fromValue(item->data(0));
    }
    else if(role ==PageRole){
        return QVariant::fromValue(item->data(1));
    }
    else if(role ==DepthRole){
        return QVariant::fromValue(item->data(2));
    }
    else
    {        
        return item->data(index.column());
    }
}

Qt::ItemFlags TreeModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return nullptr;
    return QAbstractItemModel::flags(index);
}

QVariant TreeModel::headerData(int section, Qt::Orientation orientation,
                               int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
        return rootItem->data(section);
    return QVariant();
}

QModelIndex TreeModel::index(int row, int column, const QModelIndex &parent)const
{
    if (!hasIndex(row, column, parent))
        return QModelIndex();

    TreeItem *parentItem;

    if (!parent.isValid())
        parentItem = rootItem;
    else
        parentItem = static_cast<TreeItem*>(parent.internalPointer());

    if (parentItem->child(row))
    {
        return createIndex(row, column, parentItem->child(row));
    }
    else
        return QModelIndex();
}

QModelIndex TreeModel::parent(const QModelIndex &index) const
{

    if (!index.isValid())
        return QModelIndex();

    TreeItem *parentItem = static_cast<TreeItem*>(index.internalPointer())->parentItem();
    if (parentItem == rootItem)
        return QModelIndex();

    return createIndex(parentItem->row(), 0, parentItem);
}

int TreeModel::rowCount(const QModelIndex &parent) const
{
    TreeItem *parentItem;
    if (parent.column() > 0)
        return 0;

    if (!parent.isValid())
        parentItem = rootItem;
    else
        parentItem = static_cast<TreeItem*>(parent.internalPointer());

    return parentItem->childCount();
}



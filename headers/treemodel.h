#ifndef TREEMODEL_H
#define TREEMODEL_H
#include <QAbstractItemModel>
#include <QModelIndex>
#include <QVariant>
#include <QDebug>
#include <exception>
#include <treeitem.h>

class TreeModel : public QAbstractItemModel
{
    Q_OBJECT


public:

    ~TreeModel()override;

    enum TreeModelRoles {
        TitleRole = Qt::UserRole + 1,
        PageRole,
        SizeRole,
        DepthRole
    };

    QString section_title(TreeItem *item) const;

    QString page_number(TreeItem *item) const;

    QHash<int, QByteArray> roleNames() const override;

    explicit TreeModel(const QString &data, QObject *parent = nullptr);

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const override;

    Qt::ItemFlags flags(const QModelIndex &index) const override;

    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;

    QModelIndex parent(const QModelIndex &index) const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    TreeItem* getRootItem(){return rootItem;}

private:    
    void buildModel();
    TreeItem *rootItem;
};
//! [0]

#endif // TREEMODEL_H

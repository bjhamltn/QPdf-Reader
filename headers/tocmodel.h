#ifndef TOCMODEL_H
#define TOCMODEL_H
#include <QAbstractListModel>
#include <QModelIndex>
#include <QVariant>
#include <QDebug>
#include <exception>
#include <tocitem.h>

class TOCModel : public QAbstractListModel
{
    Q_OBJECT

public:



    explicit TOCModel(QObject *parent = nullptr);
    ~TOCModel()override;
    //starts at 257
    enum TOCModelRoles {
        TitleRole = Qt::UserRole + 1, //257
        PageRole,                     //258
        ParentIdRole,                 //259
        ExpandedRole,                 //260
        ExpandedKidsRole,             //261
        KidsRole,                     //262
        DepthRole
    };

public:

    Q_INVOKABLE QVariant get(int index) const
    {
        QVariantMap data;
        QHash<int,QByteArray> rn = this->roleNames();
        for(int key : rn.keys())
        {
            QVariant dd = data_alt(index, key);
            data[QString(rn[key])] =dd;
        }

           return  QVariant::fromValue(data);


    }

    void addContent(const TOCItem &content)
    {
        beginInsertRows(QModelIndex(), rowCount(), rowCount());
        m_contents << content;
        endInsertRows();
    }
    int columnCount(const QModelIndex &parent) const override
    {
       return 1;
    }

    Q_INVOKABLE bool setData(int idx, const QVariant &value, int role = Qt::EditRole)
    {
        QVariantMap data;
        TOCItem &content = m_contents[idx];
        if (role == ExpandedKidsRole)
        {
             content.m_expandedkids  = value.toBool();
        }

        else if (role == ExpandedRole)
        {
             content.m_expanded = value.toBool();
        }

        dataChanged( index(idx, 0),  index(idx, 0));
        return  true;
    }

    int rowCount(const QModelIndex & parent = QModelIndex()) const override
    {
        Q_UNUSED(parent)
        return m_contents.count();
    }
    QVariant  data_alt(int index, int role) const
    {

        const TOCItem &content = m_contents[index];
        if (role == Qt::DisplayRole)
        {
             return content.title();
        }
        else if (role == TitleRole)
        {
            return content.title();
        }
        else if (role == PageRole)
        {
            return content.page();
        }

        else if (role == ExpandedKidsRole)
        {
            return content.kidsexpanded();
        }

        else if (role == ExpandedRole)
        {
            return content.expanded();
        }

        else if (role == ParentIdRole)
        {
            return content.parentid();
        }

        else if (role == DepthRole)
        {
            return content.depth();
        }
        else if (role == KidsRole)
        {
            return content.kids();
        }
        else{

        }
        return QVariant();
    }


    QVariant  data(const QModelIndex & index, int role) const override
    {

        if (index.row() < 0 || index.row() >= m_contents.count())
        {
            return QVariant();
        }
        const TOCItem &content = m_contents[index.row()];
        if (role == Qt::DisplayRole)
        {
             return content.title();
        }
        else if (role == TitleRole)
        {
            return content.title();
        }
        else if (role == PageRole)
        {
            return content.page();
        }

        else if (role == ExpandedKidsRole)
        {
            return content.kidsexpanded();
        }

        else if (role == ExpandedRole)
        {
            return content.expanded();
        }

        else if (role == ParentIdRole)
        {
            return content.parentid();
        }

        else if (role == DepthRole)
        {
            return content.depth();
        }
        else if (role == KidsRole)
        {
            return content.kids();
        }
        else{

        }
        return QVariant();
    }

protected:    
    QHash<int, QByteArray> roleNames() const override
    {
        QHash<int, QByteArray> roles;
        roles[ExpandedKidsRole]= "expandedkids";
        roles[ExpandedRole]    = "expanded";
        roles[ParentIdRole]    = "parentid";
        roles[TitleRole   ]    = "title";
        roles[PageRole    ]    = "page";
        roles[KidsRole    ]    = "kids";
        roles[DepthRole   ]    = "depth";
        return roles;
    }
private:
    QList<TOCItem> m_contents;
};

#endif // TOCMODEL_H

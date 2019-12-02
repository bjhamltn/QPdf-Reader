#ifndef TOCITEM_H
#define TOCITEM_H
#include <QList>
#include <QVariant>
class TOCItem
{
public:
    QString m_title;
    int  m_page;
    int  m_depth;
    int  m_kids;
    int  m_parentid;
    bool m_expanded;
    bool m_expandedkids;
public:

    TOCItem(QString title, int page, int depth, int kids,int parentid, bool expanded, bool expandedkids )
        :
          m_title       (title),
          m_page        (page),
          m_depth       (depth),
          m_kids        (kids),
          m_parentid    (parentid),
          m_expanded    (expanded),
          m_expandedkids(expandedkids)
    {
    }

    QString title() const
    {
        return m_title;
    }

    int page() const
    {
        return m_page;
    }

    int depth() const
    {
        return m_depth;
    }

    int kids() const
    {
        return m_kids;
    }

    int parentid() const
    {
        return m_parentid;
    }


    bool expanded() const
    {
        return m_expanded;
    }

    bool kidsexpanded() const
    {
        return m_expandedkids;
    }

};
#endif // TOCITEM_H

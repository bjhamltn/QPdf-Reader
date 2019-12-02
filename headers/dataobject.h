#include <QObject>
#include <QVariant>

class DataObject : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QStringList files READ files WRITE setFiles NOTIFY filesChanged)
    Q_PROPERTY(QString filepath READ filepath WRITE setfilepath NOTIFY filepathChanged)
    Q_PROPERTY(QList<QObject*> filesExtra READ filesExtra WRITE setFilesExtra NOTIFY filesExtraChanged)
    Q_PROPERTY(QVariant filesExtraVar READ filesExtraVar WRITE setFilesExtraVar NOTIFY filesExtraChangedVar)
public:
    DataObject(QObject *parent=nullptr);
    DataObject(const QString &name, QStringList files, QObject *parent=nullptr);
    QString name() const;
    QString filepath() const;
    QString fileDecription() const;
    QStringList files();
    QList<QObject*> filesExtra();
    QVariant filesExtraVar();

    void setName(const QString &name);
    void setfileDecription(const QString &fileDecription);
    void setfilepath(const QString &filepath);
    void setFiles(QStringList files);
    void setFilesExtra(QList<QObject*> files);
    void setFilesExtraVar(QVariant files);
signals:
    void nameChanged();
    void fileDecriptionChanged();
    void filepathChanged();
    void filesChanged();
    void filesExtraChanged();
    void filesExtraChangedVar();


private:
    QString m_name;
    QString m_filepath;
    QString m_fileDecription;
    QStringList m_files;
    QList<QObject*> m_filesExtra;
    QVariant m_filesExtraVar;


public:



};

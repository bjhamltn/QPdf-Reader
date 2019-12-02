#include "dataobject.h"


DataObject::DataObject(QObject *parent): QObject(parent)
{

}
DataObject::DataObject(const QString &name, QStringList files, QObject *parent)
    : QObject(parent), m_name(name), m_files(files)
{
}

QString DataObject::name() const
{
    return m_name;
}

QString DataObject::filepath() const
{
    return m_filepath;
}

QString DataObject::fileDecription() const
{
    return m_fileDecription;
}

QStringList DataObject::files()
{
    return m_files;
}

void DataObject::setName(const QString &name)
{
    if (name != m_name) {
        m_name = name;
        emit nameChanged();
    }
}

void DataObject::setfileDecription(const QString &fileDecription)
{
    if (fileDecription != m_fileDecription) {
        m_fileDecription = fileDecription;
        emit fileDecriptionChanged();
    }
}

void DataObject::setfilepath(const QString &filepath)
{
    if (filepath != m_filepath) {
        m_filepath = filepath;
        emit filepathChanged();
    }
}

void DataObject::setFiles(QStringList files)
{
    if (files != m_files) {
        m_files = files;
        emit filesChanged();
    }
}

QList<QObject*> DataObject::filesExtra()
{

    return m_filesExtra;
}

void DataObject::setFilesExtra(QList<QObject*> files)
{
    if (files != m_filesExtra) {
        m_filesExtra = files;
        m_filesExtraVar = QVariant::fromValue(m_filesExtra);
        emit filesExtraChanged();
        emit filesExtraChangedVar();
    }
}

QVariant DataObject::filesExtraVar()
{

    return m_filesExtraVar;
}

void DataObject::setFilesExtraVar(QVariant files)
{
    if (files != m_filesExtraVar) {
        m_filesExtraVar = files;
        emit filesExtraChangedVar();
    }
}

#include <viewercontroller.h>
#include <QQmlProperty>
#include <QXmlStreamReader>
#include <QScreen>

class FleetDocs{
    QString Fleet;
    QVariantMap docs;
};

enum EfbDocNodes{
    DocAcronym =0,
    Description,
    NamingConvention,
    LsapIdentifier,
    InProduction,
    ApplicableFleets
};

int tokenbyName(const QString nodeName){
    QStringList nodes = QStringList();
    nodes << "DocAcronym" << "Description" << "NamingConvention"
          << "LsapIdentifier" << "InProduction"  << "ApplicableFleets";
    return nodes.indexOf(nodeName);
}

QMap<QString, QVariantList>  readEFB_dmd(){
    QMap<QString, QVariantList> doclib;
    doclib.clear();
    QDirIterator it("C:\\EFB\\ReadOnlyData\\Documents", QStringList() << "*.PublicationManifest", QDir::NoFilter, QDirIterator::Subdirectories);
    while (it.hasNext()) {
        QString ff(it.next());
        QFile* file = new QFile(ff);
        file->open(QIODevice::ReadOnly);
        QXmlStreamReader info(file);
        QFileInfo fileInfo(ff);
        QString contentDir = fileInfo.absolutePath();
        QVariantMap docData;
        QStringList fleetNames;
        docData.insert("contentDir",contentDir);
        while (!info.atEnd() && !info.hasError())
        {
            info.readNext();
            if (info.isStartElement())
            {
                QString elementName = info.name().toString();


                if( elementName == "DocVersions")
                {
                    break;
                }


                switch (tokenbyName(elementName))
                {
                case EfbDocNodes::DocAcronym:
                    docData.insert(elementName,info.readElementText());
                    break;
                case EfbDocNodes::Description:
                    docData.insert(elementName,info.readElementText());
                    break;

                case EfbDocNodes::NamingConvention:
                    docData.insert(elementName,info.readElementText());
                    break;

                case EfbDocNodes::LsapIdentifier:
                    docData.insert(elementName,info.readElementText());
                    break;

                case EfbDocNodes::InProduction:
                    docData.insert(elementName,info.readElementText());
                    break;
                case EfbDocNodes::ApplicableFleets:
                    QString fleets = info.readElementText(QXmlStreamReader::IncludeChildElements);
                    fleetNames =fleets.split("\n",QString::SplitBehavior::SkipEmptyParts);
                    break;
                }
            }

        }

        for (QString flt : fleetNames) {
            QString fleet = flt.trimmed();
            if(doclib.keys().contains(fleet) == false)
            {
                doclib.insert(fleet, QVariantList());
            }
            bool skip = false;
            for(QVariant d: doclib[fleet] )
            {

                if( d == QVariant::fromValue(docData))
                {
                    skip = true;
                    break;
                }
            }
            if(!skip){
                doclib[fleet].append(docData);
            }
        }
        file->close();
        delete file;
    }


    return doclib;
}

bool variantLessThan( QVariant v1,  QVariant v2)
 {
    QMap<QString, QVariant> vv1 = v1.toMap();
    QMap<QString, QVariant> vv2 = v2.toMap();
     return vv1["DocAcronym"].toString() < vv2["DocAcronym"].toString();
 }

QList<QObject*> loadFolders(){
    QStringList d;
    QList<QObject*> folders;
    QDir *dd = new QDir("C:\\EFB\\ReadOnlyData\\Documents");
    QFileInfoList fleets(dd->entryInfoList(QDir::Dirs));
    QListIterator<QFileInfo> it (fleets);
    while (it.hasNext()) {
        QFileInfo fInfo = it.next();
        if(fInfo.fileName()=="." || fInfo.fileName()=="..")
        {
            continue;
        }

        QDir manuls(fInfo.filePath());
        QList<QObject*> fileDetails;
        QStringList manualsFilesDir = manuls.entryList(QDir::Dirs);
        QStringList d;
        for(int i=0; i<manualsFilesDir.length();i++){
            if(manualsFilesDir[i] != "." && manualsFilesDir[i] != "..")
            {
                DataObject *dd = new DataObject();
                QDir subDir(manuls.path()+"\\"+manualsFilesDir[i]);
                subDir.setNameFilters(QStringList()<<"*.pdf");
                QStringList pdfFiles = subDir.entryList();
                if(pdfFiles.length() > 0){
                    QString filePath = manuls.path()+"/"+manualsFilesDir[i]+"/"+pdfFiles[0];
                    dd->setName(QFileInfo(manualsFilesDir[i]).fileName());
                    dd->setfilepath(filePath);
                    d.append(QFileInfo(manualsFilesDir[i]).fileName());
                    fileDetails.append(dd);
                }
            }
        }
        DataObject *fleetData = new DataObject();
        fleetData->setName(fInfo.fileName());
        fleetData->setFiles(d);
        fleetData->setFilesExtra(fileDetails);
        folders.append(fleetData);
    }
    return folders;
}

int main(int argc, char *argv[])
{

    QString configuredFleet;
    QFile data("C:\\EFB\\ReadOnlyData\\FXEFBConfig\\fleet.txt");
    if (data.open(QFile::ReadOnly))
    {
        QTextStream in(&data);
        configuredFleet = in.readAll();
        configuredFleet = configuredFleet.trimmed();
    }



   QMap<QString, QVariantList> docLib = readEFB_dmd();
   QVariantList docLibModel;
   QVariantList configuredFleetDocs;
   for(QString fleetName :docLib.keys())
   {
       QVariantMap fleetData;     
       fleetData.insert("fleet", fleetName =="" ? "ALL" : fleetName);
       QVariantList documentsList =  docLib[fleetName];
       std::sort(documentsList.begin(), documentsList.end(), variantLessThan);
       fleetData.insert("documents",documentsList);
       docLibModel.append(fleetData);

       if(fleetName.contains( configuredFleet ))
       {
           configuredFleetDocs = docLib[fleetName];
       }
   }


    ViewerController appController;
    //QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);


    appController.engine = new QQmlApplicationEngine();
    const QUrl url(QStringLiteral("qrc:/main.qml"));

    appController.engine->rootContext()->setContextProperty("appController", &appController);

    QObject::connect(appController.engine,&QQmlApplicationEngine::objectCreated,&app, [url](QObject *obj, const QUrl &objUrl){
        if (!obj && url == objUrl){QCoreApplication::exit(-1);}}, Qt::QueuedConnection);



    appController.pdfProvider  = new PdfProvider(QQuickImageProvider::Pixmap);

    appController.pdfProvider->devicePixelRatio = static_cast<float>( app.primaryScreen()->devicePixelRatio() ) > 1 ? 1 :1;
    appController.engine->addImageProvider(QLatin1String("pdfpage"), appController.pdfProvider);

    appController.engine->rootContext()->setContextProperty("docLibModel", QVariant::fromValue(docLibModel));

    appController.engine->rootContext()->setContextProperty("sourceinfo", QVariant::fromValue(appController.pdfProvider->getpageNumbers()));
    appController.engine->rootContext()->setContextProperty("pageCnt", QVariant::fromValue(0));
    appController.engine->rootContext()->setContextProperty("configuredFleet", QVariant::fromValue(configuredFleet));
    appController.engine->rootContext()->setContextProperty("configuredFleetDocs", QVariant::fromValue(configuredFleetDocs));



    appController.engine->load(url);

    QObject *rootObject = appController.engine->rootObjects().first();
    QObject *qmlObject = rootObject->findChild<QObject*>("swipeView");

    QObject::connect(rootObject, SIGNAL(getPdfPageInfo(QVariant)), &appController, SLOT(getPageInfo(QVariant)));

    QObject::connect(qmlObject, SIGNAL(pdfChanged(QString,QVariant,QVariant,QVariant)), &appController, SLOT(loadPdf(QString,QVariant,QVariant,QVariant)));
    QObject::connect(qmlObject, SIGNAL(changeDefaultSize(QVariant,QVariant,QVariant)), &appController, SLOT(changeDefaultSize(QVariant,QVariant,QVariant)));
    QObject::connect(qmlObject, SIGNAL(setNegMode(QVariant)), &appController, SLOT(setNegMode(QVariant)));
    QObject::connect(rootObject,SIGNAL(searhPDF(QString)), &appController, SLOT(searhPDF(QString)));
    QObject::connect(rootObject,SIGNAL(enableCropMode(QVariant)), &appController, SLOT(enableCropMode(QVariant)));
    //QObject::connect(rootObject,SIGNAL(markText(QString)), &appController, SLOT(markText(QString)));
    return app.exec();
}

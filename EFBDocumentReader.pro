QT += quick core quickcontrols2 concurrent
QT -= gui
CONFIG += c++11
RC_ICONS = logo.ico
HEADERS += \
    headers/tocitem.h \
    headers/tocmodel.h  \
    headers/dataobject.h \
    headers/pdfprovider.h \
    headers/textworker.h \
    headers/treeitem.h \
    headers/treemodel.h \
    headers/viewercontroller.h

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        dataobject.cpp \
        main.cpp \
        pdfprovider.cpp \
        textworker.cpp \
        tocmodel.cpp \
        treeitem.cpp \
        treemodel.cpp \
        viewercontroller.cpp

RESOURCES += qml.qrc






# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

INCLUDEPATH += $$PWD/headers
INCLUDEPATH += $$PWD/dev/include
INCLUDEPATH += $$PWD/dev/include/mupdf
DEPENDPATH  += $$PWD/dev/include/mupdf/



############################################################################################################
contains(QT_ARCH, i386){
    DESTDIR = $$OUT_PWD/debug

    message($$QMAKE_TARGET.arch)
    win32:CONFIG(release, debug|release): LIBS += -L$$PWD/dev/include/mupdf/x86/ -llibmupdf
    else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/dev/include/mupdf/x86/ -llibmupdf

    win32:CONFIG(release, debug|release): LIBS += -L$$PWD/dev/include/mupdf/x86/ -llibresources
    else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/dev/include/mupdf/x86/ -llibresources

    win32:CONFIG(release, debug|release): LIBS += -L$$PWD/dev/include/mupdf/x86/ -llibthirdparty
    else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/dev/include/mupdf/x86/ -llibthirdparty

    win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/dev/include/mupdf/x86/liblibmupdf.a
    else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/dev/include/mupdf/x86/liblibmupdfd.a
    else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/dev/include/mupdf/x86/libmupdf.lib
    else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/dev/include/mupdf/x86/libmupdf.lib


    win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/dev/include/mupdf/x86/liblibresources.a
    else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/dev/include/mupdf/x86/liblibresourcesd.a
    else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/dev/include/mupdf/x86/libresources.lib
    else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/dev/include/mupdf/x86/libresources.lib


    win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/dev/include/mupdf/x86/liblibthirdparty.a
    else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/dev/include/mupdf/x86/liblibthirdparty.a
    else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/dev/include/mupdf/x86/libthirdparty.lib
    else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/dev/include/mupdf/x86/libthirdparty.lib


}
else{
    DESTDIR = $$OUT_PWD/Reader
    CONFIG += file_copies
    message($$DESTDIR)
    install_it.path = $${DESTDIR}
    install_it.files += EFBDocumentReader.VisualElementsManifest.xml

    COPIES  += install_it

    install_visualElementFolder.path = $${DESTDIR}\VisualElements
    install_visualElementFolder.files += $$files(VisualElements\MediumIconEFBDocumentReader.png) \
                        $$files(VisualElements\SmallIconEFBDocumentReader.png) \
                        $$files(VisualElements\MediumIconEFBDocumentReader_Metadata.xml) \
                        $$files(VisualElements\SmallIconEFBDocumentReader_Metadata.xml)
    COPIES += install_visualElementFolder


    message($$QMAKE_TARGET.arch)
    win32:CONFIG(release, debug|release): LIBS += -L$$PWD/dev/include/mupdf/x64/ -llibmupdf
    else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/dev/include/mupdf/x64_d/ -llibmupdf

    win32:CONFIG(release, debug|release): LIBS += -L$$PWD/dev/include/mupdf/x64/ -llibresources
    else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/dev/include/mupdf/x64_d/ -llibresources

    win32:CONFIG(release, debug|release): LIBS += -L$$PWD/dev/include/mupdf/x64/ -llibthirdparty
    else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/dev/include/mupdf/x64_d/ -llibthirdparty



    win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/dev/include/mupdf/x64/liblibmupdf.a
    else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/dev/include/mupdf/x64/liblibmupdfd.a
    else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/dev/include/mupdf/x64/libmupdf.lib
    else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/dev/include/mupdf/x64_d/libmupdf.lib


    win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/dev/include/mupdf/x64/liblibresources.a
    else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/dev/include/mupdf/x64/liblibresourcesd.a
    else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/dev/include/mupdf/x64/libresources.lib
    else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/dev/include/mupdf/x64_d/libresources.lib


    win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/dev/include/mupdf/x64/liblibthirdparty.a
    else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/dev/include/mupdf/x64/liblibthirdparty.a
    else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/dev/include/mupdf/x64/libthirdparty.lib
    else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/dev/include/mupdf/x64_d/libthirdparty.lib


}






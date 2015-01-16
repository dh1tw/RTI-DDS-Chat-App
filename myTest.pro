TEMPLATE = app

QT += qml quick widgets

SOURCES += main.cpp \
    mycom.cpp \
    mylistener.cpp \
    mything.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)


QMAKE_CXXFLAGS += -DRTI_UNIX
QMAKE_CXXFLAGS += -DRTI_LINUX
QMAKE_CXXFLAGS += -DRTI_64BIT
QMAKE_CXXFLAGS += -m64

LIBS += -L$$PWD/../rti/ndds.5.1.0/lib/x64Linux3.xgcc4.6.3/ -lnddscppz
LIBS += -L$$PWD/../rti/ndds.5.1.0/lib/x64Linux3.xgcc4.6.3/ -lnddscz
LIBS += -L$$PWD/../rti/ndds.5.1.0/lib/x64Linux3.xgcc4.6.3/ -lnddscorez
LIBS += -ldl
LIBS += -lnsl
LIBS += -lm
LIBS += -lpthread
LIBS += -lrt


INCLUDEPATH += $$PWD/../rti/ndds.5.1.0/include
DEPENDPATH += $$PWD/../rti/ndds.5.1.0/include
INCLUDEPATH += $$PWD/../rti/ndds.5.1.0/include/ndds
DEPENDPATH += $$PWD/../rti/ndds.5.1.0/include/ndds

HEADERS += \
    mycom.h \
    mylistener.h \
    mything.h



#ifndef COMMSHANDLER_H
#define COMMSHANDLER_H

#include <QObject>
#include <iostream>
//#include "ndds/ndds_cpp.h"
#include <commsobj.h>
#include <string>
#include <QString>

class CommsHandler : public QObject
{

    Q_OBJECT

    Q_PROPERTY(QString dataAccess WRITE writeData NOTIFY newRcvdDataAvailable)

public:
    CommsHandler();
    ~CommsHandler();

    int setupCommsHandler();
    QString readDDS();

    CommsObj *commsObj;
    CommsListener *listener;

public slots:
    void writeData(QString data);
    void readListenerData(QString data);

signals:
    void newRcvdDataAvailable(QString data);
    void newSendDataAvailable(QString data);
};


#endif // CommsHandler_H

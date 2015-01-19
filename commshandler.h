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

    Q_PROPERTY(QString dataAccess WRITE writeData READ readData NOTIFY newRcvdDataAvailable)

public:
    CommsHandler();
    ~CommsHandler();

    QString readData();

public slots:
    void writeData(QString data);
    void readListenerData(QString data);

signals:
    void newRcvdDataAvailable(QString data);
    void newSendDataAvailable(QString data);

private:
    CommsObj           * commsObj;
    CommsListener      * listener;
    int                  setupCommsHandler();
    QString              RcvBuffer;

};


#endif // CommsHandler_H

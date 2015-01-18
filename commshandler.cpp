#include "commshandler.h"
#include <QDebug>
#include <QString>

CommsHandler::CommsHandler()
{
    setupCommsHandler();
}

CommsHandler::~CommsHandler()
{

}

int CommsHandler::setupCommsHandler()
{
    CommsObj *commsObj = new CommsObj(this);
    CommsListener *listener = new CommsListener(this);

    int success = commsObj->setupCommsObj(listener);
    if (success != 0)
    {
        qDebug() << "Couldn't setup DDS Objects";
        return 1;
    }
    connect(listener, SIGNAL(newData(QString)), this, SLOT(readListenerData(QString)));
}

void CommsHandler::writeData(QString data){
    emit newSendDataAvailable(data);
}

void CommsHandler::readListenerData(QString data){
    qDebug() << this << "recieved: " << data;
    emit newRcvdDataAvailable(data);
}

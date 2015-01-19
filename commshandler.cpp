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
    listener = new CommsListener(this);
    commsObj = new CommsObj(this, listener);

    connect(listener, SIGNAL(newData(QString)), this, SLOT(readListenerData(QString)), Qt::QueuedConnection);
}

QString CommsHandler::readData(){
    return rcvBuffer;
}

void CommsHandler::writeData(QString data){
    emit newSendDataAvailable(data);
}

void CommsHandler::readListenerData(QString data){
    qDebug() << this << "recieved: " << data;
    rcvBuffer = data;
    emit newRcvdDataAvailable(data);
}

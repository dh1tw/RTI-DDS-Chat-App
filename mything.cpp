#include "mything.h"
#include <QDebug>
#include <QString>

MyThing::MyThing()
{
        MyCom mycom;
}

MyThing::~MyThing()
{

}

bool MyThing::getInstance(){
//    return true;
}


void MyThing::writeDDS(QString data){
    QString toSend = data;
    MyThing::mycom.string_writer->write(toSend.toUtf8().constData(), DDS_HANDLE_NIL);
    qDebug() << data;
    emit ddsNewMsg();
}

QString MyThing::readDDS(){

}

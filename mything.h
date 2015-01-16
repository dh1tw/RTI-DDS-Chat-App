#ifndef MYTHING_H
#define MYTHING_H

#include <QObject>
#include <iostream>
//#include "ndds/ndds_cpp.h"
#include <mycom.h>
#include <string>
#include <QString>

class MyThing : public QObject
{

    Q_OBJECT

    Q_PROPERTY(QString readDDS READ readDDS WRITE writeDDS NOTIFY ddsNewMsg)

public:
    MyThing();
    ~MyThing();

    MyCom mycom;

    QString readDDS();
    bool getInstance();

public slots:
    void writeDDS(QString data);

signals:
    void ddsNewMsg();
};

#endif // MYTHING_H

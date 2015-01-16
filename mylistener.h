#ifndef MYLISTENER_H
#define MYLISTENER_H
#include <ndds/ndds_cpp.h>
#include <QObject>

#define MAX_STRING_SIZE         1024


class MyListener : public QObject, public DDSDataReaderListener
{

    Q_OBJECT
    Q_PROPERTY(QString rcvData READ rcvData WRITE writeMe NOTIFY gotNewData)


public:
    void on_data_available(DDSDataReader *reader);
    QString rcvData();
    QString rxQueue;

public slots:
    void writeMe(QString data);

signals:
    void gotNewData();

};

#endif // MYLISTENER_H

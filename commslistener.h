#ifndef COMMSLISTENER_H
#define COMMSLISTENER_H
#include <ndds/ndds_cpp.h>
#include <QObject>
#include <QString>


#define MAX_STRING_SIZE         1024

class CommsListener : public QObject, public DDSDataReaderListener
{
    Q_OBJECT

public:
    CommsListener(QObject *parent);

    void on_data_available(DDSDataReader *reader);
    QString rxQueue;

signals:
    void newData(QString data);

};

#endif // COMMSLISTENER_H

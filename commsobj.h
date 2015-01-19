#ifndef COMMSOBJ_H
#define COMMSOBJ_H

#include <string>
#include <ndds/ndds_cpp.h>
#include <commslistener.h>
#include <QString>
#include <QObject>

using namespace std;

#define MAX_STRING_SIZE         1024

class CommsObj : public QObject
{
    Q_OBJECT

public:
    CommsObj(QObject *parent, CommsListener *listener);
    ~CommsObj();

    DDSDomainParticipant *  participant;
    DDSTopic *              topic;
    DDSDataWriter *         data_writer;
    DDSDataReader *         data_reader;
    DDSStringDataWriter *   string_writer;
    DDS_ReturnCode_t        retcode;
    CommsListener *         listener;
    char                    sample[MAX_STRING_SIZE];
    int                     main_result;

public slots:
    void sendData(QString data);

private:
    int setupCommsObj();
};


#endif // COMMSOBJ_H

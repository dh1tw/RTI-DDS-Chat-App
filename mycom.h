#ifndef MYCOM_H
#define MYCOM_H

#include <string>
#include <ndds/ndds_cpp.h>
#include <mylistener.h>
#include <QString>
#include <QObject>

using namespace std;

#define MAX_STRING_SIZE         1024

class MyCom : public QObject
{
public:
    MyCom();
    ~MyCom();

    int setupInstance();

    void on_data_available(DDSDataReader *reader);

    QString                 rxQueue;

    DDSDomainParticipant *  participant;
    DDSTopic *              topic;
    DDSDataWriter *         data_writer;
    DDSDataReader *         data_reader;
    DDSStringDataWriter *   string_writer;
    DDS_ReturnCode_t        retcode;
    MyListener              * listener;
    char                    sample[MAX_STRING_SIZE];
    int                     main_result;
};

#endif // MYCOM_H

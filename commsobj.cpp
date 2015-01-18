#include "commsobj.h"
#include <QDebug>


CommsObj::CommsObj(QObject *parent) : QObject(parent)
{
    DDSDomainParticipant *  participant = NULL;
    DDSTopic *              topic = NULL;
    DDSDataWriter *         data_writer = NULL;
    DDSDataReader *         data_reader = NULL;
    DDSStringDataWriter *   string_writer = NULL;
    char                    sample[MAX_STRING_SIZE];
    int                     main_result = 1; /* error by default */
}

CommsObj::~CommsObj()
{
    if (CommsObj::participant != NULL) {
        retcode = participant->delete_contained_entities();
        if (retcode != DDS_RETCODE_OK) {
            qDebug() << "Deletion failed";
        }
        retcode = DDSDomainParticipantFactory::get_instance()->
                delete_participant(participant);
        if (retcode != DDS_RETCODE_OK) {
            qDebug() << "Deletion failed.";
        }
    }
}

int CommsObj::setupCommsObj(CommsListener *myListener){

    listener = myListener;

    CommsObj::participant = DDSDomainParticipantFactory::get_instance()->
            create_participant(
                0,                              /* Domain ID */
                DDS_PARTICIPANT_QOS_DEFAULT,    /* QoS */
                NULL,                           /* Listener */
                DDS_STATUS_MASK_NONE);
    if (participant == NULL) {
        qDebug() << "Unable to create domain participant.";
        return 1;
    }

    /* Create the topic "Hello, World" for the String type */
    CommsObj::topic = participant->create_topic(
                "Hello, World",                          /* Topic name*/
                DDSStringTypeSupport::get_type_name(), /* Type name */
                DDS_TOPIC_QOS_DEFAULT,                 /* Topic QoS */
                NULL,                                  /* Listener  */
                DDS_STATUS_MASK_NONE);
    if (topic == NULL) {
        qDebug() << "Unable to create topic." ;
        return 1;
    }

    /* Create the data writer using the default publisher */
    CommsObj::data_writer = participant->create_datawriter(
                topic,
                DDS_DATAWRITER_QOS_DEFAULT,     /* QoS */
                NULL,                           /* Listener */
                DDS_STATUS_MASK_NONE);
    if (data_writer == NULL) {
        qDebug() << "Unable to create data writer.";
        return 1;
    }

    CommsObj::data_reader = participant->create_datareader(
                topic,
                DDS_DATAREADER_QOS_DEFAULT,    /* QoS */
                listener,                      /* Listener */
                DDS_DATA_AVAILABLE_STATUS);
    if (data_reader == NULL) {
        qDebug() << "Unable to create data reader.";
        return 1;
    }

    CommsObj::string_writer = DDSStringDataWriter::narrow(data_writer);
    if (string_writer == NULL) {
        /* In this specific case, this will never fail */
        qDebug() << "DDS_StringDataWriter_narrow failed.";
    }
    connect(parent(), SIGNAL(newSendDataAvailable(QString)), this, SLOT(sendData(QString)));

    return 0;
}

void CommsObj::sendData(QString data){
    string_writer->write(data.toUtf8().constData(), DDS_HANDLE_NIL);
    qDebug() << this << "sent: " << data;
}

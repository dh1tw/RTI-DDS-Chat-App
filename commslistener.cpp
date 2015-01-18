#include "commslistener.h"
#include <QDebug>
#include <QString>
#include <QTimer>

DDS_Boolean shutdown_flag = DDS_BOOLEAN_FALSE;

CommsListener::CommsListener(QObject *parent) : QObject(parent){
    qDebug() << "Listener build";
}


void CommsListener::on_data_available(DDSDataReader *reader) {
    DDSStringDataReader * string_reader = NULL;
    char                  sample[MAX_STRING_SIZE];
    DDS_SampleInfo        info;
    DDS_ReturnCode_t      retcode;

    /* Perform a safe type-cast from a generic data reader into a
     * specific data reader for the type "DDS::String"
     */
    string_reader = DDSStringDataReader::narrow(reader);
    if (string_reader == NULL) {
        /* In this specific case, this will never fail */
        qDebug() << "DDSStringDataReader::narrow failed.";
        return;
    }

    /* Loop until there are messages available in the queue */
    char *ptr_sample = &sample[0];
    for(;;) {
        retcode = string_reader->take_next_sample(
                            ptr_sample,
                            info);
        if (retcode == DDS_RETCODE_NO_DATA) {
            /* No more samples */
            break;
        } else if (retcode != DDS_RETCODE_OK) {
            qDebug() << "Unable to take data from data reader, error " << retcode;
            return;
        }
        if (info.valid_data) {
            // Valid (this isn't just a lifecycle sample): print it

            emit newData(sample);

            if(strlen(sample) == 0){
                shutdown_flag = DDS_BOOLEAN_TRUE;
            }

        }
    }
}

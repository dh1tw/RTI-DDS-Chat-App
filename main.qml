import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2
import dh1tw.shack 1.0

ApplicationWindow {
    title: qsTr("My DDS Chat")
    minimumWidth: 300
    minimumHeight: 500
    maximumWidth: 300
    maximumHeight: 500
    visible: true

    menuBar: MenuBar {
        Menu {
            title: qsTr("&File")
            MenuItem {
                text: qsTr("&Open")
                //                onTriggered: messageDialog.show(qsTr("Open action triggered"));
            }
            MenuItem {
                text: qsTr("E&xit")
                onTriggered: Qt.quit();
            }
        }
    }

    MyThing{
        id: msgTx
        onDdsNewMsg: console.log("event 1")
    }

    MyListener{
        id: rxMsg
        onGotNewData: console.log("event 2")
    }

    Connections { target: MyListener; onGotNewData: console.log("Signal happened"); }

    Column {
        anchors.fill: parent
        anchors.margins: 3
        width: parent.width
        height: parent.height
        spacing: 3

        TextArea{
            id: rcvMsgs
            height: 0.88 * parent.height
            text: "hello"
            readOnly: true
            width: parent.width
        }


        TextField {
            id: sendMsg
            text: ""
            width: parent.width
            onAccepted: {
//                if (text){
//                    tobi.writeDDS(sendMsg.text);
//                    rcvMsgs.append("me: " + sendMsg.text);
//                    sendMsg.text = "";
//                }
            }
        }

        Button{
            id: sendMsgBtn
            text: "Send"
            width: parent.width
            onClicked: {
                if (sendMsg.text){
                    mything.writeDDS(sendMsg.text);
                    rcvMsgs.append("me: " + sendMsg.text);
                    sendMsg.text = "";
                }
            }
        }
    }

}

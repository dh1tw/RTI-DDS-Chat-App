import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2
import org.myChat 1.0

ApplicationWindow {
    id: root
    title: qsTr("My DDS Chat")
    minimumWidth: 300
    minimumHeight: 530
    maximumWidth: 300
    maximumHeight: 530
    visible: true

    property string myName : "Unknown"
    property variant mySettingsWindow

    menuBar: MenuBar {
        Menu {
            title: qsTr("&File")
            MenuItem {
                text: qsTr("E&xit")
                onTriggered: Qt.quit();
            }
        }
    }


   // Connections { target: rxMsg; onGotNewData: console.log("Signal happened"); }

    TabView{
        id: myTabs
        anchors.fill: parent
        Tab{
            title: "Chat"
            Column {
                anchors.fill: parent
                anchors.margins: 3
                width: parent.width
                height: parent.height
                spacing: 3

                TextArea{
                    id: rcvMsgs
                    height: 0.88 * parent.height
                    readOnly: true
                    width: parent.width
                }


                TextField {
                    id: sendMsg
                    text: ""
                    width: parent.width
                    onAccepted: {
                        if (text){
                            msgHandler.writeData(root.myName + ": " + text);
                            sendMsg.text = "";
                        }
                    }
                }

                Button{
                    id: sendMsgBtn
                    text: "Send"
                    width: parent.width
                    onClicked: {
                        if (sendMsg.text){
                            msgHandler.writeData(root.myName + ": " + sendMsg.text);
                            sendMsg.text = "";
                        }
                    }
                }

                //handle Messages comming via C++
                CommsHandler{
                    id: msgHandler
                    onNewRcvdDataAvailable: rcvMsgs.append(data);
                }

            }
        }
        Tab {
            title: "Settings"
            Column {
                anchors.fill: parent
                anchors.margins: 3
                width: parent.width
                height: parent.height
                spacing: 3

                TextField {
                    id: myName
                    text: root.myName
                    width: parent.width
                    onAccepted: {
                        if (text){
                            root.myName = text;
                            messageDialog.show(qsTr("Name successfully changed"))
                        }
                    }
                }

                Button{
                    id: setName
                    text: "Set Chat Name"
                    width: parent.width
                    onClicked: {
                        if (myName.text){
                            root.myName = myName.text
                            messageDialog.show(qsTr("Name successfully changed"))
                        }
                    }
                }
                MessageDialog {
                    id: messageDialog
                    title: qsTr("Successful")

                    function show(caption) {
                        messageDialog.text = caption;
                        messageDialog.open();
                    }
                }
            }
        }
    }
}

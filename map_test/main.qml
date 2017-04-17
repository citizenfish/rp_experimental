import QtQuick 2.3
import QtQuick.Controls 1.2
import QtLocation 5.7
ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Daves Mapping Application")

    menuBar: MenuBar {
        Menu {
            title: qsTr("File")
            MenuItem {
                text: qsTr("&Open")
                onTriggered: console.log("Open action triggered");
            }
            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit();
            }
        }
    }

    Text {
        text: qsTr("Hello World")
        anchors.centerIn: parent
    }
}

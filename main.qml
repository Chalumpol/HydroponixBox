import QtQuick 2.5
import QtQuick.Window 2.2

Window {
    visible: true
    Item {
        width: 150
        height:150
        Rectangle {
            width: 150
            height: 150
            color: "black"
            border.color: "black"
            border.width: 2
        }

        Column{
            anchors.centerIn: parent
            Text {
                id: time
                //                text: "Test"
                color: "white"
                font {
                    family: "Comic Sans MS"
                    pixelSize: 36
                }
                anchors.horizontalCenter: parent.horizontalCenter
            }
            Text {
                id: dates
                //                text: "Test2"
                color: "white"
                font {
                    family: "Comic Sans MS"
                    pixelSize: 22
                }
                anchors.horizontalCenter: parent.horizontalCenter
            }
        }
        Timer{
            interval: 1000
            running: true
            repeat: true

            onTriggered: {
                var date = new Date()
                time.text = date.toLocaleTimeString(Qt.locale("en_US"),"hh:mm:ss")
                dates.text = date.toLocaleDateString(Qt.locale("en_US"),"ddd MMM yyyy")
            }
        }
    }
}

import QtQuick 2.0
import QtGraphicalEffects 1.0

Item {

    Timer {
        interval: 1000
        running: true
        repeat: true
        onTriggered: timeChanged()
    }

    function timeChanged() {
        var date = new Date()
        hourmin.text = Qt.formatDateTime(date, "hh:mm")
        seconds.text = Qt.formatDateTime(date, "ss")
        day.text = Qt.formatDate(date, "dddd dd.MM.yyyy")
    }
    Rectangle {
        id: clockHolder
        color: mainWindow.color

        Text {
            id: hourmin
            text: qsTr("--:--")
            anchors.left: clockHolder.left
            anchors.verticalCenter: parent.verticalCenter
            font.pixelSize: 10
            font.weight: Font.Medium
            //color: "white"
        }

        Text {
            id: seconds
            text: qsTr("--")
            anchors.left: hourmin.right
            //anchors.leftMargin: 1
            anchors.verticalCenter: parent.verticalCenter; anchors.verticalCenterOffset: -4
            font.pixelSize: 5
            font.weight: Font.Thin
        }

        Text {
            id: day
            text: qsTr("---")
            anchors.left: clockHolder.left
            anchors.leftMargin: 2
            anchors.bottom: hourmin.bottom
            anchors.bottomMargin: -3
            font.pixelSize: 3
            font.weight: Font.Thin
            font.letterSpacing: -0.2
        }
    }
}

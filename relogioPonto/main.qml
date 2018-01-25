import QtQuick 2.9
import QtQuick.Window 2.3
import QtQuick.Controls 2.2
import QtQuick.Controls.Material 2.2
import QtGraphicalEffects 1.0
import QtQuick.Layouts 1.3

import BackEnd 1.0

ApplicationWindow {
    id: mainWindow
    visible: true
    width: 800
    height: 100
    title: qsTr("PiClock")
    color: "#009ed2"
    //color: "white"
    Material.theme: Material.Light
    Material.accent: Material.LightBlue

    BackEnd {
        id: backend
//        onIdtextChanged: {
//            console.log("received ID: " + id)
//            myID.text = id
//            scaleAnimator.running = true
//            userInfoHolder.visible = true
//            var date = new Date()
//            time.text = Qt.formatDateTime(date, "hh:mm:ss")
//        }
        onEmployeePhotoChanged: {
            console.log("received Photo: " + photo)
            arrows.visible = false
            txtSwipe.visible = false
            scaleAnimatorIn.running = true
            var date = new Date()
            time.text = Qt.formatDateTime(date, "hh:mm:ss")
            imgEmployeePhoto.source = Qt.resolvedUrl(photo)
        }
        onEmployeeNameChanged: {
            console.log("received Name:" + name)
            employeeName.text = name
        }
        onEmployeeIDChanged: {
            if(id != "") {
                console.log("received tagID: " + id)
                tagID.text = "TagID: " + id
            } else {
                scaleAnimatorOut.running = true
//                arrows.visible = true
//                txtSwipe.visible = true
            }
        }
        onTimeIndexChanged: {
            console.log("TIME INDEX CHANGED: " + timeIndex)
            switch(timeIndex) {
            case 0:
                clockInCircle.color = "#009ed2"
                lunchInCircle.color = "#bfbfbf"
                lunchOutCircle.color = "#bfbfbf"
                clockOutCircle.color = "#bfbfbf"
                break
            case 1:
                clockInCircle.color = "#009ed2"
                lunchInCircle.color = "#009ed2"
                lunchOutCircle.color = "#bfbfbf"
                clockOutCircle.color = "#bfbfbf"
                break
            case 2:
                clockInCircle.color = "#009ed2"
                lunchInCircle.color = "#009ed2"
                lunchOutCircle.color = "#009ed2"
                clockOutCircle.color = "#bfbfbf"
                break
            case 3:
                clockInCircle.color = "#009ed2"
                lunchInCircle.color = "#009ed2"
                lunchOutCircle.color = "#009ed2"
                clockOutCircle.color = "#009ed2"
                break
            case 4:
                clockInCircle.color = "#bfbfbf"
                lunchInCircle.color = "#bfbfbf"
                lunchOutCircle.color = "#bfbfbf"
                clockOutCircle.color = "#bfbfbf"
                break
            }
        }
        onLunchLockedChanged: {
            imgEmployeePhotoLock.visible = lock
        }
    }

//    Text {
//        id: myID
//        text: qsTr("text")
//        anchors.centerIn: parent
//        font.pixelSize: 50
//    }

    Image {
        id: logo
        source: "resources/logo-ff/ff-logo.png"
        width: 40; height: 40
        x: 15; y: 425
        MouseArea {
            id: logoMouseArea
            anchors.fill: parent
            onClicked: {
                txtPiClock.visible = !txtPiClock.visible
                devBy.visible = !devBy.visible
                devGioName.visible = !devGioName.visible
            }
        }
    }

    Text {
        id: txtPiClock
        text: qsTr("PiClock")
        anchors.verticalCenter: logo.verticalCenter
        anchors.left: logo.right; anchors.leftMargin: 10
        font.pixelSize: 30
        font.weight: Font.Thin
        visible: true
    }
    Text {
        id: devBy
        text: qsTr("Developed By")
        anchors.top: logo.top
        anchors.left: logo.right; anchors.leftMargin: 10
        font.pixelSize: 15
        font.weight: Font.Thin
        visible: false
    }
    Text {
        id: devGioName
        text: qsTr("Giovanni Bauermeister")
        anchors.bottom: logo.bottom
        anchors.left: logo.right; anchors.leftMargin: 10
        font.pixelSize: 25
        font.weight: Font.Thin
        visible: false
    }

    Clock {
        id: clock
        x: 65; y: mainWindow.height/2 - 125
        scale: 10
    }

    Weather {
        id: weather
        //x: 65; y: mainWindow.height/2 + 50
        x: mainWindow.width/4 - 135; y: mainWindow.height/2 + 50
        //scale: 3
    }

    Text {
        id: txtSwipe
        text: qsTr("swipe tag")
        width: 335; height: mainWindow.height - 125
        x: 535; y: mainWindow.height/2 - txtSwipe.height/2 + 155
        font.pixelSize: 30
        font.weight: Font.Light

        SequentialAnimation {
            id: txtSwipeAnimation
            running: true
            loops: Animation.Infinite
            NumberAnimation { target: txtSwipe; property: "opacity"; to: 0.3; duration: 650;  easing.type: Easing.Linear }
            NumberAnimation { target: txtSwipe; property: "opacity"; to: 1; duration: 650;  easing.type: Easing.Linear }
        }
    }
//    Image {
//        id: arrows
//        source: "resources/arrows.png"
//        width: 100; height: 65
//        y: mainWindow.height/2 - arrows.height/2
//        anchors.left: txtSwipe.right
//        anchors.leftMargin: -190

//    }

    Rectangle {
        id: arrows
        width: arrow1.width + arrow2.width + arrow3.width - 15; height: 75
        y: mainWindow.height/2 - arrows.height/2
        anchors.left: txtSwipe.right
        anchors.leftMargin: -190
        color: mainWindow.color
        Image {
            id: arrow1
            source: "resources/arrows/arrow1.png"
            width: 40; height: arrows.height
            anchors.left: arrows.left
            anchors.verticalCenter: arrows.verticalCenter
            opacity: 0
        }
        Image {
            id: arrow2
            source: "resources/arrows/arrow2.png"
            width: 40; height: arrows.height
            anchors.horizontalCenter: arrows.horizontalCenter
            anchors.verticalCenter: arrows.verticalCenter
            opacity: 0
        }
        Image {
            id: arrow3
            source: "resources/arrows/arrow3.png"
            width: 40; height: arrows.height
            anchors.right: arrows.right
            anchors.verticalCenter: arrows.verticalCenter
            opacity: 0
        }
        SequentialAnimation {
            id: arrowsAnimation
            running: true
            loops: Animation.Infinite
            NumberAnimation { target: arrow1; property: "opacity"; to: 1; duration: 215;  easing.type: Easing.Linear }
            NumberAnimation { target: arrow2; property: "opacity"; to: 1; duration: 215;  easing.type: Easing.Linear }
            NumberAnimation { target: arrow3; property: "opacity"; to: 1; duration: 215;  easing.type: Easing.Linear }
            NumberAnimation { target: arrow1; property: "opacity"; to: 0; duration: 215;  easing.type: Easing.Linear }
            NumberAnimation { target: arrow2; property: "opacity"; to: 0; duration: 215;  easing.type: Easing.Linear }
            NumberAnimation { target: arrow3; property: "opacity"; to: 0; duration: 215;  easing.type: Easing.Linear }
        }
    }

    Pane {
        id: userInfoHolder
        width: 325; height: mainWindow.height - 150
        x: 425; y: mainWindow.height/2 - userInfoHolder.height/2 + 45
        Material.elevation: 15
        Material.background: "#e0e0e0"
        scale: 0
        visible: true

        Rectangle {
            width: 200; height: 200
            radius: width*0.5
            anchors.verticalCenter: parent.top
            anchors.horizontalCenter: parent.horizontalCenter
            Image {
                id: imgEmployeePhoto
                //source: "resources/gio.png"
                anchors.fill: parent
                scale: 0.97
                cache: false
            }
            Image {
                id: imgEmployeePhotoLock
                source: "resources/lock.png"
                anchors.fill: parent
                scale: 0.97
                visible: false
                //cache: false
            }
        }

        Label {
            id: employeeName
            //text: qsTr("Giovanni Santana")
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            anchors.verticalCenterOffset: -25
            font.pixelSize: 35
            font.weight: Font.Light
        }

        RowLayout {
            id: timesheetMarkers
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            anchors.verticalCenterOffset: 33
            spacing: 15

            Rectangle {
                id: clockInCircle
                width: 30; height: 30
                radius: width*0.5
                color: "#bfbfbf"
            }
            Rectangle {
                id: lunchInCircle
                width: 30; height: 30
                radius: width*0.5
                color: "#bfbfbf"
            }
            Rectangle {
                id: lunchOutCircle
                width: 30; height: 30
                radius: width*0.5
                color: "#bfbfbf"
            }
            Rectangle {
                id: clockOutCircle
                width: 30; height: 30
                radius: width*0.5
                color: "#bfbfbf"
            }
        }

        Label {
            id: tagID
            //text: qsTr("Tag ID: " + "123456")
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            anchors.verticalCenterOffset: 95
            font.pixelSize: 21
            font.weight: Font.Thin
        }
        Label {
            id: time
            //text: qsTr("10:10")
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            anchors.verticalCenterOffset: 135
            font.pixelSize: 27
            font.weight: Font.Thin
        }
        ScaleAnimator {
            id: scaleAnimatorIn
            target: userInfoHolder;
            from: 0;
            to: 1;
            duration: 450
            running: false
            //onStarted: console.log("animation started")
            easing.type: Easing.OutBack
            onStopped: {
                arrows.visible = false
                txtSwipe.visible = false
            }
        }
        ScaleAnimator {
            id: scaleAnimatorOut
            target: userInfoHolder;
            from: 1;
            to: 0;
            duration: 300
            running: false
            //onStarted: console.log("animation started")
            easing.type: Easing.InBack
            onStopped: {
                arrows.visible = true
                txtSwipe.visible = true
            }

//            onRunningChanged: {
//                if(!scaleAnimatorOut.running) {
//                    arrows.visible = true
//                    txtSwipe.visible = true
//                } else {
//                    arrows.visible = false
//                    txtSwipe.visible = false
//                }
//            }
        }
    }
}

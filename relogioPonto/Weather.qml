import QtQuick 2.0
import QtQuick.XmlListModel 2.0

Item {
    Timer {
        interval: 15000
        running: true
        repeat: true
        onTriggered: makeRequest()
    }
    function makeRequest() {
        var url = "http://api.openweathermap.org/data/2.5/weather?q=Itacorubi&units=metric&appid=4ade7e043103b954fedf94a6e7e838e4&mode=json"
        var jsonResponse;
        var jsonObject;
        var icon;
        var temp;
        var weatherDescription;
        var xhttp = new XMLHttpRequest();

        xhttp.onreadystatechange = function() {
            if (xhttp.readyState == 4 && xhttp.status == 200) {
                //console.log(JSON.parse(xhttp.responseText.toString()));
                jsonResponse = JSON.parse(xhttp.responseText.toString());
                jsonObject = JSON.stringify(jsonResponse, null, 2);
                temp = JSON.stringify(jsonResponse.main.temp, null, 2);
                icon = JSON.stringify(jsonResponse.weather[0].icon, null, 2);
                weatherDescription = JSON.stringify(jsonResponse.weather[0].main, null, 2);
                //console.log(temp + " " + icon + " " + weatherDescription);
                temperature.text = temp + "ºC";
                weatherIcon.source = "resources/weather-icons/"+ icon.slice(1, -1) +".png";
                description.text = weatherDescription.slice(1, -1);
            }
        }
        xhttp.open("GET", url, true);
        xhttp.send();
    }

    Rectangle {
        id: weatherHolder
        color: mainWindow.color

        Text {
            id: temperature
            text: qsTr("---")
            font.pixelSize: 30
            font.weight: Font.Medium
        }

        Image {
            id: weatherIcon
            //source: "resources/weather-icons/11n.png"
            scale: 0.3
            anchors.left: temperature.left
            anchors.leftMargin: -70
            anchors.verticalCenter: temperature.verticalCenter
        }

        Text {
            id: description
            x: -100
            text: qsTr("---")
            anchors.verticalCenterOffset: 1
            font.pixelSize: 25
            font.weight: Font.Thin
            anchors.left: weatherIcon.left
            anchors.leftMargin: 280
            anchors.verticalCenter: temperature.verticalCenter
        }
    }
}

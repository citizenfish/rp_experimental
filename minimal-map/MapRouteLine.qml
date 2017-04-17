import QtQuick 2.0
import QtLocation 5.6


MapPolyline {
    id: mapRouteLine
    line.color: "#46a2da"
    line.width: 4
    opacity: 0.75
    smooth: true

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        acceptedButtons: Qt.LeftButton | Qt.RightButton
        onClicked: {
            console.log('LINE');
        }
    }

    /* Called when a new routePoint is added */

    function setGeometry(markers, index){
        for (var i = index; i<markers.length; i++){
            addCoordinate(markers[i].coordinate);
        }
    }


}

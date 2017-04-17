import QtQuick 2.0
import QtLocation 5.6

MapQuickItem {
    id: routePoint
    anchorPoint.x: image.width/4
    anchorPoint.y: image.height

    sourceItem: Image {
        id: image
        source: "./images/marker.png"
    }
}

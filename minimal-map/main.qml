import QtQuick 2.6
import QtQuick.Window 2.2
import QtLocation 5.6
import QtPositioning 5.6
import QtQuick.Controls 1.4


ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Dave's Minimal Map")


    /* Tile generation
       1) Convert rasters to EPSG3857
       2) edit gdal2tiles.py as per http://gis.stackexchange.com/questions/63024/gdal2tiles-maptiles-from-bsb-kap-are-switched
       3) /usr/bin/gdal2tiles.py --profile=geodetic -z 0-8 min-merc2.tif /var/www/html/

       ..for 1-25k do not use godetic cut and zoom level 15 is cool

        gdalbuildvrt 1-25k-su.vrt *.tif
        gdal_translate -expand RGB 1-25k-su.vrt 1-25k-su-exp.vrt
        gdalwarp -t_srs EPSG:3857 1-25k-su-exp.vrt 1-25k-su-mercator.vrt
        gdal2tiles.py -z 15 1-25k-su-mercator.vrt /var/www/html

       OS GEOREF files https://www.ordnancesurvey.co.uk/business-and-government/help-and-support/products/georeferencing-files-land-sea-tiles.html#25k
    */

    menuBar: modeMenu

    MainMenu {
        id:modeMenu
    }


    Plugin {
        id: myPlugin
        name: "osm"
        PluginParameter { name: "osm.mapping.copyright";value: "The documentation is wrong." }
        PluginParameter { name: "osm.mapping.host"; value: "http://localhost/" }
        PluginParameter { name : "osm.mapping.cache.directory"; value: "/tmp/cache"}
    }


    Map {
        /* needed so code can refer to me */
        id: map

        /* route points variables */
        property variant routePoints
        property variant activeRoute
        property int routePointCounter: 0


        anchors.fill :parent
        plugin: myPlugin
        center : QtPositioning.coordinate(51.5,-1.7)
        zoomLevel: 15
        Component.onCompleted: {
                   for( var i_type in supportedMapTypes ) {
                       if( supportedMapTypes[i_type].name.localeCompare( "Custom URL Map" ) === 0 ) {
                           activeMapType = supportedMapTypes[i_type]
                       }
                   }

                    routePoints = new Array();
               }

        /* Pick up map mouse events here */
        MouseArea {
            id: mouseArea
            anchors.fill: parent
            property variant lastCoordinate

            acceptedButtons: Qt.LeftButton | Qt.RightButton
            onClicked: {
                lastCoordinate = map.toCoordinate(Qt.point(mouse.x, mouse.y))
                if (mouse.button == Qt.RightButton) {
                    map.addRoutePoint();
                }
            }
        }

        /* Map Functions */

        function addRoutePoint()
        {
            var count = map.routePoints.length
            map.routePointCounter++


            var marker = Qt.createQmlObject ('RoutePoint {}', map)
            map.addMapItem(marker)
            marker.z = map.z+1
            marker.coordinate = mouseArea.lastCoordinate

            //update list of markers
            var myArray = new Array()
            for (var i = 0; i<count; i++){
                myArray.push(routePoints[i])
            }
            myArray.push(marker)
            routePoints = myArray

            /* If we have 2 points then create the line */

            if(routePointCounter == 2) {
                activeRoute = Qt.createQmlObject('MapRouteLine {}', map);
                activeRoute.setGeometry(routePoints,0);
                map.addMapItem(activeRoute);


            }

            /* and trigger its redraw */

            if(routePointCounter >= 2) {

                activeRoute.setGeometry(routePoints,routePointCounter - 1);
            }
        }

    }

}

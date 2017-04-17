//Give map object global context
var map;

/*
  init_map - display the map and add a layer selection control
*/

function init_map(){

    map = L.map('mapid').setView([51.505, -0.09], 15);

    var basemap = {

        osm:  L.tileLayer('https://api.tiles.mapbox.com/v4/{id}/{z}/{x}/{y}.png?access_token=pk.eyJ1IjoibWFwYm94IiwiYSI6ImNpejY4NXVycTA2emYycXBndHRqcmZ3N3gifQ.rJcFIG214AriISLbB6B5aw',
                          {maxZoom: 18,id: 'mapbox.streets'}),

        os:    L.tileLayer.wms('http://localhost/cgi-bin/mapserv.ngx?map=/home/daveb/Development/JavascriptAPITest/raster_mapfile.map',
                            {layers: 'osraster_paid'})
    };

    L.control.layers(basemap).addTo(map);
    basemap.os.addTo(map);

}

function add_gpx_to_map(gpx) {

    new L.GPX(gpx, {async: true}).on('loaded', function(e) {
        map.fitBounds(e.target.getBounds());
    }).addTo(map);
}

function add_route_edit_layer() {

    var editableLayers = new L.FeatureGroup();
    map.addLayer(editableLayers);
    var MyCustomMarker = L.Icon.extend({
            options: {
                shadowUrl: null,
                iconAnchor: new L.Point(12, 12),
                iconSize: new L.Point(24, 24),
                iconUrl: 'link/to/image.png'
            }
        });
        var options = {
            position: 'topleft',
            draw: {
                polyline: {
                    shapeOptions: {
                        color: '#FFFF00',
                        weight: 10
                    }
                },
                //false turns off the tools that we don't want
                polygon: false,
                circle: false,
                rectangle: false,
                marker: {
                    icon: new MyCustomMarker()
                }
            },
            edit: {
                featureGroup: editableLayers, //REQUIRED!!
                remove: false
            }
        };

        var drawControl = new L.Control.Draw(options);
        map.addControl(drawControl);

        map.on(L.Draw.Event.CREATED, function (e) {
            var type = e.layerType,
                layer = e.layer;

            if (type === 'marker') {
                layer.bindPopup('A popup!');
            }

            editableLayers.addLayer(layer);
        });

}

var map;

function init_map(){



    var layers = [
            /*new ol.layer.Tile({
              source: new ol.source.OSM()
            }),*/
            new ol.layer.Tile({
              //extent: [-13884991, 2870341, -7455066, 6338219],
              source: new ol.source.TileWMS({
                url: 'http://localhost/cgi-bin/mapserv.ngx?map=/opt/nautoguide/mapfiles/raster_mapfile.map',
                params: {'LAYERS': 'osraster_paid', 'TILED': true},
                serverType: 'mapserver'
              })
            })
          ];

    Proj4.defs("EPSG:27700","+proj=tmerc +lat_0=49 +lon_0=-2 +k=0.9996012717 +x_0=400000 +y_0=-100000 +ellps=airy +towgs84=446.448,-125.157,542.06,0.15,0.247,0.842,-20.489 +units=m +no_defs");
    var extent = [-3276800, -3276800, 3276800, 3276800];
    var bng = ol.proj.get('EPSG:27700');
    bng.setExtent(extent);

    map = new ol.Map({
            layers: layers,
            target: 'map',
            view: new ol.View({
              projection: bng,
              //center: [-7337.954715376922,6709336.594759629],
              center: [423085,158612],
              zoom: 15
            })
          });

}

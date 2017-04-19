var map;
var defaultStyle = {
    'Point': new ol.style.Style({
      image: new ol.style.Circle({
        fill: new ol.style.Fill({
          color: 'rgba(255,255,0,0.5)'
        }),
        radius: 5,
        stroke: new ol.style.Stroke({
          color: '#ff0',
          width: 1
        })
      })
    }),
    'LineString': new ol.style.Style({
      stroke: new ol.style.Stroke({
        color: '#f00',
        width: 3
      })
    }),
    'Polygon': new ol.style.Style({
      fill: new ol.style.Fill({
        color: 'rgba(0,255,255,0.5)'
      }),
      stroke: new ol.style.Stroke({
        color: '#0ff',
        width: 1
      })
    }),
    'MultiPoint': new ol.style.Style({
      image: new ol.style.Circle({
        fill: new ol.style.Fill({
          color: 'rgba(255,0,255,0.5)'
        }),
        radius: 5,
        stroke: new ol.style.Stroke({
          color: '#f0f',
          width: 1
        })
      })
    }),
    'MultiLineString': new ol.style.Style({
      stroke: new ol.style.Stroke({
        color: '#0f0',
        width: 3
      })
    }),
    'MultiPolygon': new ol.style.Style({
      fill: new ol.style.Fill({
        color: 'rgba(0,0,255,0.5)'
      }),
      stroke: new ol.style.Stroke({
        color: '#00f',
        width: 1
      })
    })
  };

var styleFunction = function(feature, resolution) {
   var featureStyleFunction = feature.getStyleFunction();
   if (featureStyleFunction) {
     return featureStyleFunction.call(feature, resolution);
   } else {
     return defaultStyle[feature.getGeometry().getType()];
   }
 };


function init_map(){



    var layers = [
            new ol.layer.Tile({
              source: new ol.source.OSM()
            }),
            new ol.layer.Tile({
              //extent: [-13884991, 2870341, -7455066, 6338219],
              source: new ol.source.TileWMS({
                url: 'http://localhost/cgi-bin/mapserv.ngx?map=/opt/nautoguide/mapfiles/raster_mapfile.map',
                params: {'LAYERS': 'osraster_paid', 'TILED': true},
                serverType: 'mapserver'
              })
            })
          ];




    proj4.defs("EPSG:27700","+proj=tmerc +lat_0=49 +lon_0=-2 +k=0.9996012717 +x_0=400000 +y_0=-100000 +ellps=airy +towgs84=446.448,-125.157,542.06,0.15,0.247,0.842,-20.489 +units=m +no_defs");
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
              zoom: 12
            })
          });

}

function add_gpx_to_map(gpx) {

    var gpxFormat = new ol.format.GPX();
    var gpxFeatures;
    var gpxLayer = new ol.layer.Vector({
        source: new ol.source.Vector({

        }),
        style: styleFunction
    });

    gpxFeatures = gpxFormat.readFeatures(gpx,{dataProjection:'EPSG:4326', featureProjection:'EPSG:3857'});
    gpxLayer.getSource().addFeatures(gpxFeatures);
    map.addLayer(gpxLayer);
    gpxLayer.setVisible(true);
}

window.onload = function() {
    if (location.search != "")
        var baseUrl = (/[?&]webChannelBaseUrl=([A-Za-z0-9\-:/\.]+)/.exec(location.search)[1]);
    else
        var baseUrl = "ws://localhost:12345";

    //output("Connecting to WebSocket server at " + baseUrl + ".");
    var socket = new WebSocket(baseUrl);

    socket.onclose = function()
    {
        console.error("web channel closed");
    };
    socket.onerror = function(error)
    {
        console.error(error);
    };
    socket.onopen = function()
    {
        //output("WebSocket connected, setting up QWebChannel.");
        new QWebChannel(socket, function(channel) {

            window.wc = channel.objects.webConnector;

            /*
                This is where we receive messages from QT
                a json object of structure {method : 'foo', params : {foo :bar, foo1: bar1...}}
                The method is used to call the relevant internal javascript function
            */

            wc.sendAPICall.connect(function(message) {
                api_methods(message.method,message.params);
            });

            wc.wc_api_interface_receive({message : "Client connected, ready to send/receive messages!"});
        });
    }
};


function api_methods(method, params) {

    switch(method) {

      //Create a new layer for editing a route
      case 'newroute':
          if(map.editmode === undefined || map.editmode !== 'createroute') {
              map.editmode = 'newroute';
              add_route_edit_layer();
          }
          break;

      //Display a GPX and allow editing
      case 'viewGPX' :
          add_gpx_to_map(params.gpx);
    };
}

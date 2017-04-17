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
            // make dialog object accessible globally
            window.dialog = channel.objects.mainWindow;

            dialog.sendText.connect(function(message) {
                $('#messagebox').html('<p>' + message + '</p>');

                var params,method;
                try {
                    params =  JSON.parse(message);
                    method = params.method;
                    params = params.params;
                } catch(e) {

                    method = message;
                }

                api_methods(method);
            });

            dialog.receiveText("Client connected, ready to send/receive messages!");
        });
    }
};


function api_methods(method, param) {

    switch(method) {

      case 'newroute':
          if(map.editmode === undefined || map.editmode !== 'createroute') {
              map.editmode = 'newroute';
              add_route_edit_layer();
          }

          break;
    };
}

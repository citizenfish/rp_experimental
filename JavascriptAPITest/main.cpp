#include "mainwindow.h"
#include <QApplication>
#include <QtWebSockets/QWebSocketServer>
#include <QWebChannel>
#include "websocketclientwrapper.h"
#include "websockettransport.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;


    // setup the QWebSocketServer has to be here to be persistent
    QWebSocketServer server(QStringLiteral("QWebChannel Standalone Example Server"), QWebSocketServer::NonSecureMode);
    if (!server.listen(QHostAddress::LocalHost, 12345)) {
        qFatal("Failed to open web socket server.");
        return 1;
    }

    // wrap WebSocket clients in QWebChannelAbstractTransport objects
    WebSocketClientWrapper clientWrapper(&server);

    // setup the channel
    QWebChannel channel;
    QObject::connect(&clientWrapper, &WebSocketClientWrapper::clientConnected,
                     &channel, &QWebChannel::connectTo);


    /* Connect the channel to the Mainwindow object so I can pass messages back an forth*/
    channel.registerObject(QStringLiteral("mainWindow"), &w);

    w.show();

    return a.exec();
}

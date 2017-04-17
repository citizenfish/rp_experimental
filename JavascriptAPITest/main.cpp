#include "mainwindow.h"
#include <QApplication>
#include <QtWebSockets/QWebSocketServer>
#include <QWebChannel>
#include <QObject>
#include "websocketclientwrapper.h"
#include "websockettransport.h"
#include "webconnector.h"

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


    /* Connect the channel to the WebConnecor object so I can pass messages back an forth*/
    WebConnector wc;
    channel.registerObject(QStringLiteral("webConnector"), &wc);

    /* Connnect MainWindow signals to webconnector slots */
    QObject::connect(&w, &MainWindow::sendAPICall, &wc, &WebConnector::wc_api_interface_send);
    QObject::connect(&wc, &WebConnector::receiveAPICall, &w, &MainWindow::receiveAPICall);

    w.show();

    return a.exec();
}

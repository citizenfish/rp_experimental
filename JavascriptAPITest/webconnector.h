#ifndef WEBCONNECTOR_H
#define WEBCONNECTOR_H

#include <QObject>
#include <QJsonObject>
#include <QJsonDocument>
#include <QDebug>

class WebConnector : public QObject
{
    Q_OBJECT
public:
    explicit WebConnector(QObject *parent = 0);

signals:
    void sendAPICall(const QJsonObject &params);      // JS client will listen to this
    void receiveAPICall(const QJsonObject &params);  // Interested classes will listen to this

public slots:
    void wc_api_interface_send(const QJsonObject &params);    //Interested classes will use this to send API calls
    void wc_api_interface_receive(const QJsonObject &params); //JS client will call this method to send a response
};

#endif // WEBCONNECTOR_H

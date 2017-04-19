#include "webconnector.h"

WebConnector::WebConnector(QObject *parent) : QObject(parent)
{

}

void WebConnector::wc_api_interface_send(const QJsonObject &params)
{
    //qDebug() << "SEND TO JS API " << params;
    emit sendAPICall(params);
}

void WebConnector::wc_api_interface_receive(const QJsonObject &params)
{
    qDebug() << "RECEIVE FROM JS API " << params;
}



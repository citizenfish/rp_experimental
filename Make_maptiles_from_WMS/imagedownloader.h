#ifndef IMAGEDOWNLOADER_H
#define IMAGEDOWNLOADER_H
#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QFile>
#include <QStringList>
#include <QObject>

class imageDownloader : public QObject
{
    Q_OBJECT
    QFile *m_file;
    bool m_isReady = true;

public:
    explicit imageDownloader(QObject *parent = 0) : QObject(parent) {}
    virtual ~imageDownloader() { delete m_file; }
    void downloadFileFromURL(const QString &url, const QString &filePath);

private slots:
        void onDownloadFileComplete(QNetworkReply *reply);

};

#endif // IMAGEDOWNLOADER_H

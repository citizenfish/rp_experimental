#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWebEngineView>
#include <QFileDialog>
#include <QFile>
#include <QErrorMessage>
#include <QJsonObject>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    //void receiveText(const QString &text);


private:
    Ui::MainWindow *ui;
    QWebEngineView webView;

signals:
   void sendAPICall(const QJsonObject);

public slots:
    void newRoute(); // Create a new route
    void loadGPXPostgres(); //Load a GPX from postgres
    void loadGPXFile();     //Load a GPX from a file
    void receiveAPICall(const QJsonObject);

};

#endif // MAINWINDOW_H

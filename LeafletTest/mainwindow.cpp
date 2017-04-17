#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);



    QWebEngineView  *webView = new QWebEngineView(this);

    QWebChannel *channel = new QWebChannel(webView);

    webView->setUrl(QUrl("file:///home/daveb/Development/LeafletTest/index.html"));
    setCentralWidget(webView);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayHTMLMessage(const QString &str){

    qDebug() << str;
}

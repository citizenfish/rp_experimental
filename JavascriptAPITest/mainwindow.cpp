#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /* This sets up my web view and sticks it into the centre of the screen */
    QWebEngineView  *webView = new QWebEngineView(this);
    QUrl url = QUrl::fromLocalFile(BUILD_DIR "/leaflet.html");
    webView->setUrl(url);
    setCentralWidget(webView);

}

/* This method receives messages from the javascript client */
void MainWindow::receiveText(const QString &text){

    qDebug() << text;

    emit sendText(QString("Foo to the fooo fooo"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

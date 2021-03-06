#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /* This sets up my web view and sticks it into the centre of the screen */
    QWebEngineView  *webView = new QWebEngineView(this);
    QUrl url = QUrl::fromLocalFile(BUILD_DIR "/openlayers.html");
    webView->setUrl(url);
    setCentralWidget(webView);

}


void MainWindow::newRoute()
{
    QJsonObject params;
    params["method"] = "viewGPX";
    params["params"]  = "";
    emit sendAPICall(params);
}

void MainWindow::loadGPXPostgres()
{

}

/*
 * Open a GPS file from a file dialog and then create a JSON API call to load onto map
*/
void MainWindow::loadGPXFile()
{
    //Read the data into a string and then form a command to load GPX
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open GPX"), ".", tr("GPX Files (*.gpx)"));
    QFile gpxFile(fileName);
    if(!gpxFile.open(QFile::ReadOnly | QFile::Text)) {
        QErrorMessage *error = new QErrorMessage(this);
        error->showMessage(QString("Cannot open GPX File"));
    }

    QTextStream gpxStream(&gpxFile);
    QString gpxData = gpxStream.readAll();

    //Make a JSON API call, I need to find better way to do nesting
    QJsonObject apiCall;
    QJsonObject params;
    apiCall["method"] = "viewGPX";
    params["gpx"]  = gpxData;
    apiCall["params"] = params;

    emit sendAPICall(apiCall);
}

void MainWindow::receiveAPICall(const QJsonObject)
{

}

MainWindow::~MainWindow()
{
    delete ui;
}

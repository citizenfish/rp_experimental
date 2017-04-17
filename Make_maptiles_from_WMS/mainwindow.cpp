#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "imagedownloader.h"
#include <QDebug>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
#include "tileutils.h"

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::makeTiles(){

       int minZoom;
       int maxZoom;
       int z;
       int tiles;
       bbox boundingBox;
       imageDownloader *image;

       minZoom = ui->zoomStart->value();
       maxZoom = ui->zoomEnd->value();

       //Select Directory

       QFileDialog dialog(this);
       dialog.setFileMode(QFileDialog::Directory);
       QString _OutputFolder = QFileDialog::getExistingDirectory(0, ("Select Output Folder"), QDir::currentPath());

       for (int i = minZoom; i <= maxZoom; i ++){

            ui->statusMessages->append(QString("Processing Zoom Level %1").arg(i));
            z = i;
            tiles = pow(2, i);

            for (int y = 1; y <= tiles; y ++) {
                for(int x = 1; x <= tiles; x++) {
                     ui->statusMessages->append(QString("Processing Tile %1 %2").arg(x).arg(y));
                     boundingBox = makeBBox(x,y,z);
                     QDir outputDir(QString("%1/tiles/%2/%3").arg(_OutputFolder).arg(z).arg(y) );
                     qDebug() << outputDir;
                     if(!outputDir.exists()){
                         outputDir.mkpath(".");
                     }
                    image = new imageDownloader();
                    image->downloadFileFromURL(QString("%1&service=WMS&request=GetMap&layers=osraster_paid&styles=&format=image/png&transparent=false&version=1.1.1&height=256&width=256&srs=EPSG:4326&bbox=%2,%3,%4,%5")
                                               .arg("http://localhost/cgi-bin/mapserv.ngx?map=/home/daveb/Development/JavascriptAPITest/raster_mapfile.map")
                                               .arg(boundingBox.minX)
                                               .arg(boundingBox.minY)
                                               .arg(boundingBox.maxX)
                                               .arg(boundingBox.maxY),
                                               QString("/%1/tiles/%2/%3/%4.png").arg(_OutputFolder).arg(z).arg(y).arg(x));
                }
            }

       }
}

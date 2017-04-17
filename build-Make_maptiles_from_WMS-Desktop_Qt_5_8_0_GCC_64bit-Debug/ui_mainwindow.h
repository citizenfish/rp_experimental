/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionCreate_Tiles;
    QAction *actionDelete_Tiles;
    QAction *actionSettings;
    QAction *actionQuit;
    QWidget *centralWidget;
    QSpinBox *zoomStart;
    QSpinBox *zoomEnd;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QComboBox *sridSelector;
    QLabel *label_4;
    QProgressBar *progressBar;
    QPushButton *makeTilesButton;
    QTextBrowser *statusMessages;
    QPlainTextEdit *plainTextEdit;
    QMenuBar *menuBar;
    QMenu *menuNew;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(695, 512);
        actionCreate_Tiles = new QAction(MainWindow);
        actionCreate_Tiles->setObjectName(QStringLiteral("actionCreate_Tiles"));
        actionDelete_Tiles = new QAction(MainWindow);
        actionDelete_Tiles->setObjectName(QStringLiteral("actionDelete_Tiles"));
        actionSettings = new QAction(MainWindow);
        actionSettings->setObjectName(QStringLiteral("actionSettings"));
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        zoomStart = new QSpinBox(centralWidget);
        zoomStart->setObjectName(QStringLiteral("zoomStart"));
        zoomStart->setGeometry(QRect(130, 30, 48, 23));
        zoomEnd = new QSpinBox(centralWidget);
        zoomEnd->setObjectName(QStringLiteral("zoomEnd"));
        zoomEnd->setGeometry(QRect(130, 70, 48, 23));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 30, 71, 16));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 70, 71, 16));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 110, 71, 16));
        sridSelector = new QComboBox(centralWidget);
        sridSelector->setObjectName(QStringLiteral("sridSelector"));
        sridSelector->setGeometry(QRect(130, 160, 72, 22));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(40, 160, 59, 14));
        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(40, 410, 621, 23));
        progressBar->setValue(0);
        makeTilesButton = new QPushButton(centralWidget);
        makeTilesButton->setObjectName(QStringLiteral("makeTilesButton"));
        makeTilesButton->setGeometry(QRect(580, 370, 81, 22));
        statusMessages = new QTextBrowser(centralWidget);
        statusMessages->setObjectName(QStringLiteral("statusMessages"));
        statusMessages->setGeometry(QRect(40, 190, 521, 201));
        plainTextEdit = new QPlainTextEdit(centralWidget);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(120, 110, 521, 41));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 695, 19));
        menuNew = new QMenu(menuBar);
        menuNew->setObjectName(QStringLiteral("menuNew"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuNew->menuAction());
        menuNew->addAction(actionSettings);
        menuNew->addSeparator();
        menuNew->addAction(actionQuit);

        retranslateUi(MainWindow);
        QObject::connect(actionQuit, SIGNAL(triggered()), MainWindow, SLOT(close()));
        QObject::connect(makeTilesButton, SIGNAL(clicked()), MainWindow, SLOT(makeTiles()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Daves WMS Tile Creator", Q_NULLPTR));
        actionCreate_Tiles->setText(QApplication::translate("MainWindow", "Create Tiles", Q_NULLPTR));
        actionDelete_Tiles->setText(QApplication::translate("MainWindow", "Delete Tiles", Q_NULLPTR));
        actionSettings->setText(QApplication::translate("MainWindow", "Settings", Q_NULLPTR));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Min Zoom", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Max Zoom", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "WMS URL", Q_NULLPTR));
        sridSelector->clear();
        sridSelector->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "4326", Q_NULLPTR)
         << QApplication::translate("MainWindow", "27700", Q_NULLPTR)
         << QApplication::translate("MainWindow", "900913", Q_NULLPTR)
        );
        label_4->setText(QApplication::translate("MainWindow", "SRID", Q_NULLPTR));
        makeTilesButton->setText(QApplication::translate("MainWindow", "Make Tiles", Q_NULLPTR));
        plainTextEdit->setPlainText(QApplication::translate("MainWindow", "http://localhost/cgi-bin/mapserv.ngx?map=/home/daveb/Development/JavascriptAPITest/raster_mapfile.map", Q_NULLPTR));
        menuNew->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

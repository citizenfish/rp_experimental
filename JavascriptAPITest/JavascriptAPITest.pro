#-------------------------------------------------
#
# Project created by QtCreator 2017-02-28T20:27:55
#
#-------------------------------------------------

QT       += core gui websockets webchannel webenginewidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = JavascriptAPITest
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += "BUILD_DIR=\"\\\""$$PWD"\\\"\""
# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    websockettransport.cpp \
    websocketclientwrapper.cpp

HEADERS  += mainwindow.h \
    websockettransport.h \
    websocketclientwrapper.h

FORMS    += mainwindow.ui

DISTFILES += \
    index.html \
    qwebchannel.js \
    raster_mapfile.map \
    epsg \
    leaflet.html

install_it.path = $$PWD
install_it.files = *

INSTALLS += \
    install_it

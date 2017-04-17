TEMPLATE = app
TARGET = mapdemo
QT += widgets
CONFIG += console
CONFIG -= app_bundle

SOURCES += main.cpp

target.path = $$[QT_INSTALL_EXAMPLES]/qtconcurrent/map
INSTALLS += target

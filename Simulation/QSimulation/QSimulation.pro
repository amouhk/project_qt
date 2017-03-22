#-------------------------------------------------
#
# Project created by QtCreator 2017-03-21T10:00:53
#
#-------------------------------------------------

QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QSimulation
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    scene.cpp \
    station.cpp \
    commandstationadd.cpp \
    commandstationdelete.cpp \
    commandstationmove.cpp

HEADERS  += mainwindow.h \
    scene.h \
    station.h \
    commandstationadd.h \
    commandstationdelete.h \
    commandstationmove.h

FORMS    += mainwindow.ui

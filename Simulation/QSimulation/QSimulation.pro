#-------------------------------------------------
#
# Project created by QtCreator 2017-03-21T10:00:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QSimulation
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    scene.cpp \
    station.cpp

HEADERS  += mainwindow.h \
    scene.h \
    station.h

FORMS    += mainwindow.ui

#-------------------------------------------------
#
# Project created by QtCreator 2017-03-21T09:58:36
#
#-------------------------------------------------

QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = simulation
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    scene.cpp \
    station.cpp \
    commandstationadd.cpp \
    commandstationdelete.cpp \
    commandstationmove.cpp \
    undocommand.cpp \
    scenehandler.cpp

HEADERS  += mainwindow.h \
    scene.h \
    station.h \
    commandstationadd.h \
    commandstationdelete.h \
    commandstationmove.h \
    undocommand.h \
    scenehandler.h

FORMS    += mainwindow.ui

TRANSLATIONS = simulation_fr.ts simulation_en.ts

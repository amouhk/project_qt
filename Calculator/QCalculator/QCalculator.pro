#-------------------------------------------------
#
# Project created by QtCreator 2017-03-24T10:59:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QCalculator
TEMPLATE = app


SOURCES += main.cpp\
        qcalculator.cpp \
    operationmanager.cpp

HEADERS  += qcalculator.h \
    operationmanager.h \
    OperationInterface.h

FORMS    += qcalculator.ui

#include "mainwindow.h"
#include <QApplication>
#include <QTranslator>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator translator;
    cout << QCoreApplication::applicationDirPath().toStdString() << endl;
    translator.load("simulation_fr", QCoreApplication::applicationDirPath());
    a.installTranslator(&translator);
    MainWindow w;
    w.show();

    return a.exec();
}

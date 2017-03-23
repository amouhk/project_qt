#include "mainwindow.h"
#include <QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication l_application(argc, argv);

    // Declaration d'un translateur
    QTranslator l_translator;
    // chargement d'un dictionnaire
    l_translator.load("simulation_fr", "C:\\Users\\Administrateur.ADMIN-AR79QIL03\\Documents\\project_qt\\Simulation\\QSimulation");
    // installation du translateur dans l'application
    l_application.installTranslator(&l_translator);


    MainWindow w;
    w.show();

    return l_application.exec();
}

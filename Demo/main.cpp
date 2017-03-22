#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    // Parametres pour le passage des fichiers de config
    QApplication a(argc, argv);

    // Creation de ma fenetre
    MainWindow w;
    w.show();

    // Lanncement du process de l'application
    return a.exec();
}

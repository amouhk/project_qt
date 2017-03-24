/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLineEdit *variable1LE;
    QComboBox *operationsCB;
    QLineEdit *variable2LE;
    QLineEdit *variable3LE;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *resultLE;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(410, 340);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        variable1LE = new QLineEdit(centralWidget);
        variable1LE->setObjectName(QStringLiteral("variable1LE"));
        variable1LE->setGeometry(QRect(180, 70, 201, 21));
        QFont font;
        font.setPointSize(10);
        variable1LE->setFont(font);
        operationsCB = new QComboBox(centralWidget);
        operationsCB->setObjectName(QStringLiteral("operationsCB"));
        operationsCB->setGeometry(QRect(180, 20, 201, 22));
        variable2LE = new QLineEdit(centralWidget);
        variable2LE->setObjectName(QStringLiteral("variable2LE"));
        variable2LE->setGeometry(QRect(180, 120, 201, 21));
        variable2LE->setFont(font);
        variable3LE = new QLineEdit(centralWidget);
        variable3LE->setObjectName(QStringLiteral("variable3LE"));
        variable3LE->setGeometry(QRect(180, 170, 201, 21));
        variable3LE->setFont(font);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 20, 81, 21));
        QFont font1;
        font1.setPointSize(12);
        label->setFont(font1);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 70, 71, 16));
        label_2->setFont(font1);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 120, 71, 16));
        label_3->setFont(font1);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 170, 71, 16));
        label_4->setFont(font1);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 240, 91, 31));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        label_5->setFont(font2);
        resultLE = new QLineEdit(centralWidget);
        resultLE->setObjectName(QStringLiteral("resultLE"));
        resultLE->setGeometry(QRect(180, 240, 201, 21));
        resultLE->setFont(font2);
        resultLE->setReadOnly(true);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 410, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        variable1LE->setText(QApplication::translate("MainWindow", "1212", 0));
        variable2LE->setText(QApplication::translate("MainWindow", "1212", 0));
        variable3LE->setText(QApplication::translate("MainWindow", "1212", 0));
        label->setText(QApplication::translate("MainWindow", "Op\303\251rations", 0));
        label_2->setText(QApplication::translate("MainWindow", "Variable1", 0));
        label_3->setText(QApplication::translate("MainWindow", "Variable2", 0));
        label_4->setText(QApplication::translate("MainWindow", "Variable3", 0));
        label_5->setText(QApplication::translate("MainWindow", "R\303\251sultat", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

/********************************************************************************
** Form generated from reading UI file 'qcalculator.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QCALCULATOR_H
#define UI_QCALCULATOR_H

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

class Ui_QCalculator
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QComboBox *operationCBox;
    QLineEdit *var1LineEdit;
    QLineEdit *var2LineEdit;
    QLineEdit *var3LineEdit;
    QLineEdit *resultlineEdit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QCalculator)
    {
        if (QCalculator->objectName().isEmpty())
            QCalculator->setObjectName(QStringLiteral("QCalculator"));
        QCalculator->resize(365, 323);
        centralWidget = new QWidget(QCalculator);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 61, 31));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 70, 61, 16));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 120, 46, 13));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 170, 46, 13));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 230, 46, 13));
        operationCBox = new QComboBox(centralWidget);
        operationCBox->setObjectName(QStringLiteral("operationCBox"));
        operationCBox->setGeometry(QRect(120, 20, 181, 22));
        var1LineEdit = new QLineEdit(centralWidget);
        var1LineEdit->setObjectName(QStringLiteral("var1LineEdit"));
        var1LineEdit->setGeometry(QRect(120, 70, 181, 20));
        var2LineEdit = new QLineEdit(centralWidget);
        var2LineEdit->setObjectName(QStringLiteral("var2LineEdit"));
        var2LineEdit->setGeometry(QRect(120, 120, 181, 20));
        var3LineEdit = new QLineEdit(centralWidget);
        var3LineEdit->setObjectName(QStringLiteral("var3LineEdit"));
        var3LineEdit->setGeometry(QRect(120, 170, 181, 20));
        resultlineEdit = new QLineEdit(centralWidget);
        resultlineEdit->setObjectName(QStringLiteral("resultlineEdit"));
        resultlineEdit->setGeometry(QRect(120, 230, 181, 20));
        resultlineEdit->setReadOnly(true);
        QCalculator->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QCalculator);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 365, 21));
        QCalculator->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QCalculator);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QCalculator->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QCalculator);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QCalculator->setStatusBar(statusBar);

        retranslateUi(QCalculator);

        QMetaObject::connectSlotsByName(QCalculator);
    } // setupUi

    void retranslateUi(QMainWindow *QCalculator)
    {
        QCalculator->setWindowTitle(QApplication::translate("QCalculator", "QCalculator", 0));
        label->setText(QApplication::translate("QCalculator", "TextLabel", 0));
        label_2->setText(QApplication::translate("QCalculator", "Variable1", 0));
        label_3->setText(QApplication::translate("QCalculator", "Variable2", 0));
        label_4->setText(QApplication::translate("QCalculator", "Varible3", 0));
        label_5->setText(QApplication::translate("QCalculator", "Resultat", 0));
    } // retranslateUi

};

namespace Ui {
    class QCalculator: public Ui_QCalculator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QCALCULATOR_H

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //connexion des slots et des widgets
    connect(ui->addButton, SIGNAL(clicked()), this, SLOT(add()));
    connect(ui->quitButton, SIGNAL(clicked()), this, SLOT(quit()));
    connect(ui->incProgressBarBtn, SIGNAL(clicked()), this, SLOT(incr()));
    connect(ui->resetProgessBarBtn, SIGNAL(clicked()), this, SLOT(reset()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::add()
{

    QString l_input = ui->inputlineEdit->text();

    ui->inputlineEdit->clear();
    ui->resultEdit->append(l_input);

    if (m_info.isEmpty())
    {
        ui->resultEdit->setFocus();
        // Declaration
        QList<QTextEdit::ExtraSelection> l_selections;
        QTextEdit::ExtraSelection l_selection;
        QColor l_color  = QColor(255, 120, 120);

        l_selection.format.setBackground(l_color);
        l_selection.format.setProperty(QTextFormat::FullWidthSelection, true);

        QTextCursor l_cursor = ui->resultEdit->textCursor();
        qDebug() << "add::position:" << l_cursor.position();
        l_cursor.setPosition(1);
        //l_cursor.movePosition(QTextCursor::Start);
        //l_cursor.movePosition(QTextCursor::EndOfLine, QTextCursor::KeepAnchor);
        ui->resultEdit->setTextCursor(l_cursor);
        l_selection.cursor = l_cursor;

        l_selections.append(l_selection);
        ui->resultEdit->setExtraSelections(l_selections);
    }
    m_info.append(l_input);
}


void MainWindow::quit()
{
    // TODO: fermeture de l'application pour l'instant
    QFile l_outputFile("C:\\Users\\Administrateur\\Documents\\output_save.txt");
    if (!l_outputFile.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        return;
    }

    QTextStream l_outputStream(&l_outputFile);
    l_outputStream << ui->resultEdit->toPlainText();

    l_outputFile.close();
    this->close();
}

void MainWindow::incr()
{
    ui->resultEdit->setFocus();
    // valeur courant de la bar
    int l_pBarValue   = ui->resultProgressBar->value();

    // nombre d'element dans le champ de textEdit
    int l_nbTextLines = m_info.length();

    // on recupere la chaine de Qtext
    QString l_text          = ui->resultEdit->toPlainText();
    QStringList l_textItems = l_text.split("\n");

    if (l_pBarValue/(100/l_nbTextLines) < l_nbTextLines)
    {
        std::cout << "[" << l_pBarValue/(100/l_nbTextLines) << "]" << l_textItems.at(l_pBarValue/(100/l_nbTextLines)).toStdString() << std::endl;
        int l_start = l_text.indexOf(l_textItems.at(l_pBarValue/(100/l_nbTextLines)), 0, Qt::CaseSensitive);

        QTextCursor l_cursor = ui->resultEdit->textCursor();
        l_cursor.setPosition(l_start);
        l_cursor.setPosition(l_start + l_textItems.at(l_pBarValue/(100/l_nbTextLines)).length(), QTextCursor::KeepAnchor);

        ui->resultEdit->setTextCursor(l_cursor);
        ui->resultEdit->setFocus();
    }


    ui->resultProgressBar->setValue( l_pBarValue + (100/l_nbTextLines) );
}

void MainWindow::reset()
{
    ui->resultProgressBar->setValue(0);
}

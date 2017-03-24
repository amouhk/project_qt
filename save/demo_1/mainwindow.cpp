#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->addButton, SIGNAL(clicked()), this, SLOT(add()));
    connect(ui->quitButton, SIGNAL(clicked()), this, SLOT(quit()));

    connect(ui->nextButton, SIGNAL(clicked()), this, SLOT(next()));
    connect(ui->clearButton, SIGNAL(clicked()), this, SLOT(clear()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::quit()
{
    // TODO : afficher une boite de dialogue
    this->close();
}

void MainWindow::add()
{
    QString input = ui->inputEdit->text();
    infos.append(input);
    ui->resultEdit->append(input);
    ui->inputEdit->clear();
    if(!infos.empty())
    {
        QTextCursor cursor = ui->resultEdit->textCursor();
        QList<QTextEdit::ExtraSelection> selection;
        QTextEdit::ExtraSelection extra;

        cursor.movePosition(QTextCursor::Start);
        cursor.movePosition(QTextCursor::EndOfLine, QTextCursor::KeepAnchor);
        ui->resultEdit->setTextCursor(cursor);

        extra.cursor = cursor;
        extra.format.setProperty(QTextFormat::FullWidthSelection, true);
        extra.format.setBackground(Qt::red);
        selection.append(extra);

        ui->resultEdit->setExtraSelections(selection);
        cursor.movePosition(QTextCursor::Start);
        ui->resultEdit->setTextCursor(cursor);

        ui->inputEdit->setFocus();
    }
}

void MainWindow::next(){
    int progressValue = ui->ProgressList->value();
    int nb = infos.length();
    ui->ProgressList->setValue(progressValue + (100/nb));
}

void MainWindow::clear()
{
    ui->ProgressList->setValue(0);
}


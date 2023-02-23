#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QtCore>
#include <QDesktopServices>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_rulesButton_clicked()
{
    std::cout << "RULES BUTTON PRESSED" << std::endl;
    QDesktopServices::openUrl(QUrl("https://brainking.com/en/GameRules?tp=17", QUrl::TolerantMode));
}


void MainWindow::on_startButton_clicked()
{
    std::cout << "START GAME PRESSED" << std::endl;
}


void MainWindow::on_rulesButton_2_clicked()
{
    std::cout << "EXITING GAME" << std::endl;
    QApplication::quit();
}


//#include "mainwindow.h"
//#include "./ui_mainwindow.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include <QtCore>
#include <QDesktopServices>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QVBoxLayout>
#include <QFileDialog>
#include <iostream>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //add the image to the homescreen
    //QPixmap pix("C:/Users/logan/Desktop/EE273Project/Antichess/images/placeholder.png");


    QString relativePath = "../Antichess/images/placeholder.png";
    QPixmap pix(relativePath);
    ui->Start_image->setPixmap(pix);

    //link multiple widgets together for different pages
    stackedWidget = new QStackedWidget(this);
    stackedWidget->addWidget(ui->StartPage);
    stackedWidget->addWidget(ui->Game);

    stackedWidget->setCurrentIndex(0);
    connect(ui->startButton, SIGNAL(clicked()), this, SLOT(on_startButtonClicked()));
    connect(ui->mainMenuButton, SIGNAL(clicked()), this, SLOT(on_mainMenuButton_clicked()));

    setCentralWidget(stackedWidget);


    QPixmap pixmap("../Antichess/images/chess-board-vector_.jpg"); //DOUBLE CHECK THIS STILL WORKS AND THEN UPLOAD .JPG TO GIT REPO


    Scene = new QGraphicsScene(this);
    Scene->addPixmap(pixmap.scaledToHeight(500));
    ui->boardGraphic->setScene(Scene);









}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startButton_clicked()
{
    std::cout << "START GAME PRESSED\n";
    stackedWidget->setCurrentWidget(ui->Game);
}


void MainWindow::on_rulesButton_clicked()
{
    std::cout << "OPENING RULES\n";
    QDesktopServices::openUrl(QUrl("https://www.antichess.org/antichess-basics/", QUrl::TolerantMode));
}


void MainWindow::on_mainMenuButton_clicked()
{
    std::cout << "GOING TO MAIN MENU\n";
    stackedWidget->setCurrentWidget(ui->StartPage);
}


void MainWindow::on_exitGame_clicked()
{
    std::cout << "EXITING GAME\n";
    QApplication::exit();
}

void MainWindow::on_PawnTest_pressed()
{
    std::cout << "PAWN PRESSED\n";


}


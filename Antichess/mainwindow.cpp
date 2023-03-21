
//#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "mainwindow.h"
#include "Chess/board.h"
#include "Chess/Pieces.h"
#include "Chess/King.h"
#include "Chess/Queen.h"
#include "Chess/Pawn.h"
#include "Chess/Bishop.h"
#include "Chess/Knight.h"
#include "Chess/Rook.h"
#include "Points.h"
#include "Chess/move.h"
#include "utils/clickableLabels.h"
#include <QtCore>
#include <QDesktopServices>
#include <QPushButton>
#include <QGraphicsRectItem>
#include <QPainter>
#include <QGraphicsScene>
#include <QVBoxLayout>
#include <iostream>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //draw the board onto the screen
    QPixmap pix("../Antichess/images/background.png");
    Board gameBoard;
    ui->Start_image->setPixmap(pix);

    //link multiple widgets together for different pages
    stackedWidget = new QStackedWidget(this);
    stackedWidget->addWidget(ui->StartPage);
    stackedWidget->addWidget(ui->Game);

    stackedWidget->setCurrentIndex(0);

    //implementation of buttons
    connect(ui->startButton, SIGNAL(clicked()), this, SLOT(on_startButtonClicked()));
    connect(ui->mainMenuButton, SIGNAL(clicked()), this, SLOT(on_mainMenuButton_clicked()));
    //connect(ui->resetButton, SIGNAL(clicked()), this, SLOT(on_resetButton_clicked()));
    /*QPushButton *label = new QPushButton;
    label->setFlat(true);
    label->setFixedSize(50,50);
    label->setIconSize(QSize(50,50));
    //cout << "Drawing icon @: " << a << "," << b << ". ";
    label->setIcon(QPixmap("../Antichess/images/Pieces/bishop_w.svg")); //icons.at(setup[a][b]
    connect(label, SIGNAL(clicked()), this, SLOT(keyPressed()));
    //label->lower();
    ui->squares->addWidget(label,3,4);
*/
    setCentralWidget(stackedWidget);

    //import chess board image
    QPixmap pixmap("../Antichess/images/chess-board-vector_.jpg"); //DOUBLE CHECK THIS STILL WORKS AND THEN UPLOAD .JPG TO GIT REPO


    //create new graphics scene to position the board on the GUI

    Scene = new QGraphicsScene(this);


    Scene->addPixmap(pixmap.scaledToHeight(512));
    ui->boardGraphic->setScene(Scene);
    vector<string> init = gameBoard.setBoard("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR");
    updateGUI(init);


    //QLayoutItem *item = ui->gridLayout->itemAtPosition(2,2);

    //std::cout<< item <<std::endl;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::updateGUI(vector<string> setup){


    for(int a =0;a<8;a++){ //WHEN FEN NOTATION IS CHANGED TO "rnbqkbnr/pppppppp/8/8/4P3/8/PPP1PPPP/RNBQKBNR" PROGRAM CRASHES

        if(setup[a][0] == '8'){
            continue;
        }
        for(int b =0; b<8;b++){

            QPushButton *label = new QPushButton;
            label->setFlat(true);
            label->setFixedSize(54,56);
            label->setIconSize(QSize(50,50));
            cout << "Drawing icon @: " << a << "," << b << ". ";
            label->setIcon(gameBoard.icons.at(setup[a][b])); //icons.at(setup[a][b]

            connect(label, SIGNAL(clicked()), this, SLOT(keyPressed()));
            //label->lower();
            ui->squares->addWidget(label,a,b,Qt::AlignCenter);


        }
    }
    cout << endl;

}

void MainWindow::keyPressed(){


    QPushButton* pos = qobject_cast<QPushButton*>(sender());
    Points point(pos);




}


vector<pair<int,int>> MainWindow::getMoves(){

    return m_moves ;
}


void MainWindow::on_startButton_clicked()
{
    std::cerr << "START GAME PRESSED\n";
    stackedWidget->setCurrentWidget(ui->Game);
}


void MainWindow::on_rulesButton_clicked()
{
    std::cerr << "OPENING RULES\n";
    QDesktopServices::openUrl(QUrl("https://www.antichess.org/antichess-basics/", QUrl::TolerantMode));
}


void MainWindow::on_mainMenuButton_clicked()
{
    std::cerr << "GOING TO MAIN MENU\n";
    stackedWidget->setCurrentWidget(ui->StartPage);
}


void MainWindow::on_exitGame_clicked()
{
    std::cerr << "EXITING GAME\n";
    QApplication::exit();
}


void MainWindow::on_resetButton_clicked()
{
    bool reset_flag = true;
    gameBoard.resetBoard(reset_flag);

}



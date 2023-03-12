
//#include "mainwindow.h"
#include "./ui_mainwindow.h"
//#include "ui_mainwindow.h"
#include "mainwindow.h"
#include "Chess/board.h"
#include "Chess/Pieces.h"
#include "Chess/King.h"
#include "Chess/Queen.h"
#include "Chess/Pawn.h"
#include "Chess/Bishop.h"
#include "Chess/Knight.h"
#include "Chess/Rook.h"
#include "Chess/move.h"
#include "utils/clickableLabels.h"
#include <QtCore>
#include <QDesktopServices>
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

    setCentralWidget(stackedWidget);

    //import chess board image
    QPixmap pixmap("../Antichess/images/chess-board-vector_.jpg"); //DOUBLE CHECK THIS STILL WORKS AND THEN UPLOAD .JPG TO GIT REPO


    //create new graphics scene to position the board on the GUI

    Scene = new QGraphicsScene(this);
    Scene->addPixmap(pixmap.scaledToHeight(520));
    ui->boardGraphic->setScene(Scene);
    vector<string> init = gameBoard.setBoard();
    updateGUI(init);


    //QLayoutItem *item = ui->gridLayout->itemAtPosition(2,2);

    //std::cout<< item <<std::endl;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::updateGUI(vector<string> setup){


    King bKing('b');
    Queen bQueen('b');
    Bishop bBishop('b');
    Knight bKnight('b');
    Rook bRook('b');
    Pawn bPawn('b');

    King wKing('w');
    Queen wQueen('w');
    Bishop wBishop('w');
    Knight wKnight('w');
    Rook wRook('w');
    Pawn wPawn('w');

    map<char,QPixmap> icons;

    icons = {
        {'k',bKing.getIcon()},
        {'q',bQueen.getIcon()},
        {'b',bBishop.getIcon()},
        {'n',bKnight.getIcon()},
        {'r',bRook.getIcon()},
        {'p',bPawn.getIcon()},

        {'K',wKing.getIcon()},
        {'Q',wQueen.getIcon()},
        {'B',wBishop.getIcon()},
        {'N',wKnight.getIcon()},
        {'R',wRook.getIcon()},
        {'P',wPawn.getIcon()},
        {'8',wPawn.getIcon()}
    };

    for(int a =0;a<8;a++){ //WHEN FEN NOTATION IS CHANGED TO "rnbqkbnr/pppppppp/8/8/4P3/8/PPP1PPPP/RNBQKBNR" PROGRAM CRASHES

        if(setup[a][0] == '8'){
            continue;
        }
        for(int b =0; b<8;b++){
            clickablelabels *label = new clickablelabels;
            cout << a << "," << b << endl;
            label->setPixmap(icons.at(setup[a][b])); //icons.at(setup[a][b]
            ui->squares->addWidget(label,a,b);


        }
    }

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



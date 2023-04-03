
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
    gameBoard = new Board;
    ui->Start_image->setPixmap(pix);

    //link multiple widgets together for different pages
    stackedWidget = new QStackedWidget(this);
    stackedWidget->addWidget(ui->StartPage);
    stackedWidget->addWidget(ui->Game);

    stackedWidget->setCurrentIndex(0);

    //implementation of buttons
    connect(ui->startButton, SIGNAL(clicked()), this, SLOT(on_startButton_clicked()));
    connect(ui->mainMenuButton, SIGNAL(clicked()), this, SLOT(on_mainMenuButton_clicked()));
    //connect(ui->resetButton, SIGNAL(clicked()), this, SLOT(on_resetButton_clicked()));


    setCentralWidget(stackedWidget);

    //import chess board image
    QPixmap pixmap("../Antichess/images/chess-board-vector_.jpg"); //DOUBLE CHECK THIS STILL WORKS AND THEN UPLOAD .JPG TO GIT REPO


    //create new graphics scene to position the board on the GUI

    Scene = new QGraphicsScene(this);

    ui->squares->setOriginCorner(Qt::BottomLeftCorner);
    Scene->addPixmap(pixmap.scaledToHeight(512));
    ui->boardGraphic->setScene(Scene);
    gameBoard->setBoard("RNBQKBNR/PPPPPPPP/8/8/8/8/pppppppp/rnbqkbnr");
    updateGUI();


    //QLayoutItem *item = ui->gridLayout->itemAtPosition(2,2);

    //std::cout<< item <<std::endl;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::updateGUI(){



    for(int b =0; b<8;b++){ //WHEN FEN NOTATION IS CHANGED TO "rnbqkbnr/pppppppp/8/8/4P3/8/PPP1PPPP/RNBQKBNR" PROGRAM CRASHES

        if(gameBoard->currentFEN[b][0] == '8'){
            continue;
        }
        for(int a =0; a<8;a++){

            //cout<<a<<","<<b<<endl;
            QPushButton *label = new QPushButton;
            label->setFlat(true);
            label->setFixedSize(54,56);
            label->setIconSize(QSize(50,50));
            label->setCheckable(true);
            label->setIcon(gameBoard->icons.at(gameBoard->currentFEN[b][a])); //icons.at(setup[a][b]
            //cout<<"Piece is "<<gameBoard->readFEN(a,b)<<endl;
            connect(label, SIGNAL(toggled(bool)), this, SLOT(keyPressed(bool)));

            ui->squares->addWidget(label,b,a,Qt::AlignCenter);


        }
    }
    cout << "Icons drawn successfully" << endl;

}

void MainWindow::keyPressed(bool checked){ //Possible error here need to investigate
                                           //seems as if all peices are behaving like bishops

    QPushButton* pos = qobject_cast<QPushButton*>(sender());
    cout << gameBoard->currentFEN[pos->x()][pos->y()];
    Points point(pos);

    vector<pair<int,int>> moves = point.getMoves();
    vector<QPushButton*> buttons;

    if(checked){


    for(int a = 0;a<15;a++){
        //cout<<buttons.size()<<endl;

        //setup a new move label
        QPushButton *mLabel = new QPushButton;
        mLabel->setFlat(true);
        mLabel->setFixedSize(54,56);
        mLabel->setIconSize(QSize(50,50));


        buttons.push_back(mLabel);
<<<<<<< Updated upstream
        //cout << "Drawing mLabels @: " << a << "," << b << endl; //b undeclared
=======
        //cout << "\nmoves available @: " << a << "," << a << ". ";
>>>>>>> Stashed changes
        mLabel->setIcon(QPixmap("../Antichess/images/dot2.svg")); //icons.at(setup[a][b]


        //connect(mLabel, SIGNAL(clicked()), this, SLOT(keyPressed(bool)));
        //label->lower();

        //ui->squares->addWidget(mLabel, moves[a].first, moves[a].second, Qt::AlignCenter); //THIS LINE CAUSING THE PROGRAM CRASHES WHEN INVESTIGATED IN THE DEBUGGER


    }
    }

    if(!checked){
    cout << "unchecked " << endl;

        for(int x = 0; x<8 ;x++){




        }


    }

}



void MainWindow::on_startButton_clicked()
{
    //std::cerr << "START GAME PRESSED\n";
    stackedWidget->setCurrentWidget(ui->Game);
}


void MainWindow::on_rulesButton_clicked()
{
    std::cerr << "OPENING RULES\n";
    QDesktopServices::openUrl(QUrl("https://www.antichess.org/antichess-basics/", QUrl::TolerantMode));
}


void MainWindow::on_mainMenuButton_clicked()
{
    //std::cerr << "GOING TO MAIN MENU\n";
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
    gameBoard->resetBoard(reset_flag);

}



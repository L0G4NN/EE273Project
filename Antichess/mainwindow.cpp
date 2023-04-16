/* filename mainwindow.cpp
 * generates the gameplay loop for the Antichess game itself
 * Last updated: [DD:MM:YYYY]
 * Description of latest update:
 *
 *
 */

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
#include "utils/clickableLabels.h"
#include <QtCore>
#include <QDesktopServices>
#include <QPushButton>
#include <QGraphicsRectItem>
#include <QPainter>
#include <QGraphicsScene>
#include <QVBoxLayout>
#include <iostream>
#include <QMouseEvent>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //draw the board onto the screen
    QPixmap pix("../Antichess/images/background.png");
    gameBoard = new Board;
    gameBoard->MoveCounter();
    prev = new QPushButton;
    buttons = new vector<QPushButton*>;
    //pieces = new vector<QPushButton*>;




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
    gameBoard->setBoard("RNBQKBNR/PPPPPPPP/88888888/88888888/88888888/88888888/pppppppp/rnbqkbnr");
    updateGUI();

    //QLayoutItem *item = ui->gridLayout->itemAtPosition(2,2);

    //std::cout<< item <<std::endl;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::updateGUI(){



    gameBoard->MoveCounter(); //update the move counter to increase by 1 every time a move is played to determine whos turn it is

    //update GUI to say whos turn it is
    char turn_char = gameBoard->whosTurn();
    QString labelString = QString("MOVE: %1 TURN: %2").arg(gameBoard->getCount()).arg(turn_char);
    ui->turnLabel->setText(labelString);

    prev = new QPushButton;

    for(auto c: pieces){
        c->deleteLater();


    }

    for(auto c:*buttons){

        c->deleteLater();
        }

    pieces.clear();
    buttons -> clear();

    for(int b =0; b<8;b++){ //WHEN FEN NOTATION IS CHANGED TO "rnbqkbnr/pppppppp/8/8/4P3/8/PPP1PPPP/RNBQKBNR" PROGRAM CRASHES


        for(int a =0; a<8;a++){

            //cout<<a<<","<<b<<endl;
            if(gameBoard->currentFEN[b][a] == '8'){
                continue;
            }
            QPushButton *label = new QPushButton;
            label->setFlat(true);
            label->setFixedSize(54,56);
            label->setIconSize(QSize(50,50));
            label->setCheckable(true);
            label->setIcon(gameBoard->icons.at(gameBoard->currentFEN[b][a])); //icons.at(setup[a][b]
            label->lower();
            //cout<<"Piece is "<<gameBoard->readFEN(a,b)<<endl;
            connect(label, SIGNAL(toggled(bool)), this, SLOT(keyPressed(bool)));


            ui->squares->addWidget(label,b,a,1,1,Qt::AlignCenter);
            pieces.push_back(label);
            cout<<"Size of pieces "<<pieces.size()<<endl;

            //gameBoard->getMoves(label);
        }
    }
    cout << "Icons drawn successfully" << endl;
    for(auto c: gameBoard->currentFEN){
        cout<<c<<endl;
    }


    //cout<<"Number of elements"<<pieces->size()/pieces[0].size()<<endl;




    checkForTake();
    buttons = new vector<QPushButton*>;



}

void MainWindow::checkForTake(){



    for(int b =0; b<8;b++){ //WHEN FEN NOTATION IS CHANGED TO "rnbqkbnr/pppppppp/8/8/4P3/8/PPP1PPPP/RNBQKBNR" PROGRAM CRASHES


        for(int a =0; a<8;a++){

            QMouseEvent amongus = QMouseEvent(QEvent::MouseButtonPress,QPoint(a,b),Qt::LeftButton,Qt::LeftButton,Qt::NoModifier);
            QApplication::sendEvent(ui->squares,&amongus);

            QMouseEvent amongus2 = QMouseEvent(QEvent::MouseButtonRelease,QPoint(a,b),Qt::LeftButton,Qt::LeftButton,Qt::NoModifier);

            if(gameBoard->takePiece){

                cout<<"Attacking piece "<<gameBoard->currentFEN[gameBoard->m_y][gameBoard->m_x]<<endl;
                cout<<"Taking piece "<<gameBoard->currentFEN[gameBoard->takeablePiece.second][gameBoard->takeablePiece.first]<<endl;
                swap(gameBoard->currentFEN[gameBoard->m_y][gameBoard->m_x],gameBoard->currentFEN[gameBoard->takeablePiece.second][gameBoard->takeablePiece.first]);
                gameBoard->takePiece = false;
                updateGUI();

            }


        }
    }


}


void MainWindow::dotPressed(){


    cout<<"dot pressed"<<endl;
    QPushButton* pos = qobject_cast<QPushButton*>(sender());
    cout<<pos->x()<<","<<pos->y();

    cout<<"Point Position is: "<<floor(pos->x()/(pos->width()))<<","<<floor(7-(pos->y()/(pos->height())))<<endl;
    cout<<"Piece position is: "<<floor(prev->x()/prev->width())<<","<<floor(7-(prev->y()/prev->height()))<<endl;
    cout<<gameBoard->currentFEN[floor(7-(prev->y()/prev->height()))][floor(prev->x()/prev->width())]<<endl;
    cout<<gameBoard->currentFEN[floor(7-(pos->y()/(pos->height())))][floor(pos->x()/(pos->width()))]<<endl;

    std::swap(gameBoard->currentFEN[floor(7-(pos->y()/(pos->height())))][floor(pos->x()/(pos->width()))],gameBoard->currentFEN[floor(7-(prev->y()/prev->height()))][floor(prev->x()/prev->width())]);
    cout<<gameBoard->currentFEN[floor(7-(prev->y()/prev->height()))][floor(prev->x()/prev->width())]<<endl;



    gameBoard->takePiece = false;
    updateGUI();




}

void MainWindow::keyPressed(bool checked){ //Possible error here need to investigate
                                           //seems as if all peices are behaving like bishops
    //buttons = new vector<QPushButton*>;

    prev -> setChecked(false);
    QPushButton* pos = qobject_cast<QPushButton*>(sender());
    prev = pos;
    //cout << gameBoard->currentFEN[pos->x()][pos->y()]; //ALSO CAUSING CRASHING SOMETIMES

    cout<<"Current Position"<< floor(pos->x()/pos->width())<<","<<floor(7-(pos->y()/pos->height()))<<endl;


    vector<pair<int,int>> moves = gameBoard->getMoves(pos);


    if(checked){

    //buttons->clear();
    cout<<"Checked"<<endl;
    cout<<"Moves size "<<moves.size()<<endl;


    for(auto b : moves){
        cout<<"Dot pos" <<endl;
        //setup a new move label
        if(b.first == floor(pos->x()/pos->width()) and b.second == floor(7-(pos->y()/pos->height()))){
            cout<<"hit"<<endl;
            continue;
        }

        if(gameBoard->currentFEN[b.second][b.first] != '8'){
            continue;
        }


        QPushButton *mLabel = new QPushButton;
        mLabel->setFlat(true);
        mLabel->setFixedSize(54,56);
        mLabel->setIconSize(QSize(50,50));



        buttons->push_back(mLabel);
        //cout << "Drawing mLabels @: " << a << "," << b << endl; //b undeclared
        //cout << "\nmoves available @: " << a << "," << a << ". ";
        mLabel->setIcon(QPixmap("../Antichess/images/dot2.svg")); //icons.at(setup[a][b]


        connect(mLabel, SIGNAL(clicked()), this, SLOT(dotPressed()));
        mLabel->raise();


        ui->squares->addWidget(mLabel, b.second, b.first, Qt::AlignCenter);

        }

    }

    if(!checked){
    cout << "unchecked " << endl;

    for(auto c:*buttons){

        c->deleteLater();

        }
    buttons->clear();
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

    //check if game is reset or not
    if(gameBoard->isReset() == true){
    gameBoard->setBoard("RNBQKBNR/PPPPPPPP/88888888/88888888/88888888/88888888/pppppppp/rnbqkbnr");

    //Also reset move counters to zero 0
    gameBoard->setCounter(-1); //-1 as updateGUI will increment by 1

    updateGUI(); //call immediate update GUI request

    }
    else {
    ;
    }

}



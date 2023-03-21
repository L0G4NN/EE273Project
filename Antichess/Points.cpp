#include "Points.h"
#include "../../../Antichess/utils/clickablelabels.h"
#include "./ui_mainwindow.h"
#include "Chess/board.h"
#include <QPushButton>
#include <QPoint>


Points::Points(){

}

Points::Points(QPushButton* pos){

    //QPixmap dot("../Antichess/images/dot2.svg");
    //dotLabel = label;

    //cout<<pos->x()<<","<<pos->width()<<endl;

    m_x = floor(pos->x()/pos->width());
    m_y = floor(7-(pos->y()/pos->height())); //translates pixel postion to vector coordinate

    getClickLocation();
    showMoves();


    //std::cout  << "piece selected @ : " << m_x << ", " << m_y << std::endl; //show coordinates where clicked


}


pair<int,int> Points::getClickLocation(){
    //cout << m_x << ", " << m_y << endl;
    return{m_x,m_y};
}


void Points::showMoves(){

    //QPixmap dot("../Antichess/images/dot2.svg");

    //get the current click location and identify what piece is on the board

    //switch case to determine how that piece moves around the board

    char piece_char = 'k'; //rn manually setting the case statments

    //calculate all the available moves for that type of piece
    //filter out which moves are available / unavailable based upon if any other pieces occupy those squares
    //could be done by viewing were they are drawn in mainwindow::updateGUI()
    switch(piece_char) {
            case 'p': //bPawn
                cout << "pPawn\n";
                break;

            case 'P': //wPawn
                cout << "wPawn\n";
                break;

            case 'r': //bRook
                cout << "bRook\n";
                break;

            case 'R': //wRook
                cout << "wRook\n";
                break;

            case 'n': //bKnight
                cout << "bKnight\n";
                break;

            case 'N': //wKnight
                cout << "wKnigth\n";
                break;

            case 'b': //bBishop
                cout << "bBishop\n";
                break;

            case 'B': //wBishop
                cout << "wBishop\n";
                break;

            case 'q': //bQueen
                cout << "bQueen\n";
                break;

            case 'Q': //wQueen
                cout << "wQueen\n";
                break;

            case 'k': //bKing
                cout << "bKing\n";
                break;

            case 'K': //wKnight
                cout << "wKing\n";
                break;

    }



}

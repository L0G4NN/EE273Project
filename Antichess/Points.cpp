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
    m_y = floor(7-(pos->y()/pos->height()));
    //translates pixel postion to vector coordinate

    getClickLocation();
    //showMoves();




    //std::cout  << "piece selected @ : " << m_x << ", " << m_y << std::endl; //show coordinates where clicked


}


pair<int,int> Points::getClickLocation(){
    //cout << m_x << ", " << m_y << endl;
    return{m_x,m_y};
}


vector<pair<int,int>> Points::getMoves(){
    cout<<"Current cord"<<m_x<<","<<m_y<<endl;

    //QPixmap dot("../Antichess/images/dot2.svg");

    //get the current click location and identify what piece is on the board

    //switch case to determine how that piece moves around the board
    cout<<m_x<<","<<m_y<<endl;
    char piece_char = gameBoard->readFEN(m_x,m_y); //rn manually setting the case statments

    //calculate all the available moves for that type of piece
    //filter out which moves are available / unavailable based upon if any other pieces occupy those squares
    //could be done by viewing were they are drawn in mainwindow::updateGUI()
    //I DONT THINK THE ORIGIN IS BOTTOM LEFT ANYMORE- NEED SOME INVESTIGATION
    switch(piece_char) {
            case 'p' : //bPawn
                cerr << "bPawn\n";
                moves.push_back({(m_x)+1,(m_y)+1});

                break;

            case 'P': //wPawn
                cerr << "wPawn\n";
                moves.push_back({(m_x)+1,(m_y)+1});
                break;

            case 'r': //bRook
                cerr << "bRook\n";
                break;

            case 'R': //wRook
                cerr << "wRook\n";
                break;

            case 'n': //bKnight
                cerr << "bKnight\n";
                break;

            case 'N': //wKnight
                cerr << "wKnight\n";
                break;

            case 'b': //bBishop
                cerr << "bBishop\n";
                for (int a = 0; a <=7; a++)
                {


                     moves.push_back({a,a+(m_y-m_x)});
                     moves.push_back({a,(2*m_y) - (a+(m_y-m_x))});

                }
                break;

            case 'B': //wBishop
                cerr << "wBishop\n";
                for (int a = 1; a <=7; a++)
                {


                     moves.push_back({a,a+(m_y-m_x)});
                     moves.push_back({a,(2*m_y) - (a+(m_y-m_x))});

                }

                break;

            case 'q': //bQueen
                cerr << "bQueen\n";
                break;

            case 'Q': //wQueen
                cerr << "wQueen\n";
                break;

            case 'k': //bKing
                cerr << "bKing\n";
                break;

            case 'K': //wKnight
                cerr << "wKing\n";
                break;

    }

    return moves;


}

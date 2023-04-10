#include "board.h"
#include "Pieces.h"
#include "Pieces.h"
#include "King.h"
#include "Queen.h"
#include "Pawn.h"
#include "Bishop.h"
#include "Knight.h"
#include "blank.h"
#include "Rook.h"
#include "../mainwindow.h"
#include "Points.h"

#include "Pieces.h"


/*Each team requires
* 1 king
* 1 queen
* 2 bishop
* 2 knights
* 2 rooks
* 8 pawns
*/

//setup white pieces

/* Draw king @ (0,3)
 * draw queen @ (0,4)
 * draw bishops @ (0,2) & (0,5)
 * draw knights @ (0,1) & (0,6)
 * draw rooks @ (0,0) & (0,7)
 * draw pawns @ (1, full_row)
 */

//setup black pieces

/* Draw king @ (7,3)
 * draw queen @ (7,4)
 * draw bishops @ (7,2) & (7,5)
 * draw knights @ (7,1) & (7,6)
 * draw rooks @ (7,0) & (7,7)
 * draw pawns @ (6, full_row)
 */


Board::Board()
{

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
    Blank blank;

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
        {'8',blank.getIcon()}
    };

}

Board::~Board()
{

}

void Board::setBoard(string FEN )
{
    this->boardVector.resize(this->rows, std::vector<int>(this->cols)); //set an 8x8 2D vector

    //maybe just here to have constructors for each piece and their coords
    //i.e. Rook(0,0)
    //     Knight(1,0)

     //Forsyth Edward Notation: https://www.chessprogramming.org/Forsyth-Edwards_Notation
    std::stringstream startBoard(FEN);
    currentFEN = setFEN(startBoard);


}


bool Board::resetBoard(bool reset_flag)
{
    if (reset_flag == true)
    {
        //reset the game
        std::cerr << "Resetting game!\n";
        //Board::setBoard(); //currently causes crashes when enabled
        //Board.setFEN(this->defaultBoard);

        return true;

    }
    else
    {
        std::cerr << "An error occured resetting the board\n";
        return false;
    }
}

vector<std::string> Board::setFEN(stringstream& setup){

    vector<string> boardSetup;

    while(setup.good()){
        string temp;
        getline(setup,temp,'/');
        boardSetup.push_back(temp);

    }
    return boardSetup;

}


//vector<pair<int,int>> Board::showMoves(){

//}

char Board::readFEN(int x, int y) {
    char piece_char;
    piece_char = currentFEN[y][x];
    //cerr<<piece_char<<endl;
    //Take the location to be read
    //cout<<piece_char<<endl;
    //return char

    return piece_char;

}

vector<pair<int,int>> Board::getMoves(QPushButton* pos){

    moves.clear();
    int m_x = floor(pos->x()/pos->width());
    int m_y = floor(7-(pos->y()/pos->height()));

    int x = 0;
    cout << "Current cord: " << m_x << "," << m_y << endl; //get current piece location
    for(auto c: this->currentFEN){
        cout<<c<<endl;
    }

    //QPixmap dot("../Antichess/images/dot2.svg");

    //get the current click location and identify what piece is on the board

    //switch case to determine how that piece moves around the board
    //cout<<m_x<<","<<m_y<<endl;
    char piece_char = this->readFEN(m_x,m_y);
    cout<<"Piece is"<<piece_char<<endl;//rn manually setting the case statments

    //calculate all the available moves for that type of piece
    //filter out which moves are available / unavailable based upon if any other pieces occupy those squares
    //could be done by viewing were they are drawn in mainwindow::updateGUI()
    //I DONT THINK THE ORIGIN IS BOTTOM LEFT ANYMORE- NEED SOME INVESTIGATION

    switch(piece_char) {
            case 'p' : //bPawn
                //cerr << "available move drawn at: " << m_x - 1 << " ," << m_y - 1 << endl;
                    moves.push_back({(m_x),(m_y)-1});
                    cout<<"pawn selected"<<endl;//default movement

                break;

            case 'P': //wPawn
                cerr << "wPawn\n";
                cout<<"pawn selected"<<endl;

                    moves.push_back({(m_x),(m_y)+1}); //default movement

                break;


            case 'r': //bRook
                cerr << "bRook\n";

                for(int a = 0; a<= 7; a++){
                    moves.push_back({m_x,abs(a)});
                    moves.push_back({a,abs(m_y)});
                }
                break;

            case 'R': //wRook
                cerr << "wRook\n";

                for(int a = 0; a<= 7; a++){
                    moves.push_back({m_x,abs(a)});
                    moves.push_back({a,abs(m_y)});
                }
                break;

            case 'n': //bKnight
                cerr << "bKnight\n";
                moves.push_back({m_x+1,m_y+2});
                moves.push_back({m_x+2,m_y+1});

                moves.push_back({m_x+1,abs(m_y-2)});
                moves.push_back({m_x+2,abs(m_y-1)});

                moves.push_back({abs(m_x-1),m_y+2});
                moves.push_back({abs(m_x-2),m_y+1});

                moves.push_back({abs(m_x-1),abs(m_y-2)});
                moves.push_back({abs(m_x-2),abs(m_y-1)});

                for(auto a : moves){
                    //cout<<a.first<<","<<a.second<<endl;
                }
                break;

            case 'N': //wKnight
                cerr << "wKnight\n";
                moves.push_back({m_x+1,m_y+2});
                moves.push_back({m_x+2,m_y+1});

                moves.push_back({(m_x-1),m_y+2});
                moves.push_back({(m_x-2),m_y+1});

                moves.push_back({m_x+1,(m_y-2)});
                moves.push_back({m_x+2,(m_y-1)});

                moves.push_back({(m_x-1),(m_y-2)});
                moves.push_back({(m_x-2),(m_y-1)});
                break;

            case 'b': //bBishop
                cerr << "bBishop\n";
                for (int a = 0; a <=7; a++)
                {
                     moves.push_back({a,(a+(m_y-m_x))});
                     moves.push_back({a,((2*m_y) - (a+(m_y-m_x)))});
                }
                break;

            case 'B': //wBishop
                cerr << "wBishop\n";
                for (int a = m_x; a <=7; a++)
                {
                     moves.push_back({a,(m_y+(a-m_x))});
                     moves.push_back({a,(m_y-(a-m_x))});

                }

                for (int a = m_x; a >=0; a--)
                {
                     moves.push_back({a,(m_y+(m_x-a))});
                     moves.push_back({a,(m_y-(m_x-a))});

                }

                break;

            case 'q': //bQueen
                cerr << "bQueen\n";
                for(int a = 0; a<= 7; a++){
                    moves.push_back({m_x,abs(a)});
                    moves.push_back({a,(m_y)});
                    moves.push_back({a,(a+(m_y-m_x))});
                    moves.push_back({a,((2*m_y) - (a+(m_y-m_x)))});
                }
                break;

            case 'Q': //wQueen
                cerr << "wQueen\n";
                for(int a = 0; a<= 7; a++){
                    moves.push_back({m_x,(a)});
                    moves.push_back({a,(m_y)});
                    moves.push_back({a,(a+(m_y-m_x))});
                    moves.push_back({a,((2*m_y) - (a+(m_y-m_x)))});
                }
                break;

            case 'k': //bKing
                cerr << "bKing\n";
                moves.push_back({m_x,m_y+1});
                moves.push_back({m_x,m_y-1});

                moves.push_back({m_x+1,m_y});
                moves.push_back({m_x-1,m_y});

                moves.push_back({m_x+1,m_y+1});
                moves.push_back({m_x+1,m_y-1});

                moves.push_back({m_x-1,m_y+1});
                moves.push_back({m_x-1,m_y-1});


                break;

            case 'K': //wKing
                cerr << "wKing\n";
                moves.push_back({m_x,m_y+1});
                moves.push_back({m_x,m_y-1});

                moves.push_back({m_x+1,m_y});
                moves.push_back({m_x-1,m_y});

                moves.push_back({m_x+1,m_y+1});
                moves.push_back({m_x+1,m_y-1});

                moves.push_back({m_x-1,m_y+1});
                moves.push_back({m_x-1,m_y-1});

                break;

    }



    it = unique(moves.begin(),moves.end());
    moves.resize(distance(moves.begin(),it));

    newit = remove_if(moves.begin(),moves.end(),[](pair<int,int> b){return (b.first > 7 or b.second > 7 or b.first <0 or b.second <0);});
    moves.resize(distance(moves.begin(),newit));
    for(auto c: moves){
        cout<<c.first<<","<<c.second<<endl;

    }




    return moves;


}

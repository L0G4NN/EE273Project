
#include "board.h"
#include "move.h"
#include <sstream>
#include <iostream>

Board::Board()
{

}

Board::~Board()
{

}

void Board::setBoard()
{
    this->boardVector.resize(this->rows, std::vector<int>(this->cols)); //set an 8x8 2D vector



    //maybe just here to have constructors for each piece and their coords
    //i.e. Rook(0,0)
    //     Knight(1,0)

    //BLACK
    vector<Pawn> bPawns;
    King bKing('b');
    Queen bQueen('b');

    Bishop bBishop1('b');
    Bishop bBishop2('b');

    Knight bKnight1('b');
    Knight bKnight2('b');

    Rook bRook1('b');
    Rook bRook2('b');

    for(int x = 0;x<8;x++){
        Pawn bPawn('w');
        bPawns.push_back(bPawn);
    }    for(int x = 0;x<8;x++){
        Pawn bPawn('w');
        bPawns.push_back(bPawn);
    }

    //WHITE
    vector<Pawn> wPawns;

    King wKing('w');
    Queen wQueen('w');

    Bishop wBishop1('w');
    Bishop wBishop2('w');

    Knight wKnight1('w');
    Knight wKnight2('w');

    Rook wRook1('w');
    Rook wRook2('w');

    for(int x = 0;x<8;x++){
        Pawn wPawn('w');
        wPawns.push_back(wPawn);
    }

     //Forsyth Edward Notation: https://www.chessprogramming.org/Forsyth-Edwards_Notation
    std::stringstream startBoard("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR");
    setFEN(startBoard);

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
}

bool Board::resetBoard()
{
    bool reset_flag = false;
    /*if button is pressed
     * {
     * Board::setBoard();
     * }
     */

    return false;
}

void Board::setFEN(stringstream& setup){

    vector<string> boardSetup;

    while(setup.good()){
        string temp;
        getline(setup,temp,'/');
        boardSetup.push_back(temp);

    }


}

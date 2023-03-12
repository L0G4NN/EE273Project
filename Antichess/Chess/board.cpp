#include "board.h"
#include "Pieces.h"
#include "../mainwindow.h"

Board::Board()
{

}

Board::~Board()
{

}

vector<string> Board::setBoard()
{
    this->boardVector.resize(this->rows, std::vector<int>(this->cols)); //set an 8x8 2D vector

    //maybe just here to have constructors for each piece and their coords
    //i.e. Rook(0,0)
    //     Knight(1,0)


     //Forsyth Edward Notation: https://www.chessprogramming.org/Forsyth-Edwards_Notation
    std::stringstream startBoard("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR");
    vector<string> init = setFEN(startBoard);

    return init;
}

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



#include "King.h"
#include <vector>
#include <QString>
#include <sstream>
#include <iostream>
#include <map>
#include "Pieces.h"
#include "King.h"
#include "Queen.h"
#include "Pawn.h"
#include "Bishop.h"
#include "Knight.h"
#include "Rook.h"
#include <vector>
#pragma once

class Board {


public:
    Board();
    ~Board();

    std::vector<std::string> setBoard(string FEN); //uknown args atm
    bool isSetup();
    bool resetBoard(bool reset_flag);
    std::vector<std::string> setFEN(std::stringstream& setup);
    void readFEN();
    vector<pair<int,int>> showMoves();
    map<char,QPixmap> icons;



    /*possible funcs
     * bool isNewGame();
     * bool or int playerTurn();
     */

    bool isOccupied(int x, int y);

private:

    int rows = 8; //chess board is 8x8 size
    int cols = 8;

    std::vector<std::vector<int>> boardVector;
protected:
    vector<string> board;




    //std::stringstream startBoard("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR");
};


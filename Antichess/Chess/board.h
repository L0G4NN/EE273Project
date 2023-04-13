

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
#include <QPushButton>
#pragma once

class Board {


public:
    Board();
    ~Board();

    void setBoard(string FEN); //uknown args atm
    bool isSetup();

    bool resetBoard(bool reset_flag);
    bool isReset();

    std::vector<std::string> setFEN(std::stringstream& setup);
    char readFEN(int x, int y);
    vector<pair<int,int>> showMoves();
    vector<pair<int,int>> getMoves(QPushButton* pos);
    map<char,QPixmap> icons;
    vector<string> currentFEN;



    /*possible funcs
     * bool isNewGame();
     * bool or int playerTurn();
     */

    bool isOccupied(int x, int y);
    char whosTurn();
    void setCounter(int counter);
    int MoveCounter();
    int getCount();
    bool takePiece;
    pair<int,int> takeablePiece;

private:

    string defaultBoard = "RNBQKBNR/PPPPPPPP/88888888/88888888/88888888/88888888/pppppppp/rnbqkbnr";

    int rows = 8; //chess board is 8x8 size
    int cols = 8;
    vector<pair<int,int>> moves;

    std::vector<std::vector<int>> boardVector;
    vector<pair<int,int>>::iterator it,newit;

    int countMoves{-2}; //init to -2 so game starts at 0 after updateGUI() has initialised the board
    char playTurn = 'w'; //white always starts first

protected:

    bool reset_flag{false};

};


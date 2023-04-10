

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
    char whosTurn(char playTurn);
    int MoveCounter();

private:

    int rows = 8; //chess board is 8x8 size
    int cols = 8;
    vector<pair<int,int>> moves;

    std::vector<std::vector<int>> boardVector;
    vector<pair<int,int>>::iterator it,newit;
protected:
    char playTurn = 'w'; //white always starts first
    int countMoves{-1}; //init to -1 so game starts at 0 after first pass of updateGUI()





    //std::stringstream startBoard("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR");
};


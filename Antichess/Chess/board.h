

#include "Points.h"
#include <vector>
#include <QString>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>
#pragma once

class Board: public Points
{
public:
    Board();
    ~Board();
    std::vector<std::string> setBoard(); //uknown args atm
    bool isSetup();
    bool resetBoard(bool reset_flag);
    std::vector<std::string> setFEN(std::stringstream& setup);
    void readFEN();

    /*possible funcs
     * bool isNewGame();
     * bool or int playerTurn();
     */

    bool isOccupied(int x, int y);

private:
    int rows = 8; //chess board is 8x8 size
    int cols = 8;
    std::vector<std::vector<int>> boardVector;
    //std::stringstream startBoard("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR");
};


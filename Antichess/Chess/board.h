#pragma once
#include <vector>
#include <QString>
#include <sstream>

class Board
{
public:
    Board();
    ~Board();
    void setBoard(); //uknown args atm
    bool isSetup();
    bool resetBoard();
    void setFEN(std::stringstream& setup);
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
};


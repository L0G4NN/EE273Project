#pragma once
#include <vector>

class Board
{
public:
    Board();
    ~Board();
    void setBoard(); //uknown args atm
    bool isSetup();
    bool resetBoard();

    /*possible funcs
     * bool isNewGame();
     * bool or int playerTurn();
     */
    bool isOccupied(int x, int y);

private:
    int size = 8; //chess board is 8x8 size
    std::vector<std::vector<int>> boardVector;
};


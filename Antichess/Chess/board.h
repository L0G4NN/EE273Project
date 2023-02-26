#pragma once

class Board
{
public:
    Board();
    ~Board();
    void setBoard(); //uknown args atm
    /*possible funcs
     * bool isSetup();
     * bool resetBoard();
     * bool isNewGame();
     */

private:
    int size = 8; //chess board is 8x8 size
};

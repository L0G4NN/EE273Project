#include <vector>
#include <QString>
#include <sstream>
#include <iostream>
#include <map>
#include <string>
#include <QPixmap>
#include <vector>
#pragma once

using namespace std;
class Board {


public:
    Board();
    ~Board();

    void setBoard(string FEN); //uknown args atm
    bool resetBoard(bool reset_flag);
    std::vector<std::string> setFEN(std::stringstream& setup);
    char readFEN(int x, int y);
    vector<pair<int,int>> showMoves();
    map<char,QPixmap> icons;
    vector<string> currentFEN;

    char whosTurn(char playTurn);
    int MoveCounter();

private:

    int rows = 8; //chess board is 8x8 size
    int cols = 8;

    std::vector<std::vector<int>> boardVector;

    char playTurn = 'w'; //white always starts first
    int countMoves{-1}; //init to -1 so game starts at 0 after first pass of updateGUI()

protected:
    //std::stringstream startBoard("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR");
};



/* move.h
 * Antichess
 * Elias and Logan
 * Logic for the pieces to move around the board
 *
 * Pawn
 * Knight
 * Rook
 * Bishop
 * King
 * Queen
*/

//SVG image set for pieces - CBurnett chess pieces - https://commons.wikimedia.org/wiki/Category:SVG_chess_pieces

#pragma once
#include <vector>
#include <QPixmap>
using namespace std;

class Pieces {

public:
    Pieces();
    ~Pieces();

    Pieces(char colour,int x, int y);

    bool isActive(); //true if player has piece selected

    vector<pair<int,int>> getMoves(Pieces piece);
    vector<int> getCords();
    vector<int> getTakes(); // return a vector of all coordinates that the opponent could lose their piece in the next move
    void setCords(int x, int y); //for initial game setup
    void setIcon(QString address);
    QPixmap getIcon();

    void move();
    void show_moves(); //had a build issue with virtual func - removed temp
    void take_piece();

private:
    QPixmap icon;
    int x;
    int y;

};

class Pawn : public Pieces
{
public:
    Pawn(char colour);


    void show_moves();

private:
    QPixmap icon;
};



class Knight : public Pieces
{
public:

    Knight(char colour);


    void show_moves();
private:
    QPixmap icon;
};



class Rook : public Pieces
{
public:

    Rook(char colour);


    void show_moves();

private:
    QPixmap icon;
};



class Bishop : public Pieces
{
public:

    Bishop(char colour);


    void show_moves();
private:
    QPixmap icon;
};



class King : public Pieces
{
public:

    King(char colour);


    void show_moves();

private:
    QPixmap icon;
};



class Queen : public Pieces
{
public:

    Queen(char colour);


    void show_moves();

private:
    QPixmap icon;
};

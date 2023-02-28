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

#pragma once
#include <vector>
//<<<<<<< Updated upstream
//=======
using namespace std;
//>>>>>>> Stashed changes

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

    void move();
    void show_moves(); //had a build issue with virtual func - removed temp
    void take_piece();

private:
    int x;
    int y;

};

class Pawn : public Pieces
{
public:
    Pawn();
    ~Pawn();
    void show_moves();
private:
};

class Knight : public Pieces
{
public:
    Knight();
    ~Knight();
    void show_moves();
private:
};

class Rook : public Pieces
{
public:
    Rook();
    ~Rook();
    void show_moves();

private:
};

class Bishop : public Pieces
{
public:
    Bishop();
    ~Bishop();
    void show_moves();
private:
};

class King : public Pieces
{
public:
    King();
    ~King();
    void show_moves();

private:
};

class Queen : public Pieces
{
public:
    Queen();
    ~Queen();
    void show_moves();

private:
};


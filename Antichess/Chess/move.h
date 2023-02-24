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

class Pieces {
public:
    Pieces();
    ~Pieces();

    Pieces(int x, int y);

    int getCords(int x, int y);
    void setCords(int x, int y); //for initial game setup

    void move();
    bool check_move();
    void take_piece();

private:
    int x;
    int y;

};

class Pawn : public Pieces
{
public:
private:
};

class Knight : public Pieces
{
public:
private:
};

class Rook : public Pieces
{
public:
private:
};

class Bishop : public Pieces
{
public:
private:
};

class King : public Pieces
{
public:
private:
};

class Queen : public Pieces
{
public:
private:
};


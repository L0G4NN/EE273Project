#ifndef BISHOP_H
#define BISHOP_H
#include "Pieces.h"
#pragma once
#endif // BISHOP_H

class Bishop : public Pieces
{
public:

    Bishop(char colour);


    void show_moves();

private:
    QPixmap icon;
};

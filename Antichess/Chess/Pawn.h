#ifndef PAWN_H
#define PAWN_H
#include "Pieces.h"
#pragma once
#endif // PAWN_H


class Pawn : public Pieces
{
public:
    Pawn(char colour);

    void show_moves();

private:
    QPixmap icon;
};

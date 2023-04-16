/* filename Knight.h
 * [Description]
 * Last updated: [DD:MM:YYYY]
 * Description of latest update:
 *
 *
 */

#ifndef KNIGHT_H
#define KNIGHT_H
#include "Pieces.h"
#pragma once
#endif // KNIGHT_H


class Knight : public Pieces
{
public:

    Knight(char colour);


    void show_moves();
private:
    QPixmap icon;
};

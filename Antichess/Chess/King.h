/* filename King.h
 * [Description]
 * Last updated: [DD:MM:YYYY]
 * Description of latest update:
 *
 *
 */

#ifndef KING_H
#define KING_H
#include "Pieces.h"
#pragma once
#endif // KING_H



class King : public Pieces
{
public:

    King(char colour);


    void show_moves();

private:
    QPixmap icon;
};

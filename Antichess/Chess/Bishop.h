/* filename Bishop.h
 * [Description]
 * Last updated: [DD:MM:YYYY]
 * Description of latest update:
 *
 *
 */

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

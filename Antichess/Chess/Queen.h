/* filename Queen.h
 * [Description]
 * Last updated: [DD:MM:YYYY]
 * Description of latest update:
 *
 *
 */

#ifndef QUEEN_H
#define QUEEN_H
#include "Pieces.h"
#pragma once

#endif // QUEEN_H

class Queen : public Pieces
{
public:

    Queen(char colour);


    void show_moves();

private:
    QPixmap icon;
};

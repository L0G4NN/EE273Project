/* filename Rook.h
 * [Description]
 * Last updated: [DD:MM:YYYY]
 * Description of latest update:
 *
 *
 */

#ifndef ROOK_H
#define ROOK_H
#include "Pieces.h"
#pragma once

#endif // ROOK_H

class Rook : public Pieces
{
public:

    Rook(char colour);


    void show_moves();

private:
    QPixmap icon;
};

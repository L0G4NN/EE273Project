/* filename Knight.cpp
 * [Description]
 * Last updated: [DD:MM:YYYY]
 * Description of latest update:
 *
 *
 */

#include "Knight.h"

Knight::Knight(char colour){

    switch(colour){

        case('b'):
           setIcon("../Antichess/images/Pieces/knight_b.svg");
        break;

        case('w'):
           setIcon("../Antichess/images/Pieces/knight_w.svg");
        break;
    }

}

void Knight::show_moves(){

}


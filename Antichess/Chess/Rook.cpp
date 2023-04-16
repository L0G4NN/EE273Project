/* filename Rook.cpp
 * [Description]
 * Last updated: [DD:MM:YYYY]
 * Description of latest update:
 *
 *
 */

#include "Rook.h"

Rook::Rook(char colour){

    switch(colour){

        case('b'):
           setIcon("../Antichess/images/Pieces/rook_b.svg");
        break;

        case('w'):
           setIcon("../Antichess/images/Pieces/rook_w.svg");
        break;
    }

}

void Rook::show_moves(){

    vector<pair<int,int>> moves;
    int x = this->getCords()[0];
    int y = this->getCords()[1];

    for (int a = 0; a <=7; a++)
    {
        moves.push_back({x,a});
        moves.push_back({a,y});
    }

}

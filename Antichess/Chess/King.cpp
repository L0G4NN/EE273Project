/* filename King.cpp
 * [Description]
 * Last updated: [DD:MM:YYYY]
 * Description of latest update:
 *
 *
 */

#include "King.h"

King::King(char colour){

    switch(colour){

        case('b'):
           setIcon("../Antichess/images/Pieces/king_b.svg");
        break;

        case('w'):
           setIcon("../Antichess/images/Pieces/king_w.svg");
        break;
    }

}


void King::show_moves(){

    vector<pair<int,int>> moves;

    int x = this->getCords()[0];
    int y = this->getCords()[1];

    for (int a = x-1; a <=x+1; a++)
    {
        moves.push_back({a,a+(y-x)});
        moves.push_back({a,(2*y) - a+(y-x)});
    }

}

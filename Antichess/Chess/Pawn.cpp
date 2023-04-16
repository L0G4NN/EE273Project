/* filename Pawn.cpp
 * [Description]
 * Last updated: [DD:MM:YYYY]
 * Description of latest update:
 *
 *
 */

#include "Pawn.h"
#include <iostream>
using namespace std;
Pawn::Pawn(char colour){

    switch(colour){

        case('b'):
           setIcon("../Antichess/images/Pieces/pawn_b.svg");
        break;

        case('w'):
            setIcon("../Antichess/images/Pieces/pawn_w.svg");
        break;


    }

}

void Pawn::show_moves(){

    vector<pair<int,int>> moves;
    int x = this->getCords()[0];
    int y = this->getCords()[1];

}


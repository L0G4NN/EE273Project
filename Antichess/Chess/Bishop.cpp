#include "Bishop.h"

Bishop::Bishop(char colour){

    switch(colour){

        case('b'):
           setIcon("../Antichess/images/Pieces/bishop_b.svg");
        break;

        case('w'):
           setIcon("../Antichess/images/Pieces/bishop_w.svg");
        break;
    }

}

void Bishop::show_moves(){

    vector<pair<int,int>> moves;
    int count;
    int x = this->getCords()[0];
    int y = this->getCords()[1];

    for (int a = 0; a <=7; a++)
    {

         moves.push_back({a,a+(y-x)});
         moves.push_back({a,(2*y) - (a+(y-x))});

    }


}

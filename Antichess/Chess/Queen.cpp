#include "Queen.h"

Queen::Queen(char colour){

    switch(colour){

        case('b'):
           setIcon("../Antichess/images/Pieces/queen_b.svg");
        break;

        case('w'):
           setIcon("../Antichess/images/Pieces/queen_w.svg");
        break;
    }

}

void Queen::show_moves(){

    vector<pair<int,int>> moves;
    int b;
    int c;

    int x = this->getCords()[0];
    int y = this->getCords()[1];



   for(int a = 0; a<=7 ;a++)
   {
       b = (2*y) - (a+(y-x));
       c = a+(y-x);

       moves.push_back({x,a});
       moves.push_back({a,y});

       moves.push_back({a,c});
       moves.push_back({a,b});
   }
}

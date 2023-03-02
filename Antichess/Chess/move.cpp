#include <iostream>
#include "move.h"
#include "board.h"


Pieces::Pieces(char colour, int x, int y)
{
    this->x = x;
    this->y = y;
}

Pieces::~Pieces()
{

}

void Pieces::setCords(int x, int y)
{
    this->x = x;
    this->y = y;
}

vector<int> Pieces::getCords()
{
    std::cout << "x: " << this->x << std::endl;
    std::cout << "y: " << this->y << std::endl;
    vector<int> cords;

    return cords; //return type should perhaps be a vector to express x and y cords
}

void Pawn::show_moves(){

    vector<pair<int,int>> moves;
    int x = this->getCords()[0];
    int y = this->getCords()[1];   

}



void Knight::show_moves(){

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

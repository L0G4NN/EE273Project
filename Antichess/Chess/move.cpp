#include <iostream>
#include "move.h"

Pieces::Pieces(int x, int y)
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

int Pieces::getCords(int x, int y)
{
    std::cout << "x: " << this->x << std::endl;
    std::cout << "y: " << this->y << std::endl;

    return x; //return type should perhaps be a vector to express x and y cords
}


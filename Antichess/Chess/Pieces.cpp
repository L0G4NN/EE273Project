/* filename Pieces.cpp
 * Last updated: [17:04:2023]
 * Description of latest update:
 *
 *  Removed unused variables - code cleanup
 */

#include <iostream>
#include "Pieces.h"

Pieces::Pieces(){

}


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

void Pieces::setIcon(QString address){
    this->icon = address;
}

QPixmap Pieces::getIcon(){
    return this->icon;
}



/* filename clickablelabels.cpp
 * [Description]
 * Last updated: [DD:MM:YYYY]
 * Description of latest update:
 *
 *
 */

#include "clickableLabels.h"
#include "../mainwindow.h"
#include "../../../Antichess/Chess/Pieces.h"
#include "QAbstractButton.h"
#include <QDialog>
#include <QPoint>
#include <vector>

using namespace std;


clickablelabels::clickablelabels(QWidget *parent)
    : QLabel{parent}
{

}


void clickablelabels::mousePressEvent(QMouseEvent *event)
{
    clickCount +=1;
    //emit mouse_pressed();

    std::cerr << "LABEL CLICKED " << " ";
    //this->setStyleSheet("background-color: rgb(85, 170, 255)");

    std::cerr << clickCount << std::endl;
    if(clickCount == 2){
        this->setStyleSheet("background-color: rgb(0,0,0,0)");
        clickCount = 0;}
}



//POSSIBLY REDUNDANT FUNCTION -- DOES NOT WORK AS EXPECTED, WORKS AS EXPECTED IN POINT.CPP
//pair<int,int> clickablelabels::getClickLocation(QPoint Point){

//    pair<int,int> position{};
//    int x = Point.x()/this->width();
//    int y = 7-((Point.y())/this->height());
//    std::cout << "pointing @: " << x << ", " << y << std::endl; //X AND Y ARE ALWAYS SET TO 0,7 NO MATTER WHERE ON THE SCREEN IS CLICKED

//    return {x,y};

//}


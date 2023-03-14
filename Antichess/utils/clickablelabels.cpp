#include "clickableLabels.h"
#include "C:\Users\Elias\Documents\UNI\Year 2\EE273\Semester 2\GroupProject\EE273Project\Antichess\Chess\Points.h"
#include "../mainwindow.h"
#include "C:\Users\Elias\Documents\UNI\Year 2\EE273\Semester 2\GroupProject\EE273Project\Antichess\Chess\Pieces.h"
#include <QDialog>
#include <QPoint>
#include <vector>

using namespace std;


clickablelabels::clickablelabels(QWidget *parent)
    : QLabel{parent}
{

}

//STILL SOME VERY WEIRD BUGS GOING ON HERE WHERE ONLY CERTAIN LABELS NEAR THE FIRST CLICKED LABELS WORK

void clickablelabels::mousePressEvent(QMouseEvent *event)
{

    emit mouse_pressed();
    std::cerr << "LABEL CLICKED " << " ";
    this->setStyleSheet("background-color: rgb(85, 170, 255)");
    clickCount +=1;
    std::cerr << clickCount << std::endl;
    if(clickCount == 2){
        this->setStyleSheet("background-color: rgb(0,0,0,0)");
        clickCount = 0;}

    Points point(this);
    this->getClickLocation(point);


}

pair<int,int> clickablelabels::getClickLocation(QPoint Point){

    pair<int,int> position{};
    int x = Point.x()/this->width();
    int y = 7-((Point.y())/this->height());

     cout<<x<<endl;
    return {x,y};
}


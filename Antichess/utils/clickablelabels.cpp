#include "clickableLabels.h"
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

    QPoint point;
    point = this->pos();
    this->getClickLocation(point);

}

vector<pair<int,int>> clickablelabels::getClickLocation(QPoint Point){

    vector<pair<int,int>> position{};
    position.push_back({Point.x(),Point.y()});
    cout<<ceil(Point.x()/this->width())<<","<<7-((Point.y())/this->height())<<endl;

    return position;
}


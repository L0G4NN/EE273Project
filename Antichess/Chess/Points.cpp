#include "Points.h"
#include "C:\Users\Elias\Documents\UNI\Year 2\EE273\Semester 2\GroupProject\EE273Project\Antichess\utils\clickableLabels.h"
#include <QPoint>


Points::Points(){

}
Points::Points(clickablelabels* label){

    QPoint point = label->pos();
    x = point.x()/label->width();
    y = 7-(point.y()/label->height());


}



pair<int,int> Points::getClickLocation(){
    return{x,y};

}

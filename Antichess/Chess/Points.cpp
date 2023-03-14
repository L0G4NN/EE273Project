#include "Points.h"
#include "../../../Antichess/utils/clickablelabels.h"
#include <QPoint>


Points::Points(){

}
Points::Points(clickablelabels* label){

    QPoint point = label->pos();
    x = point.x()/label->width();
    y = 7-(point.y()/label->height());

    std::cout  << "piece selected @ : " << x << ", " << y << std::endl; //show coordinates where clicked


}



pair<int,int> Points::getClickLocation(){
    return{x,y};

}

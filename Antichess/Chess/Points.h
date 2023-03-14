#ifndef POINTS_H
#define POINTS_H

#include <QPoint>
#include "C:\Users\Elias\Documents\UNI\Year 2\EE273\Semester 2\GroupProject\EE273Project\Antichess\utils\clickableLabels.h"
#endif // POINTS_H
#pragma once


class Points: public QPoint {


public:
    Points();
    Points(clickablelabels* label);
    pair<int,int> getClickLocation();

private:

    int x;
    int y;
};

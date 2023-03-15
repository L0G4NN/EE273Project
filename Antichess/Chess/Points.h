#ifndef POINTS_H
#define POINTS_H

#include <QPoint>
#include "../../../Antichess/utils/clickablelabels.h"
#endif // POINTS_H
#pragma once


class Points: public QPoint {


public:
    Points();
    Points(clickablelabels* label);
    pair<int,int> getClickLocation();

private:
    vector<pair<int,int>>moves;
    int x;
    int y;
};

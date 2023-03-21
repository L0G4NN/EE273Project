#ifndef POINTS_H
#define POINTS_H

#include <QPoint>
#include "../../../Antichess/utils/clickablelabels.h"
#include "../mainwindow.h"
#include "board.h"

#endif // POINTS_H
#pragma once


class Points: public QPoint, public Board, public clickablelabels, public MainWindow {


public:
    Points();
    Points(clickablelabels* label);
    pair<int,int> getClickLocation();
    void showMoves();

private:
    vector<pair<int,int>>moves;
    int x;
    int y;
};

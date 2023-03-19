#ifndef POINTS_H
#define POINTS_H

#include <QPoint>
#include "../../../Antichess/utils/clickablelabels.h"
#include "C:\Users\Elias\Documents\UNI\Year 2\EE273\Semester 2\GroupProject\EE273Project\Antichess\mainwindow.h"
#include "Chess/board.h"

#endif // POINTS_H
#pragma once


class Points: public QPoint, public Board, public clickablelabels, public MainWindow {


public:
    Points();
    Points(clickablelabels* label);
    pair<int,int> getClickLocation();
    void showMoves();

private:
    vector<pair<int,int>>m_moves;
    clickablelabels* dotLabel;
    int m_x;
    int m_y;


};

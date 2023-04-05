#ifndef POINTS_H
#define POINTS_H

#include <QPoint>
#include "../../../Antichess/utils/clickablelabels.h"
#include "mainwindow.h"
#include "Chess/board.h"
#include <qabstractbutton.h>
#include <QPushButton>

#endif // POINTS_H
#pragma once

class Points: public QPoint, public Board, public MainWindow, public QPushButton{


public:
    Points();
    Points(QPushButton* pos);
    pair<int,int> getClickLocation();
    vector<pair<int,int>> getMoves();

private slots:
    void onClick();


private:
    vector<pair<int,int>>m_moves;
    clickablelabels* dotLabel;
    int m_x;
    int m_y;
    bool clicked;
    vector<pair<int,int>> moves;

    vector<pair<int,int>>::iterator it;




};

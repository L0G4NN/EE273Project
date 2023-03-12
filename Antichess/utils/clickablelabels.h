#ifndef CLICKABLELABELS_H
#define CLICKABLELABELS_H

#include <QLabel>
#include <QMouseEvent>
#include <iostream>
#pragma once
/*
 *  -- TURNING QLABELS INTO CLICKABLE LABEL TYPES --
 *  CREATE THE CLICKABLELABELS CLASS INHERTITED FROM QLABEL
 *  PROMOTE EACH QLABEL IN THE GRID TO A CLIKCABLE LABEL TYPE -- ui_mainwindow.h
*/

//to include in ui_mainwindow.h -- #include "../../../Antichess/utils/clickablelabels.h"

class clickablelabels : public QLabel
{
    Q_OBJECT
public:
    explicit clickablelabels(QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent *event);

signals:
    void mouse_pressed();
    void mouse_pos(); //unsure if needed yet

private:
    int clickCount;

};

#endif // CLICKABLELABELS_H

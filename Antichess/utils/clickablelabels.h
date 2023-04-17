/* filename clickablelabels.h
 * changes the QLabels on the game board to be clickable by the user.
 * Last updated: [17:04:2023]
 * Description of latest update:
 * Removed unused functions for code cleanup.
 *
 */

#ifndef CLICKABLELABELS_H
#define CLICKABLELABELS_H

#include <QLabel>
#include <QMouseEvent>
#include <iostream>
#include <QPoint>
#include <vector>
#pragma once


using namespace std;
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

private:
    int clickCount{0};

};

#endif // CLICKABLELABELS_H

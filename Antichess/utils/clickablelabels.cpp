#include "clickablelabels.h"
#include "../mainwindow.h"
#include <QDialog>


clickablelabels::clickablelabels(QWidget *parent)
    : QWidget{parent}
{

}

//STILL SOME VERY WEIRD BUGS GOING ON HERE WHERE ONLY CERTAIN LABELS NEAR THE FIRST CLICKED LABELS WORK

void clickablelabels::mousePressEvent(QMouseEvent *event)
{
    emit mouse_pressed();
    std::cerr << "LABEL CLICKED " << std::endl;

}

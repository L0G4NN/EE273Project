#include "clickableLabels.h"
#include "../mainwindow.h"
#include <QDialog>


clickablelabels::clickablelabels(QWidget *parent)
    : QLabel{parent}
{

}

//STILL SOME VERY WEIRD BUGS GOING ON HERE WHERE ONLY CERTAIN LABELS NEAR THE FIRST CLICKED LABELS WORK

void clickablelabels::mousePressEvent(QMouseEvent *event)
{

    emit mouse_pressed();
    std::cerr << "LABEL CLICKED " << " ";
    this->setStyleSheet("background-color: rgb(85, 170, 255)");
    clickCount +=1;
    std::cerr << clickCount << std::endl;
    if(clickCount == 2){
        this->setStyleSheet("background-color: rgb(0,0,0,0)");
        clickCount = 0;
    }




}


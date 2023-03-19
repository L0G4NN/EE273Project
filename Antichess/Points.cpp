#include "Points.h"
#include "../../../Antichess/utils/clickablelabels.h"
#include "./ui_mainwindow.h"
//#include "ui_mainwindow.h"
#include "Chess/board.h"
#include <QPoint>


Points::Points(){

}
Points::Points(clickablelabels* label){


    dotLabel = label;
    QPoint point = label->pos();
    m_x = point.x()/label->width();
    m_y = 7-(point.y()/label->height());
    showMoves();


    std::cout  << "piece selected @ : " << m_x << ", " << m_y << std::endl; //show coordinates where clicked


}


pair<int,int> Points::getClickLocation(){
    return{m_x,m_y};
}

void Points::showMoves(){

    QPixmap dot("../Antichess/images/Pieces/bishop_w.svg");
    int a = 0;
    int b = 0;

    pair<int,int> location = this->getClickLocation();
    vector<pair<int,int>> moves;

    int x = get<0>(location);
    int y = get<1>(location);


    /*switch(board[get<0>(location)][get<1>(location)]){

        case('k'):

        break;

        case('q'):

        break;

        case('b'):

        for (int a = 0; a <=7; a++)
        {
             cout<<a<<endl;
             moves.push_back({a,a+(y-x)});
             moves.push_back({a,(2*y) - (a+(y-x))});

        }

        break;

        case('n'):

        break;

        case('r'):

        break;

        case('p'):

        break;
    }*/


        clickablelabels* mlabel = new clickablelabels;
        cout << "dot placed @: " << x+1 << "," << y+1 << ". ";
        mlabel->setPixmap(dot);
        ui->squares->addWidget(mlabel,3,4);
        //ui-> label_20 -> show();
        //ui->squares->addWidget(dotLabel,3,4);//icons.at(setup[a][b]
        //ui->squares->addWidget(mlabel,x,y);



}

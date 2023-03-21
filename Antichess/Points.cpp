#include "Points.h"
#include "../../../Antichess/utils/clickablelabels.h"
#include "./ui_mainwindow.h"
//#include "ui_mainwindow.h"
#include "Chess/board.h"
#include <QPushButton>
#include <QPoint>


Points::Points(){

}
Points::Points(QPushButton* pos){

    QPixmap dote("../Antichess/images/Pieces/bishop_w.svg");
    //dotLabel = label;
    cout<<pos->x()<<","<<pos->width()<<endl;
    m_x = floor(pos->x()/pos->width());
    m_y = floor(7-(pos->y()/pos->height()));
    showMoves();


    //std::cout  << "piece selected @ : " << m_x << ", " << m_y << std::endl; //show coordinates where clicked


}


pair<int,int> Points::getClickLocation(){
    return{m_x,m_y};
}


void Points::showMoves(){

    QPixmap dote("../Antichess/images/Pieces/bishop_w.svg");
    int a = 0;
    int b = 0;


    vector<pair<int,int>> moves;

        cout<<m_x<<","<<m_y<<endl;

        for (int a = 0; a <=14; a++)
        {
             cout<<a<<endl;
             moves.push_back({a,a+(m_y-m_x)});
             moves.push_back({a,(2*m_y) - (a+(m_y-m_x))});
        if(moves[a].second >= 0){
             cout << "dot placed @: " << moves[a].first << "," << moves[a].second << ". "<<"\n";

        }
        }
        m_moves = moves;



        //connect(label, SIGNAL(clicked()), this, SLOT(keyPressed()));
        //label->lower();



       // clickablelabels* mlabel = new clickablelabels;


}

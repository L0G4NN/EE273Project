/* filename Pieces.h
 * [Description]
 * Last updated: [DD:MM:YYYY]
 * Description of latest update:
 *
 *
 */

#ifndef PIECES_H
#define PIECES_H
#pragma once
#include <vector>
#include <QPixmap>


#endif // PIECES_H

using namespace std;
class Pieces {

public:
    Pieces();
    ~Pieces();

    Pieces(char colour,int x, int y);

    bool isActive(); //true if player has piece selected

    vector<pair<int,int>> getMoves(Pieces piece);
    vector<int> getCords();
    vector<int> getTakes(); // return a vector of all coordinates that the opponent could lose their piece in the next move
    void setCords(int x, int y); //for initial game setup
    void setIcon(QString address);
    QPixmap getIcon();

    void move();
    void show_moves(); //had a build issue with virtual func - removed temp
    void take_piece();

private:
    QPixmap icon;
    int x;
    int y;

};

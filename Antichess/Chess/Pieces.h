/* filename Pieces.h
 * [Description]
 * Last updated: [17:04:2023]
 * Description of latest update:
 *
 *  Removed unecessary methods - code cleanup
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

    vector<int> getCords();
    void setCords(int x, int y); //for initial game setup

    void setIcon(QString address);
    QPixmap getIcon();

private:
    QPixmap icon;
    int x;
    int y;

};

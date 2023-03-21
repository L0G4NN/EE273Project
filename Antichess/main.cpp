#include "mainwindow.h"
#include "Points.h"
#include "Chess/board.h"


#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    return a.exec();
}

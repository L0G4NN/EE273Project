#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    //w.setScene(new chessboard(&view));
    w.show();
    return a.exec();
}

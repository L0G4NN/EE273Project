#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>

#include <QMainWindow>
#include <QGraphicsRectItem>
#include <QGraphicsScene>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_rulesButton_clicked();

    void on_startButton_clicked();

private:
    Ui::MainWindow *ui;
};



//class Chessboard : public MainWindow {
//public:
//    Chessboard(QWidget* parent = nullptr) : MainWindow(parent)
//    {
//        const int size = 50; //size of each square
//        const int numRows = 8;
//        const int numCols = 8;

//        for (int row = 0; row < numRows; ++row) {
//            for(int cols = 0; cols < numCols; ++cols)
//            {
//                QGraphicsRectItem* square = new QGraphicsRectItem();
//                square->setRect(cols * size, row * size, size, size);
//                square->setBrush((row + cols) % 2 == 0 ? Qt::white : Qt::gray);
//                addItem(square);
//            }

//        }

//        setSceneRect(0, 0, numCols * size, numRows * size);
//    }
//};


#endif // MAINWINDOW_H

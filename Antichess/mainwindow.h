#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QStackedWidget>
#include <QGraphicsRectItem>
#include <QGraphicsPixMapItem>
#include <QPainter>
#include <QPixmap>


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


    void on_startButton_clicked();

    void on_rulesButton_clicked();

    void on_exitGame_clicked();

    void on_mainMenuButton_clicked();

    void on_PawnTest_pressed();

private:
    Ui::MainWindow *ui;
    QStackedWidget *stackedWidget;
    QGraphicsScene *Scene;
    QGraphicsRectItem *rect;
    QGraphicsPixmapItem *board;
    QPainter gridPainter;

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

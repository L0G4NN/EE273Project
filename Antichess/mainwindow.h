//#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Chess/board.h"
#include <QMainWindow>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QStackedWidget>
#include <QGraphicsRectItem>
#include <QGraphicsPixMapItem>
#include <QPainter>
#include <QPixmap>

using namespace std;


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void updateGUI(vector<string> setup);


private slots:


    void on_startButton_clicked();

    void on_rulesButton_clicked();

    void on_exitGame_clicked();

    void on_mainMenuButton_clicked();

    void on_resetButton_clicked();


private:
    Ui::MainWindow *ui;
    QStackedWidget *stackedWidget;
    QGraphicsScene *Scene;
    QGraphicsRectItem *rect;
    QGraphicsPixmapItem *board;
    QPainter gridPainter;
    Board gameBoard;

};

#endif // MAINWINDOW_H

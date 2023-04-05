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
#include "qgridlayout.h"
#include <QPushButton>
#include "../../../Antichess/utils/clickablelabels.h"

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
    void updateGUI();



private slots:

    void keyPressed(bool checked);

    void on_startButton_clicked();

    void on_rulesButton_clicked();

    void on_exitGame_clicked();

    void on_mainMenuButton_clicked();

    void on_resetButton_clicked();


protected:
    Ui::MainWindow *ui;
    Board* gameBoard;


private:
    QStackedWidget *stackedWidget;
    QGraphicsScene *Scene;
    QGraphicsRectItem *rect;
    //QGraphicsPixmapItem *board;
    QPainter gridPainter;
    vector<QPushButton*> buttons;

    QPushButton *prev;
    int m_x;
    int m_y;





};

#endif // MAINWINDOW_H

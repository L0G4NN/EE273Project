/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionRules;
    QAction *actionCreated_by_Elias_and_Logan;
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QGraphicsView *graphicsView;
    QMenuBar *menubar;
    QMenu *menuAntichess;
    QMenu *menuAbout;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1280, 720);
        actionRules = new QAction(MainWindow);
        actionRules->setObjectName("actionRules");
        actionCreated_by_Elias_and_Logan = new QAction(MainWindow);
        actionCreated_by_Elias_and_Logan->setObjectName("actionCreated_by_Elias_and_Logan");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(498, 400, 250, 85));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(550, 500, 160, 60));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(230, 100, 120, 120));
        graphicsView->setAutoFillBackground(false);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1280, 25));
        menuAntichess = new QMenu(menubar);
        menuAntichess->setObjectName("menuAntichess");
        menuAbout = new QMenu(menubar);
        menuAbout->setObjectName("menuAbout");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuAntichess->menuAction());
        menubar->addAction(menuAbout->menuAction());
        menuAbout->addAction(actionRules);
        menuAbout->addAction(actionCreated_by_Elias_and_Logan);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Antichess", nullptr));
        actionRules->setText(QCoreApplication::translate("MainWindow", "Rules", nullptr));
        actionCreated_by_Elias_and_Logan->setText(QCoreApplication::translate("MainWindow", "Created by Elias and Logan", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Start game", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Rules", nullptr));
        menuAntichess->setTitle(QCoreApplication::translate("MainWindow", "Antichess", nullptr));
        menuAbout->setTitle(QCoreApplication::translate("MainWindow", "About", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

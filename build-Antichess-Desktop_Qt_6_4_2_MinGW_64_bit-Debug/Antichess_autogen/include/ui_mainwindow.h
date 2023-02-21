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
    QAction *actionBy_Elias_and_Logan;
    QAction *actionExit;
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QMenuBar *menubar;
    QMenu *menuAntichess;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->setEnabled(true);
        MainWindow->resize(1280, 720);
        MainWindow->setTabShape(QTabWidget::Triangular);
        actionBy_Elias_and_Logan = new QAction(MainWindow);
        actionBy_Elias_and_Logan->setObjectName("actionBy_Elias_and_Logan");
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName("actionExit");
        actionExit->setCheckable(true);
        actionExit->setChecked(true);
        actionExit->setMenuRole(QAction::QuitRole);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(575, 200, 83, 29));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(575, 250, 83, 29));
        pushButton_2->setCheckable(false);
        pushButton_2->setAutoDefault(false);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1280, 25));
        menuAntichess = new QMenu(menubar);
        menuAntichess->setObjectName("menuAntichess");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuAntichess->menuAction());
        menuAntichess->addAction(actionBy_Elias_and_Logan);
        menuAntichess->addAction(actionExit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Antichess", nullptr));
        actionBy_Elias_and_Logan->setText(QCoreApplication::translate("MainWindow", "By Elias and Logan", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Start game", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Rules", nullptr));
        menuAntichess->setTitle(QCoreApplication::translate("MainWindow", "Antichess", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

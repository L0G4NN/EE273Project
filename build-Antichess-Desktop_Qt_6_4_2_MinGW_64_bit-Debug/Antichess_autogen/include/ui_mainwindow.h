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
    QAction *actionRules;
    QAction *actionCreated_by_Elias_and_Logan;
    QWidget *centralwidget;
    QPushButton *startButton;
    QPushButton *rulesButton;
    QMenuBar *menubar;
    QMenu *menuAbout;
    QMenu *menuAntichess;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1280, 720);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        actionRules = new QAction(MainWindow);
        actionRules->setObjectName("actionRules");
        actionCreated_by_Elias_and_Logan = new QAction(MainWindow);
        actionCreated_by_Elias_and_Logan->setObjectName("actionCreated_by_Elias_and_Logan");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        startButton = new QPushButton(centralwidget);
        startButton->setObjectName("startButton");
        startButton->setGeometry(QRect(498, 400, 250, 85));
        startButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);\n"
"background-color: rgb(207, 207, 207);"));
        rulesButton = new QPushButton(centralwidget);
        rulesButton->setObjectName("rulesButton");
        rulesButton->setGeometry(QRect(550, 500, 160, 60));
        rulesButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);\n"
"background-color: rgb(207, 207, 207);"));
        MainWindow->setCentralWidget(centralwidget);
        rulesButton->raise();
        startButton->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1280, 25));
        menuAbout = new QMenu(menubar);
        menuAbout->setObjectName("menuAbout");
        menuAntichess = new QMenu(menubar);
        menuAntichess->setObjectName("menuAntichess");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuAntichess->menuAction());
        menubar->addAction(menuAbout->menuAction());
        menuAbout->addAction(actionRules);
        menuAbout->addAction(actionCreated_by_Elias_and_Logan);

        retranslateUi(MainWindow);

        rulesButton->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Antichess", nullptr));
        actionRules->setText(QCoreApplication::translate("MainWindow", "Rules", nullptr));
        actionCreated_by_Elias_and_Logan->setText(QCoreApplication::translate("MainWindow", "Created by Elias and Logan", nullptr));
        startButton->setText(QCoreApplication::translate("MainWindow", "Start game", nullptr));
        rulesButton->setText(QCoreApplication::translate("MainWindow", "Rules", nullptr));
        menuAbout->setTitle(QCoreApplication::translate("MainWindow", "About", nullptr));
        menuAntichess->setTitle(QCoreApplication::translate("MainWindow", "Antichess", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

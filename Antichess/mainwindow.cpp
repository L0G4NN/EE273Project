#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QtCore>
#include <QDesktopServices>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    stackedWidget = new QStackedWidget(this);
    stackedWidget->addWidget(ui->StartPage);
    stackedWidget->addWidget(ui->Game);

    stackedWidget->setCurrentIndex(0);
    connect(ui->startButton, SIGNAL(clicked()), this, SLOT(startButtonClicked()));

    setCentralWidget(stackedWidget);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startButton_clicked()
{

}


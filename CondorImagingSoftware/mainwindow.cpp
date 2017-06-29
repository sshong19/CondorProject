#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ArchitectorSDKFunctions.h"
#include "condorcamera.h"
#include <QImage>
#include <QGraphicsScene>
#include <QCamera>
#include <QCameraInfo>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    CondorCamera condor = CondorCamera();
    condor.initiateCamera();
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_liveButton_clicked()
{
    CondorCamera condor = CondorCamera();
    QImage newimg = QImage(condor.getpixeldata(),640,450,Format_RGB888);
    ui->label->setPixmap(QPixmap::fromImage(newimg));
    return;
}



void MainWindow::on_stopButton_clicked()
{
    CondorCamera condor;
    condor.stopCamera();
    return;
}



void MainWindow::on_quitButton_clicked()
{
    CondorCamera condor;
    condor.disconnectCamera();
    return;
}


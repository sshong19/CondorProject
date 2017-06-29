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
}


MainWindow::~MainWindow()
{
    delete ui;
}

//void MainWindow::on_liveButton_clicked()
//{
//    CondorCamera condor = CondorCamera();
//    condor.startCamera();
//    QImage newimg = QImage(condor.getpixeldata(),640,450,QImage::Format_RGB888);
//    ui->label->setPixmap(QPixmap::fromImage(newimg));
//    return;
//}



//void MainWindow::on_stopButton_clicked()
//{
//    CondorCamera condor;
//    condor.stopCamera();
//    return;
//}



//void MainWindow::on_quitButton_clicked()
//{
//    CondorCamera condor;
//    condor.disconnectCamera();
//    return;
//}


void MainWindow::on_liveButton_clicked()
{
    CondorCamera condor = CondorCamera();
    condor.startCamera();
    QImage newimg = QImage(condor.getpixeldata(),640,450,QImage::Format_RGB888);
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

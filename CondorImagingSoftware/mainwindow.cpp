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
    CondorCamera* condor = new CondorCamera();
    condor->initiateCamera();
    delete condor;
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    CondorCamera* condor = new CondorCamera();
    QImage newimg = QImage(condor->pixeldata,640,450,Format_RGB888);
    ui->label->setPixmap(QPixmap::fromImage(newimg));
}

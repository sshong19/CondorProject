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


void MainWindow::on_stopButton_clicked()
{
    CondorCamera condor;
    condor.stopCamera();
    condor.disconnectCamera();
    return;
}


void MainWindow::on_initiateButton_clicked()
{
    CondorCamera condor = CondorCamera();
    condor.initiateCamera();
}

void MainWindow::on_snapButton_clicked()
{
    CondorCamera condor = CondorCamera();
    uchar** arrayOfChannelPointers = condor.snapshot();
    std:: cout << "References have been set" << std::endl;
    std::cout << "popped an image" << std::endl;
    QImage newimg;QImage newimg1; QImage newimg2;
    newimg.fromData(arrayOfChannelPointers[0],307200);
    newimg1.fromData(arrayOfChannelPointers[1],307200);
    newimg2.fromData(arrayOfChannelPointers[2],307200);
    std::cout << "drawing on QImage"<< std::endl;
    ui->ColorCamera_Img->setPixmap(QPixmap::fromImage(newimg));
    ui->NIR1_Img ->setPixmap(QPixmap::fromImage(newimg1));
    ui->NIR2_Img ->setPixmap(QPixmap::fromImage(newimg2));
    ui->Merge_Img->setPixmap(QPixmap::fromImage(newimg));
    std::cout << "drawing on label" << std::endl;
}

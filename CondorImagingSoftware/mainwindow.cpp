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
    condor.startCamera();
    condor.stopCamera();
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
    condor.startCamera();
    std:: cout << "References have been set" << std::endl;
    uchar* pixeldata = condor.popImages();
    std::cout << "popped an image" << std::endl;
    int bytes_per_line = 1280*3;
    QImage newimg;
    newimg.fromData(pixeldata,307200);
    std::cout << "drawing on QImage"<< std::endl;
    ui->ColorCamera_Img->setPixmap(QPixmap::fromImage(newimg));
    ui->NIR1_Img ->setPixmap(QPixmap::fromImage(newimg));
    ui->NIR2_Img ->setPixmap(QPixmap::fromImage(newimg));
    ui->Merge_Img->setPixmap(QPixmap::fromImage(newimg));
    std::cout << "drawing on label" << std::endl;
}

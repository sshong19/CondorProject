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

void MainWindow::on_quitButton_clicked()
{
    CondorCamera condor;
    condor.disconnectCamera();
    return;
}


void MainWindow::on_liveButton_clicked()
{
    CondorCamera condor = CondorCamera();
    condor.startCamera();
    std:: cout << "References have been set" << std::endl;
    Architector::DeviceRefPtr dev;
    dev = condor.getdev();
//    while(dev -> isGrabbing()){
        uchar* pixeldata = condor.popImages();
        std::cout << "popped an image" << std::endl;
        QImage newimg = QImage(pixeldata,640,450,QImage::Format_Indexed8);
        std::cout << "drawing on QImage"<< std::endl;
        ui->label->setPixmap(QPixmap::fromImage(newimg));
        std::cout << "drawing on label" << std::endl;
//    }
}

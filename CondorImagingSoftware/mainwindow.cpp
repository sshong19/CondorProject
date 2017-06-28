#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ArchitectorSDKFunctions.h"
#include <QImage>
#include <QGraphicsScene>
#include <QCamera>
#include <QCameraInfo>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
    foreach (const QCameraInfo& cameraInfo, cameras){
        qDebug() << cameraInfo.deviceName();
    }

    ui->setupUi(this);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    init();
    Architector::DeviceRefPtr dev = getDevice("GenericDevice");
    if (!dev.isValid()){
        std::cout << "Device is not present" << std::endl;
    }

    //Detect framegrabbers and allow users to pick one. A framegrabber must be detected before it can be used.
    detectFrameGrabbers();
    //Get the chosen framegrabber from the manager, return early if grabber cannot be retrieved.
    Architector::FrameGrabberRefPtr grabber = getFrameGrabber("Epix_EL1_01");
    if (!grabber.isValid()){
        std::cout<<"Grabber is not present" << std::endl;
    }
    //Assign the framegrabber to the device created earlier.
    assignFrameGrabberToDevice(dev, grabber);
    //Set up the framegrabber to return images of specific format.
    //Please note that specialized devices (like the "Condor5-ICX285") have presets that automatically setup
    //the assigned grabber(s) to obtain the best results.
    std::cout << "Setting up framegrabber, for 1 taps, 640x480 8-bit images..." << std::endl;
    //setupFrameGrabber(grabber, 2720, 1024, 12, 2); //for 12 bit. full resolution on a Condor 3.
    //setupFrameGrabber(grabber, 1360, 1024, 8, 3); //for 8 bit full resolution on a Condor 3.
    setupFrameGrabber(grabber, 640, 480, 8, 1); //for 8 bit
    //Creating a buffer for the camera place streamed images in.
    Architector::BufferRefPtr buf = createBuffer();
    if (!connectBuffer(dev, buf))
    {
        std::cout << "Could not connect buffer." << std::endl << std::endl;
    }
    dev->connect();
    //Starting grabbing.
    if (!startGrabbing(dev))
    {
        std::cout << "Could not start grabbing." << std::endl << std::endl;
    }
    Architector::ImageBuffer* bufPtr = Architector::buffer_cast<Architector::ImageBuffer>(buf);
    if (bufPtr == NULL)
    {
        std::cout << "Bad buffer." << std::endl;
        stopGrabbing(dev);
        dev->disconnect();
    }
//    while (dev->isGrabbing())
//    {
//        Architector::ImgRefPtr img;
//        //since we have a blocking buffer, this method returns when there's an image in the buffer.
//        bufPtr->pop(img);
//        Architector::ChannelRefPtr ch0 = img->channel(0);
//        uchar* pixelpointer = reinterpret_cast<uchar*>(ch0 -> uint8Data());
//        QImage newimg = QImage(pixelpointer,640,480,QImage::Format_Indexed8);
//        ui->label->setPixmap(QPixmap::fromImage(newimg));
//        delete pixelpointer;
//    }
}

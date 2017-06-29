#include "mainwindow.h"
#include "condorcamera.h"
#include "ArchitectorSDKFunctions.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    CondorCamera condor = CondorCamera();
    condor.initiateCamera();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

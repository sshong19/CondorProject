#include "mainwindow.h"
#include "condorcamera.h"
#include "ArchitectorSDKFunctions.h"
#include <QApplication>
#include "initialwindow.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    initialWindow w;
    w.show();
    return a.exec();
}

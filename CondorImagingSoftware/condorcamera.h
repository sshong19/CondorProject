#ifndef CONDORCAMERA_H
#define CONDORCAMERA_H

#include <string>
#include "ArchitectorSDKFunctions.h"
#include <Architector/BufferManager.h>
#include <Architector/DeviceManager.h>
#include <Architector/FrameGrabberManager.h>
#include <Architector/ImageManager.h>
#include <Architector/LogManager.h>
#include <Architector/Utility/FileSystem.h>
#include <Architector/Utility/PluginLoader.h>

class CondorCamera
{
public:
    CondorCamera();

    void initiateCamera();

    void startCamera();

    void stopCamera();

    void disconnectCamera();

    uchar* getpixeldata(){
        return this->pixeldata;
    }

    void setpixeldata(uchar* pixeldata){
        this->pixeldata = pixeldata;
    }

    ~CondorCamera(){
        delete this->pixeldata;
        std::cout << "Destructor is called" << std::endl;
    }

private:
    uchar* pixeldata;
    std::string deviceName;
    std::string grabberName;

};

#endif // CONDORCAMERA_H

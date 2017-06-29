#ifndef CONDORCAMERA_H
#define CONDORCAMERA_H

#include <string>
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
    uchar* pixeldata;

private:
    std::string deviceName;
    std::string grabberName;

};

#endif // CONDORCAMERA_H

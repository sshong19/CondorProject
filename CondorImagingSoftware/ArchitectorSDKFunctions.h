#ifndef ARCHITECTORSDKFUNCTIONS_H
#define ARCHITECTORSDKFUNCTIONS_H

#include <Architector/BufferManager.h>
#include <Architector/DeviceManager.h>
#include <Architector/FrameGrabberManager.h>
#include <Architector/ImageManager.h>
#include <Architector/LogManager.h>
#include <Architector/Utility/FileSystem.h>
#include <Architector/Utility/PluginLoader.h>
#include "mainwindow.h"

#include <stdint.h>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>


void init();
Architector::DeviceRefPtr getDevice(const std::string& type);
void detectFrameGrabbers();
Architector::FrameGrabberRefPtr getFrameGrabber(const std::string& name);
void setupFrameGrabber(Architector::FrameGrabberRefPtr grabber, uint32_t w, uint32_t h, uint32_t bd, uint32_t taps); 
void assignFrameGrabberToDevice(Architector::DeviceRefPtr dev, Architector::FrameGrabberRefPtr grabber);
int getFrameCount();
Architector::BufferRefPtr createBuffer();
bool connectBuffer(Architector::DeviceRefPtr dev, Architector::BufferRefPtr buf);
bool startGrabbing(Architector::DeviceRefPtr dev);
void stopGrabbing(Architector::DeviceRefPtr dev);
bool disconnectSource(Architector::BufferRefPtr buffer);
void releaseBuffer(Architector::BufferRefPtr& buf);
std::string getFilename();
void saveChannel(Architector::ImgRefPtr img, int channel, const std::string& filename);
void saveImage(Architector::ImgRefPtr img, const std::string& baseFilename);
Architector::ImgRefPtr takeSnapshot(Architector::DeviceRefPtr dev);
std::string chooseFrameGrabber();
void cleanup();
int cleanupAndQuit(int returnValue);

#endif

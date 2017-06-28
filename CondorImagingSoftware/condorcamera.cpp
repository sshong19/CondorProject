#include "condorcamera.h"

CondorCamera::CondorCamera()
{
    deviceName = "Condor3-ICX692-CL";
    grabberName = "EPIX_EL1_01";
}

void CondorCamera::initiateCamera(){

    //loading all the plugins for the camera
    Architector::PluginLoader* ptr = Architector::PluginLoader::get();
    Architector::PluginLoader::get()->discoverAvailablePlugins();
    Architector::PluginLoader::get()->loadAll();
    Architector::PluginLoader::PluginVector plugins = Architector::PluginLoader::get()->plugins();
    std::string& type = this->deviceName;

    //initiating the device(camera)
    Architector::DeviceRefPtr dev = Architector::DeviceManager::get()->create(type.c_str(),"KevinsDevice");
    if (!dev.isValid()){
        std::cout << "Could not create instance of " << type << " ." << std::endl;
    }
    //initiating the framegrabber
    std::string& grabbertype = this->grabberName;
    Architector::FrameGrabberRefPtr grabber = Architector::FrameGrabberManager::get()->instance(grabbertype.c_str());
    if (dev.isValid() && grabber.isValid()){
        dev -> addHwComponent(0,grabber);
    }

    //setting up for EPIX framegrabber
    grabber->connect();
    grabber->beginPropertyChange();
    uint32_t taps = 1;
    uint32_t bitdepth = 8;
    uint32_t width = 640;
    uint32_t height = 450;
    grabber->setProperty("Image::Tap",taps-1u);
    grabber->setProperty("Image::BitDepth",bitdepth);
    grabber->setProperty("Image::Width",width);
    grabber->setProperty("Image::Height",height);
    grabber->setProperty("SerialPort::BaudRate","57600");
    grabber->endPropertyChange();
    uint32_t mode = 0;
    std::stringstream sstream;
    sstream << "Pixel " << mode << "\n";
    grabber->write(reinterpret_cast<const uint8_t*>(sstream.str().c_str()),sstream.str().size());
    Architector::Thread::sleep(100);
    grabber->disconnect();

    //Create Buffer
    std::string bufName = "KevinsBuffer";
    Architector::BufferRefPtr buf = Architector::BufferManager::get->create("ImageFifo",1,bufName);
    if(buf.isValid()){
        buf->beginPropertyChange();
        buf->setProperty("PushBlock","On");
        buf->setProperty("PopBlock","On");
        buf->endPropertyChange();
    }

    //Connect device to the buffer
    buf -> connectSource(dev,"Output");

//    //Connect framegrabber to the buffer
//    grabber -> setImageBuffer(buf);

}

void CondorCamera::startCamera(){
    std::string& grabberType = this->grabberName;
    Architector::FrameGrabberRefPtr grabber = Architector::FrameGrabberManager::get()->instance(grabbertype.c_str());
    std::string& deviceType = "KevinsDevice";
    Architector::DeviceRefPtr dev = Architector::DeviceManager::get()->instance(devicename.c_str());
    std::string& bufferType = "KevinsBuffer";
    Architector::BufferRefPtr buf = Archiector::BufferManager::get()->instance(bufferType.c_str());
    if(!dev->isConnected()){
        dev->connect();
    }
    //device starts grabbing images
    dev -> startGrabbing();
    Architector::ImageBuffer*bufPtr = Architector::buffer_cast<Architector::ImageBuffer>(buf);

    //cleans up if it gives bad images
    if(bufPtr == NULL){
        std::cout << "Bad buffer." << std::endl;
        dev -> stopGrabbing();
        dev->disconnect();
        std::cout << "Cleaning up..." << std::endl;
        std::cout << "Unloading plugins..." << std::endl;
        Architector::PluginLoader::get()->unloadAll();

        std::cout << "Clearing managers..." << std::endl;
        Architector::BufferManager::get()->cleanUp();
        Architector::ImageManager::get()->cleanUp();
        Architector::DeviceManager::get()->cleanUp();
        Architector::FrameGrabberManager::get()->cleanUp();
        Architector::LogManager::get()->cleanUp();

        std::cout << "Cleanup complete." << std::endl;
    }

    Architector::ImgRefPtr img;
    while(dev->isGrabbing){
        bufPtr -> pop(img);
        Architector::ChannelRefPtr colorchannel = img -> channel(0);
        uchar* pixeldata = reinterpret_cast<uchar*>(colorchannel->uint8Data());
    }

}

#include "condorcamera.h"
#include "ArchitectorSDKFunctions.h"

CondorCamera::CondorCamera()
{
    deviceName = "Condor3-ICX692-CL";
    grabberName = "Epix_EL1_01";
}

void CondorCamera::initiateCamera(){

    //loading all the plugins for the camera
    Architector::PluginLoader* ptr = Architector::PluginLoader::get();
    Architector::PluginLoader::get()->discoverAvailablePlugins();
    Architector::PluginLoader::get()->loadAll();
    Architector::PluginLoader::PluginVector plugins = Architector::PluginLoader::get()->plugins();
    std::cout << "Loaded " << plugins.size() << " plugins:" << std::endl;

    typedef Architector::PluginLoader::PluginVector::iterator PluginIterator;
    for (PluginIterator it = plugins.begin(); it != plugins.end(); ++it)
    {
        Architector::PluginOrganizer* org = (*it);
        if (org != NULL)
        {
            Architector::PluginInfo info = org->info();
            std::cout << " - " << info.name() << std::endl;
        }
    }
    const std::string type = "Condor3-ICX692-CL";
    std::string devName = "KevinsDevice";
    //initiating the device(camera)
    Architector::DeviceRefPtr dev = Architector::DeviceManager::get()->create(type.c_str(),devName);
    if (!dev.isValid()){
        std::cout << "Could not create instance of " << type << " ." << std::endl;
    }
    std::cout << "Initiating the device from the camera" << std::endl;
    //initiating the framegrabber
    std::string grabbertype = "Epix_EL1_01";
    Architector::FrameGrabberRefPtr grabber = Architector::FrameGrabberManager::get()->instance(grabbertype.c_str());
    if(!grabber.isValid()){
        std::cout<<"The framegrabber is not present"<<std::endl;
    }
    if (dev.isValid() && grabber.isValid()){
        dev -> addHwComponent(0,grabber);
    }
    std::cout<<"Initiated the framegrabber from the camera" << std::endl;

    //setting up for EPIX framegrabber
    grabber->connect();
    std::cout<<"The device is connected"<<std::endl;
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
    std::cout<<"Property of the framegrabber has been set"<<std::endl;
    uint32_t mode = 0;
    std::stringstream sstream;
    sstream << "Pixel " << mode << "\n";
    grabber->write(reinterpret_cast<const uint8_t*>(sstream.str().c_str()),sstream.str().size());
    std::cout<<"Sent signal through serial port"<<std::endl;
    Architector::Thread::sleep(100);
    grabber->disconnect();
    std::cout<<"Framegrabber has been set up"<<std::endl;

    //Create Buffer
    std::string bufName = "KevinsBuffer";
    Architector::BufferRefPtr buf = Architector::BufferManager::get()->create("ImageFifo",1,bufName);
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
    std::string grabberType = this->grabberName;
    Architector::FrameGrabberRefPtr grabber = Architector::FrameGrabberManager::get()->instance(grabberType.c_str());
    std::string deviceType = "KevinsDevice";
    Architector::DeviceRefPtr dev = Architector::DeviceManager::get()->instance(deviceType.c_str());
    std::string bufferType = "KevinsBuffer";
    Architector::BufferRefPtr buf = Architector::BufferManager::get()->instance(bufferType.c_str());
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
    while(dev->isGrabbing()){
        bufPtr -> pop(img);
        Architector::ChannelRefPtr colorchannel = img -> channel(0);
        this->pixeldata = reinterpret_cast<uchar*>(colorchannel->uint8Data());
    }

}

void CondorCamera::stopCamera(){
    std::cout<<"Stop grabbing images" << std::endl;
    std::string grabberType = this->grabberName;
    Architector::FrameGrabberRefPtr grabber = Architector::FrameGrabberManager::get()->instance(grabberType.c_str());
    std::string deviceType = "KevinsDevice";
    Architector::DeviceRefPtr dev = Architector::DeviceManager::get()->instance(deviceType.c_str());
    std::string bufferType = "KevinsBuffer";
    Architector::BufferRefPtr buf = Architector::BufferManager::get()->instance(bufferType.c_str());
    dev->stopGrabbing();
}

void CondorCamera::disconnectCamera(){
    std::string grabberType = this->grabberName;
    Architector::FrameGrabberRefPtr grabber = Architector::FrameGrabberManager::get()->instance(grabberType.c_str());
    std::string deviceType = "KevinsDevice";
    Architector::DeviceRefPtr dev = Architector::DeviceManager::get()->instance(deviceType.c_str());
    std::string bufferType = "KevinsBuffer";
    Architector::BufferRefPtr buf = Architector::BufferManager::get()->instance(bufferType.c_str());
    dev->stopGrabbing();
    std::cout<<"Stop grabbing images"<<std::endl;
    dev->disconnect();
    std::cout<<"disconnecting the device"<<std::endl;
    buf->disconnectSource();
    std::cout<<"disconnecting the buffer from the source"<<std::endl;
    Architector::BufferManager::get()->releaseInstance(buf->name().c_str());
    std::cout<<"Releasing buffer from manager"<<std::endl;
    cleanup();
}




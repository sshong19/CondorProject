#include "condorcamera.h"
#include "ArchitectorSDKFunctions.h"
using namespace std;

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
    std::string devName = "MyDevice";
    //initiating the device(camera)
    Architector::DeviceRefPtr dev = Architector::DeviceManager::get()->create(type.c_str(),devName);
    if (!dev.isValid()){
        std::cout << "Could not create instance of " << type << " ." << std::endl;
    }
    std::cout << "Initiating the device from the camera" << std::endl;
    //initiating the framegrabber
    std::string grabbertype = "Epix_EL1_01";
    //Getting the list of frame grabbers
    std::cout<<"The following framegrabbers are available for use." <<std::endl;
    int index = 1;
    //Detecting framegrabbers
    Architector::DeviceManager::get()->detectAll(100);
    Architector::StringList frameGrabbers = Architector::FrameGrabberManager::get()->instanceList();
    for(Architector::StringList::iterator it = frameGrabbers.begin(); it != frameGrabbers.end();++it,++index){
        std::cout<<"["<<index <<"]" << *it << std::endl;
    }
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
    uint32_t taps = 3;
    uint32_t bitdepth = 8;
    uint32_t width = 640;
    uint32_t height = 480;
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
    std::string bufName = "MyBuffer";
    Architector::BufferRefPtr buf = Architector::BufferManager::get()->create("ImageFifo",1,bufName);
    if(buf.isValid()){
        cout << "buffer is valid" << endl;
        buf->beginPropertyChange();
        buf->setProperty("PushBlock","On");
        buf->setProperty("PopBlock","On");
        buf->endPropertyChange();
    }

    //Connect buffer to device's output slot
    if (!connectBuffer(dev,buf)){
        std:cout <<"Could not connect buffer."<<std::endl;
    }
//    buf -> connectSource(dev,"Output");
//    cout << "connected to the source" << endl;
////    //Connect framegrabber to the buffer
////    grabber -> setImageBuffer(buf);

}

void CondorCamera::startCamera(){
    std::string grabberType = "Epix_EL1_01";
    Architector::FrameGrabberRefPtr grabber = Architector::FrameGrabberManager::get()->instance(grabberType.c_str());
    std::string deviceType = "MyDevice";
    Architector::DeviceRefPtr dev = Architector::DeviceManager::get()->instance(deviceType.c_str());
    std::string bufferType = "MyBuffer";
    Architector::BufferRefPtr buf = Architector::BufferManager::get()->instance(bufferType.c_str());
    cout << "Reference to Buffer" << endl;
    if(!dev->isConnected()){
        dev->connect();
        cout << "Device is connected" << endl;
    }
    //Get the base file name for saving images to. If result is empty we don't save.
    std::string baseFilename = "C:\Users\Choi-HPLC\Desktop\test\test.raw";
    //device starts grabbing image
    if(!startGrabbing(dev)){
        std::cout<<"Could not start grabbing."<<std::endl;
    }
    grabber->setImageBuffer(buf);
    cout << "Device started grabbing" << endl;

    //In order to pop images from the buffer we must cast the buffer to the appropriate type
    Architector::ImageBuffer*bufPtr = Architector::buffer_cast<Architector::ImageBuffer>(buf);
    if (!buf.isValid()){
        cout << "There is no buffer" << endl;
    }
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
        int maxFrames = 5;
        int digitCount = static_cast<int>(floor(log10(static_cast<double>(maxFrames))) + 1);
        //save every image we get and count the number of frames we've received.
        int currentFrame = 1;
//        while (currentFrame <= maxFrames && dev->isGrabbing())
//        {
//            Architector::ImgRefPtr img;
//            //since we have a blocking buffer, this method returns when there's an image in the buffer.
//            bufPtr->pop(img);
//            char sign = ((currentFrame % 5) == 0)? '|': '.';
//            std::cout << sign;
//            if (!baseFilename.empty())
//            {
//                std::stringstream sstream;
//                sstream << base << "_frame_" << std::setw(digitCount) << std::setfill('0') << currentFrame
//                    << "_of_" << maxFrames << ext;
//                saveImage(img, baseFilename);
//            }
//            ++currentFrame;
//        }
//        std::cout << " Streamed " << (currentFrame - 1) << " frames." << std::endl << std::endl;
}

uchar* CondorCamera::popImages(){
    std::string grabberType = this->grabberName;
    Architector::FrameGrabberRefPtr grabber = Architector::FrameGrabberManager::get()->instance(grabberType.c_str());
    std::string deviceType = "MyDevice";
    Architector::DeviceRefPtr dev = Architector::DeviceManager::get()->instance(deviceType.c_str());
    std::string bufferType = "MyBuffer";
    Architector::BufferRefPtr buf = Architector::BufferManager::get()->instance(bufferType.c_str());

    Architector::ImageBuffer*bufPtr = Architector::buffer_cast<Architector::ImageBuffer>(buf);
    cout << "Device is grabbing images" << endl;
    Architector::ImgRefPtr img;
    if (grabber->isGrabbing()){
        cout << "Framegrabber is grabbing the image" << endl;
    }
    if (bufPtr == NULL){
        cout << "No bufPtr" << endl;
    }
    if (!dev.isValid()){
        cout << "Device is not present" << endl;
    }
    if (!buf.isValid()){
        cout << "Buffer is not present" << endl;
    }
    if (!grabber.isValid()){
        cout << "Grabber is not present" << endl;
    }
    dev->snapshot(img);
    if (!img.isValid()){
        cout << "Img is not present" << endl;
    }
    cout << "Image width: " << img->width() << endl;
    cout << "Image height: " << img->height() << endl;
    cout << "Image size in bytes: " << img->sizeInBytes() << endl;
    cout << "Img popped from the buffer" << endl;
    Architector::ChannelRefPtr colorchannel = img -> channel(0);
    return reinterpret_cast<uchar*>(colorchannel->uint8Data());
}

 uchar** CondorCamera::snapshot(){
     std::string grabberType = this->grabberName;
     Architector::FrameGrabberRefPtr grabber = Architector::FrameGrabberManager::get()->instance(grabberType.c_str());
     std::string deviceType = "MyDevice";
     Architector::DeviceRefPtr dev = Architector::DeviceManager::get()->instance(deviceType.c_str());
     std::string bufferType = "MyBuffer";
     Architector::BufferRefPtr buf = Architector::BufferManager::get()->instance(bufferType.c_str());
     Architector::ImgRefPtr img;
   uchar** arrayOfChannelPointers;
    for (int ii = 0; ii < 3; ii++){
        Architector::ChannelRefPtr colorchannel = img->channel(ii);
        arrayOfChannelPointers[ii] = reinterpret_cast<uchar*>(colorchannel->uint8Data());
    }
    return arrayOfChannelPointers;
 }

void CondorCamera::stopCamera(){
    cout<<"Stop grabbing images" << std::endl;
    std::string grabberType = this->grabberName;
    Architector::FrameGrabberRefPtr grabber = Architector::FrameGrabberManager::get()->instance(grabberType.c_str());
    std::string deviceType = "MyDevice";
    Architector::DeviceRefPtr dev = Architector::DeviceManager::get()->instance(deviceType.c_str());
    std::string bufferType = "MyBuffer";
    Architector::BufferRefPtr buf = Architector::BufferManager::get()->instance(bufferType.c_str());
    dev->stopGrabbing();
    return;
}

void CondorCamera::disconnectCamera(){
    std::string grabberType = this->grabberName;
    Architector::FrameGrabberRefPtr grabber = Architector::FrameGrabberManager::get()->instance(grabberType.c_str());
    std::string deviceType = "MyDevice";
    Architector::DeviceRefPtr dev = Architector::DeviceManager::get()->instance(deviceType.c_str());
    std::string bufferType = "MyBuffer";
    Architector::BufferRefPtr buf = Architector::BufferManager::get()->instance(bufferType.c_str());
    cout << "here" << endl;
    grabber->grabStop();
    cout << "Grabber stopped" << endl;
    dev->stopGrabbing();
    std::cout<<"Stop grabbing images"<<std::endl;
    dev->disconnect();
    std::cout<<"disconnecting the device"<<std::endl;
    buf->disconnectSource();
    std::cout<<"disconnecting the buffer from the source"<<std::endl;
    Architector::BufferManager::get()->releaseInstance(buf->name().c_str());
    std::cout<<"Releasing buffer from manager"<<std::endl;
    cleanup();
    return;
}




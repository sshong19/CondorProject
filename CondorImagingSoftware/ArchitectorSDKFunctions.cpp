#pragma once

#include "ArchitectorSDKFunctions.h"

int getNumber()
{
	std::string input;
	std::getline(std::cin, input);

	if ((input.size() >= 1) && ((input[0] == 'q') || (input[0] == 'Q')))
		return -1;

	int res = 0;
	std::stringstream sstream(input);
	sstream >> res;

	return res;
}

void init()
{
    //std::cout << "Loading plugins..." << std::endl;
	Architector::PluginLoader* ptr = Architector::PluginLoader::get();
	Architector::PluginLoader::get()->discoverAvailablePlugins();
	Architector::PluginLoader::get()->loadAll();

	Architector::PluginLoader::PluginVector plugins = Architector::PluginLoader::get()->plugins();
    //std::cout << "Loaded " << plugins.size() << " plugins:" << std::endl;

//	typedef Architector::PluginLoader::PluginVector::iterator PluginIterator;
//	for (PluginIterator it = plugins.begin(); it != plugins.end(); ++it)
//	{
//		Architector::PluginOrganizer* org = (*it);
//		if (org != NULL)
//		{
//			Architector::PluginInfo info = org->info();
//            std::cout << " - " << info.name() << std::endl;
//		}
//	}
}

/*!
	Creates a new device of the desired type and returns it.

	As we don't need to use the device anywhere other that here, there is no need to keep a reference to it
	in the device manager.
*/
Architector::DeviceRefPtr getDevice(const std::string& type = "GenericDevice")
{
	//Creating device and asserting its valid.
	std::string devName = "MyDevice";
	Architector::DeviceRefPtr dev = Architector::DeviceManager::get()->create(type.c_str(), devName);
	if (!dev.isValid())
	{
		//std::cout << "Could not create instance of \"" << type << "\"." << std::endl;
		return Architector::DeviceRefPtr();
	}

	//releasing device from manager, so that it will we no longer use it.
	//Note: releasing a device from the manager will reset the device's name, e.g.:
	//dev->name() will return an empty string.
	Architector::DeviceManager::get()->releaseInstance(dev->name().c_str());
	return dev;
}

/*!
	Detects all framegrabbers useable with Architector.

	Please note that detecting framegrabbers is done via the device manager and not via
	the frame grabber manager. This is because of historic reasons.
*/
void detectFrameGrabbers()
{
    //std::cout << "Started detecting frame grabbers... This may take a while." << std::endl;
	//Note, using DeviceManager to detect framegrabbers.
	Architector::DeviceManager::get()->detectAll(100);
}

/*!
	Retrieves a framegrabber with name \a name from the Frame grabber manager.

	Please note that the frame grabber must have been detected previously before it can be retrieved 
	from the manager.
	
	Also note that we retrieve an instance of a framegrabber here and do not create a new one like
	when creating devices.
*/
Architector::FrameGrabberRefPtr getFrameGrabber(const std::string& name)
{
	return Architector::FrameGrabberManager::get()->instance(name.c_str());
}

/*!
	Assigns \a grabber to \a dev if both are valid.

	Please note that this method will not work when adding a second or higher number frame grabber as
	the first argument of the device's "addHwComponent" must be unique for all grabbers.
*/
void assignFrameGrabberToDevice(Architector::DeviceRefPtr dev, Architector::FrameGrabberRefPtr grabber)
{
	if (dev.isValid() && grabber.isValid())
	{
		dev->addHwComponent(0, grabber);
	}
}

void setupFrameGrabber(Architector::FrameGrabberRefPtr grabber, uint32_t w, uint32_t h
					   , uint32_t bd, uint32_t taps)
{
	//some framegrabbers are required to be connected before making these changes.
    std:: cout << "Before connecting the grabber" << std::endl;
	grabber->connect(); 
    std:: cout << "After connection" << std:: endl;
	grabber->beginPropertyChange();
	grabber->setProperty("Image::Tap", taps - 1u); //Image::Tap is 0-orientated and will always be 1 less than taps.
	grabber->setProperty("Image::BitDepth", bd);
	grabber->setProperty("Image::Width", w);
	grabber->setProperty("Image::Height", h);
	grabber->setProperty("SerialPort::BaudRate", "9600");
	grabber->endPropertyChange();

	//Setting up camera for right 8 or 12 bit images.
	//Only works for Quest cameras, comment out next 5 lines in case of non-quest camera.
	uint32_t mode = (bd <= 8)? 0: 2;
	std::stringstream sstream;
	sstream << "Pixel " << mode << "\n";
	grabber->write(reinterpret_cast<const uint8_t*>(sstream.str().c_str()), sstream.str().size());
	Architector::Thread::sleep(100);

	grabber->disconnect();
}


int getFrameCount()
{
	int res = 0;
	while (res <= 0)
	{
		std::cout << "Please enter the number of frames you wish to stream (from 1 to 100)." << std::endl;
		res = getNumber();
		if ((res <= 0) || (res > 100))
		{
			std::cout << "Invalid value, try again." << std::endl;
			res = 0;
		}
	}

	return res;
}

/*!
	Creates a new buffer suitable for storing images.

	The buffer will be a FIFO (First In, First Out) buffer.
*/
Architector::BufferRefPtr createBuffer()
{
	std::cout << "Creating buffer..." << std::endl;

	std::string bufName = "MyBuffer";
	Architector::BufferRefPtr res = Architector::BufferManager::get()->create("ImageFifo", 1, bufName);

	//Unlike device we may not release the buffer from the manager as long as the buffer is used, since
	//process interfaces (like devices) need the buffer to be in the manager in order to initiate them.
	if (res.isValid())
	{
		//Changing properties to make buffer blocking on push and pop.
		//This means that the push and pop method of this buffer will not return until an image is either 
		//pushed or popped.
		res->beginPropertyChange();
		res->setProperty("PushBlock", "On");
		res->setProperty("PopBlock", "On");
		res->endPropertyChange();
	}
	return res;
}

/*!
	Connects a buffer to a device, if both are valid.

	Buffer must be able to store images.
*/
bool connectBuffer(Architector::DeviceRefPtr dev, Architector::BufferRefPtr buf)
{
	if (!dev.isValid() || !buf.isValid())
		return false;

	//confirm we have buffer of proper type.
	if (Architector::buffer_cast<Architector::ImageBuffer>(buf) == NULL)
		return false;

	std::cout << "Connecting buffer to camera..." << std::endl;

	//Connects the buffer to the device's "Output" slot.
	return buf->connectSource(dev, "Output");
}
std::string chooseFrameGrabber()
{
    std::cout << "The following framegrabbers are available for use." << std::endl;

    int index = 1;
    Architector::StringList frameGrabbers = Architector::FrameGrabberManager::get()->instanceList();
    for (Architector::StringList::iterator it = frameGrabbers.begin(); it != frameGrabbers.end(); ++it, ++index)
    {
        std::cout << "[" << index << "] " << *it << std::endl;
    }

    std::cout << std::endl;

    int fg = 0;
    while (fg == 0)
    {
        std::cout << "Please choose a framegrabber or choose 'Q' to quit." << std::endl;
        fg = getNumber();

        if (fg > (int)frameGrabbers.size())
        {
            fg = 0;
        }
    };

    if (fg < 0)
        return "";

    std::string usedFrameGrabber = frameGrabbers[fg - 1];
    std::cout << std::endl << "Using \"" << usedFrameGrabber << "\" with device." << std::endl;
    return usedFrameGrabber;
}

/*!
	Starts streaming device.

	This method does nothing if the device is not valid or if it's already grabbing.
*/
bool startGrabbing(Architector::DeviceRefPtr dev)
{
	if (!dev.isValid() || dev->isGrabbing())
		return false;

	std::cout << "Starting to grab images..." << std::endl;
	//A device must be connected before it can start grabbing.
	if (!dev->isConnected())
	{
		dev->connect();
	}

	//Start grabbing.
	return dev->startGrabbing();
}

/*!
	Stops streaming device.

	This method does nothing if the device is not valid or if it's not grabbing.
*/
void stopGrabbing(Architector::DeviceRefPtr dev)
{
	if (!dev.isValid() || !dev->isGrabbing())
		return;

	std::cout << "Stopping grabbing..." << std::endl;
	//Stops grabbing frames.
	dev->stopGrabbing();
}

/*!
	Disconnects a buffer from whatever is attached to its source.
*/
bool disconnectSource(Architector::BufferRefPtr buffer)
{
	if (!buffer.isValid())
		return true; //no buffer, so there's nothing attached to it.

	std::cout << "Disconnecting buffer from source..." << std::endl;
	return buffer->disconnectSource();
}

/*!
	Releases the buffer from the buffer manager.

	Please note that once you do this, you can no longer use the buffer with processes or devices.
*/
void releaseBuffer(Architector::BufferRefPtr& buf)
{
	if (!buf.isValid())
		return;

	std::cout << "Releasing buffer from manager..." << std::endl;
	Architector::BufferManager::get()->releaseInstance(buf->name().c_str());
}

/*!
	Queries user to enter a filename under which the an image can be saved.

	If the given directory doesn't exists, the user will have to try again.
	If the user doesn't enter anything at all, this method will return an empty string (and no file will be saved).
	If the give filename does not end in ".raw", the extension ".raw" will be added.
*/
std::string getFilename()
{
	std::cout << std::endl << "Please enter a valid filename to save images to (*.raw)." << std::endl;
	std::cout << "Leave empty to not save image." << std::endl;

	std::string filename;
	bool skip = false;
	while (filename.empty() && !skip)
	{
		std::getline(std::cin, filename);
		if (filename.empty())
		{
			skip = true;
			continue;
		}

		std::string folder = filename.substr(0, filename.find_last_of("/\\"));
		Architector::Dir dir(folder.c_str());
		if (!dir.exists())
		{
			std::cout << "Invalid folder: \"" << folder << "\", please enter a valid filename "
				"(e.g: \"C:\\temp\\test.raw)." << std::endl;
			filename.clear();
			continue;
		}

		std::string ext = filename.substr(filename.find_last_of("."));
		std::transform(ext.begin(), ext.end(), ext.begin(), tolower);
		if (ext != ".raw")
		{
			filename += ".raw";
		}
	}
	return filename;
}

/*!
	Saves as single channel of \a img to the file \a filename in raw format.

	If \a filename already exists, the existing file will be overwritten.
*/
void saveChannel(Architector::ImgRefPtr img, int channel, const std::string& filename)
{
	if (!img.isValid() || !img->channel(channel).isValid())
		return;

	std::ofstream file;
	file.open(filename.c_str(), std::ios_base::out | std::ios_base::binary);
	if (!file.is_open())
		return;

	file.imbue(std::locale::classic());

	Architector::ChannelRefPtr chRef = img->channel(channel);
	int channelSize = chRef->sizeInBytes(); //= width * height * pixelSize.

	char* data = reinterpret_cast<char*>(chRef->uint8Data());
	file.write(data, channelSize);
	file.close();
}

/*!
	Saves an image in raw format to file.

	If \a img has more than 1 channel, each channel gets its own file. Every file will then get a 
	numeric suffix. For example: if \a img has 3 channels and \a baseFilename is "C:/temp/Test.raw",
	then the following 3 files will be created:
	 - "C:/temp/Test_1_of_3.raw" for the first channel.
	 - "C:/temp/Test_2_of_3.raw" for the second channel.
	 - "C:/temp/Test_3_of_3.raw" for the third channel.
*/
void saveImage(Architector::ImgRefPtr img, const std::string& baseFilename)
{
	if (!img.isValid() || baseFilename.empty())
		return;

	if (img->channelCount() == 1)
	{
		saveChannel(img, 0, baseFilename);
		return;
	}

	size_t lastDot = baseFilename.find_last_of(".");
	std::string base = baseFilename.substr(0, lastDot);
	std::string ext = baseFilename.substr(lastDot);

	int channelCount = img->channelCount();
	std::stringstream sstream;
	std::string filename;
	for (int i = 0; i < channelCount; ++i)
	{
		sstream.str("");//empties the stream.
		sstream << base << "_Channel_" << (i + 1) << "_of_" << channelCount << ext;
		saveChannel(img, i, sstream.str());
	}
}

/*!
	Cleans up the used managers of the Architector library and unloads all plugins.
*/
Architector::ImgRefPtr takeSnapshot(Architector::DeviceRefPtr dev)
{
    Architector::ImgRefPtr img;
    dev->connect();
    dev->snapshot(img);
    dev->disconnect();
    return img;
}

void cleanup()
{
	//std::cout << "Cleaning up..." << std::endl;
	//std::cout << "Unloading plugins..." << std::endl;
	Architector::PluginLoader::get()->unloadAll();

	//std::cout << "Clearing managers..." << std::endl;
	Architector::BufferManager::get()->cleanUp();
	Architector::ImageManager::get()->cleanUp();
	Architector::DeviceManager::get()->cleanUp();
	Architector::FrameGrabberManager::get()->cleanUp();
	Architector::LogManager::get()->cleanUp();

	std::cout << "Cleanup complete." << std::endl;
}

/*!
	Cleans up and prints quit message and waits for user input before returning \a returnValue.
*/
int cleanupAndQuit(int returnValue)
{
	cleanup();
	std::cout << "Press 'enter' to quit." << std::endl;
	std::cin.get();
	return returnValue;
}


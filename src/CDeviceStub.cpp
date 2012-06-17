/************************************************************************/
/* Copyright (C) 2012-20112 OneDouble
/* This file is part of the "Double Engine".
/* dfghj77777@gmail.com                                                 
/************************************************************************/
#include "CDeviceStub.h"
#include "IDevice.h"
namespace doubal
{
//! constructor
CDeviceStub::CDeviceStub(const SCreationParameters& params)
: IDevice(), VideoDriver(0), GUIEnvironment(0), SceneManager(0),
	 UserReceiver(params.EventReceiver), Logger(0),//Timer(0), CursorControl(0), Operator(0),
	FileSystem(0), InputReceivingSceneManager(0), CreationParams(params),
	Close(false)
{
	/*Timer = new CTimer();
	if (os::Printer::Logger)
	{
		os::Printer::Logger->grab();
		Logger = (CLogger*)os::Printer::Logger;
		Logger->setReceiver(UserReceiver);
	}
	else
	{
		Logger = new CLogger(UserReceiver);
		os::Printer::Logger = Logger;
	}
	Logger->setLogLevel( CreationParams.LoggingLevel );

	os::Printer::Logger = Logger;

	FileSystem = io::createFileSystem();
	core::stringc s = "doubal Engine version ";
	s.append(getVersion());
	os::Printer::log(s.c_str(), ELL_INFORMATION);*/

	checkVersion(params.SDK_version_do_not_use);
}


CDeviceStub::~CDeviceStub()
{
	//FileSystem->drop();

	//if (GUIEnvironment)
	//	GUIEnvironment->drop();

	//if (VideoDriver)
	//	VideoDriver->drop();

	//if (SceneManager)
	//	SceneManager->drop();

	//if (InputReceivingSceneManager)
	//	InputReceivingSceneManager->drop();

	//if (CursorControl)
	//	CursorControl->drop();

	//if (Operator)
	//	Operator->drop();

	//CursorControl = 0;

	//Timer->drop();

	//if (Logger->drop())
	//	os::Printer::Logger = 0;
}


void CDeviceStub::createGUIAndScene()
{
	#ifdef _COMPILE_WITH_GUI_
	// create gui environment
	//GUIEnvironment = gui::createGUIEnvironment(FileSystem, VideoDriver, Operator);
	#endif

	// create Scene manager
	//SceneManager = scene::createSceneManager(VideoDriver, FileSystem, CursorControl, GUIEnvironment);

	setEventReceiver(UserReceiver);
}


//! returns the video driver
video::IVideoDriver* CDeviceStub::getVideoDriver()
{
	return VideoDriver;
}



//! return file system
io::IFileSystem* CDeviceStub::getFileSystem()
{
	return FileSystem;
}



//! returns the gui environment
gui::IGUIEnvironment* CDeviceStub::getGUIEnvironment()
{
	return GUIEnvironment;
}



//! returns the scene manager
scene::ISceneManager* CDeviceStub::getSceneManager()
{
	return SceneManager;
}

#if 0 
//! \return Returns a pointer to the ITimer object. With it the
//! current Time can be received.
ITimer* CDeviceStub::getTimer()
{
	return Timer;
}


//! Returns the version of the engine.
const char* CDeviceStub::getVersion() const
{
	return IRRLICHT_SDK_VERSION;
}

//! \return Returns a pointer to the mouse cursor control interface.
gui::ICursorControl* CDeviceStub::getCursorControl()
{
	return CursorControl;
}


//! \return Returns a pointer to a list with all video modes supported
//! by the gfx adapter.
video::IVideoModeList* CDeviceStub::getVideoModeList()
{
	return &VideoModeList;
}
#endif

//! checks version of sdk and prints warning if there might be a problem
bool CDeviceStub::checkVersion(const char* version)
{
	if (strcmp(getVersion(), version))
	{
		std::string w;
		w = "Warning: The library version of the Irrlicht Engine (";
		w += getVersion();
		w += ") does not match the version the application was compiled with (";
		w += version;
		w += "). This may cause problems.";
		//os::Printer::log(w.c_str(), ELL_WARNING);
		//_IRR_IMPLEMENT_MANAGED_MARSHALLING_BUGFIX;
		return false;
	}

	return true;
}

#if 0
//! Compares to the last call of this function to return double and triple clicks.
unsigned int CDeviceStub::checkSuccessiveClicks(int mouseX, int mouseY, EMOUSE_INPUT_EVENT inputEvent )
{
	const int MAX_MOUSEMOVE = 3;

	//doubal::unsigned int clickTime = getTimer()->getRealTime();

	//if ( (clickTime-MouseMultiClicks.LastClickTime) < MouseMultiClicks.DoubleClickTime
	//	&& core::abs_(MouseMultiClicks.LastClick.X - mouseX ) <= MAX_MOUSEMOVE
	//	&& core::abs_(MouseMultiClicks.LastClick.Y - mouseY ) <= MAX_MOUSEMOVE
	//	&& MouseMultiClicks.CountSuccessiveClicks < 3
	//	&& MouseMultiClicks.LastMouseInputEvent == inputEvent
	//   )
	//{
	//	++MouseMultiClicks.CountSuccessiveClicks;
	//}
	//else
	//{
	//	MouseMultiClicks.CountSuccessiveClicks = 1;
	//}

	//MouseMultiClicks.LastMouseInputEvent = inputEvent;
	MouseMultiClicks.LastClickTime = clickTime;
	MouseMultiClicks.LastClick.X = mouseX;
	MouseMultiClicks.LastClick.Y = mouseY;

	return MouseMultiClicks.CountSuccessiveClicks;
}


//! send the event to the right receiver
bool CDeviceStub::postEventFromUser(const SEvent& event)
{
	bool absorbed = false;

	if (UserReceiver)
		absorbed = UserReceiver->OnEvent(event);

	if (!absorbed && GUIEnvironment)
		absorbed = GUIEnvironment->postEventFromUser(event);

	scene::ISceneManager* inputReceiver = InputReceivingSceneManager;
	if (!inputReceiver)
		inputReceiver = SceneManager;

	if (!absorbed && inputReceiver)
		absorbed = inputReceiver->postEventFromUser(event);

	//_IMPLEMENT_MANAGED_MARSHALLING_BUGFIX;
	return absorbed;
}


//! Sets a new event receiver to receive events
void CDeviceStub::setEventReceiver(IEventReceiver* receiver)
{
	UserReceiver = receiver;
	Logger->setReceiver(receiver);
	if (GUIEnvironment)
		GUIEnvironment->setUserEventReceiver(receiver);
}

#endif
//! Returns poinhter to the current event receiver. Returns 0 if there is none.
//IEventReceiver* CDeviceStub::getEventReceiver()
//{
//	return UserReceiver;
//}


//! \return Returns a pointer to the logger.
//ILogger* CDeviceStub::getLogger()
//{
//	return Logger;
//}


//! Returns the operation system opertator object.
//IOSOperator* CDeviceStub::getOSOperator()
//{
//	return Operator;
//}


//! Sets the input receiving scene manager.
void CDeviceStub::setInputReceivingSceneManager(scene::ISceneManager* sceneManager)
{
    if (sceneManager)
        sceneManager->grab();
	if (InputReceivingSceneManager)
		InputReceivingSceneManager->drop();

	InputReceivingSceneManager = sceneManager;
}


//! Checks if the window is running in fullscreen mode
bool CDeviceStub::isFullscreen() const
{
	return CreationParams.Fullscreen;
}


//! returns color format
video::ECOLOR_FORMAT CDeviceStub::getColorFormat() const
{
	return video::ECF_R5G6B5;
}

//! No-op in this implementation
bool CDeviceStub::activateJoysticks(core::array<SJoystickInfo> & joystickInfo)
{
	return false;
}

/*!
*/
void CDeviceStub::calculateGammaRamp ( unsigned short *ramp, float gamma, float relativebrightness, float relativecontrast )
{
	int i;
	int value;
	int rbright = (int) ( relativebrightness * (65535.f / 4 ) );
	float rcontrast = 1.f / (255.f - ( relativecontrast * 127.5f ) );

	gamma = gamma > 0.f ? 1.0f / gamma : 0.f;

	for ( i = 0; i < 256; ++i )
	{
		value = (int)(pow( rcontrast * i, gamma)*65535.f + 0.5f );
		//ramp[i] = (unsigned short) core::s32_clamp ( value + rbright, 0, 65535 );
	}

}

void CDeviceStub::calculateGammaFromRamp ( float &gamma, const unsigned short *ramp )
{
	/* The following is adapted from a post by Garrett Bass on OpenGL
	Gamedev list, March 4, 2000.
	*/
	float sum = 0.0;
	int i, count = 0;

	gamma = 1.0;
	for ( i = 1; i < 256; ++i ) {
		if ( (ramp[i] != 0) && (ramp[i] != 65535) ) {
			float B = (float)i / 256.f;
			float A = ramp[i] / 65535.f;
			sum += (float) ( logf(A) / logf(B) );
			count++;
		}
	}
	if ( count && sum ) {
		gamma = 1.0f / (sum / count);
	}

}

//! Set the current Gamma Value for the Display
bool CDeviceStub::setGammaRamp( float red, float green, float blue, float brightness, float contrast )
{
	return false;
}

//! Get the current Gamma Value for the Display
bool CDeviceStub::getGammaRamp( float &red, float &green, float &blue, float &brightness, float &contrast )
{
	return false;
}

//! Set the maximal elapsed time between 2 clicks to generate doubleclicks for the mouse. It also affects tripleclick behaviour.
void CDeviceStub::setDoubleClickTime( unsigned int timeMs )
{
	MouseMultiClicks.DoubleClickTime = timeMs;
}

//! Get the maximal elapsed time between 2 clicks to generate double- and tripleclicks for the mouse.
unsigned int CDeviceStub::getDoubleClickTime() const
{
	return MouseMultiClicks.DoubleClickTime;
}

//! Remove all messages pending in the system message loop
void CDeviceStub::clearSystemMessages()
{
}



} // end namespace doubal


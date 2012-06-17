/************************************************************************/
/* Copyright (C) 2012-20112 OneDouble
/* This file is part of the "Double Engine".
/* dfghj77777@gmail.com                                                 
/************************************************************************/

#ifndef __C_DEVICE_STUB_H_
#define __C_DEVICE_STUB_H_


namespace doubal
{
	// lots of prototypes:
	class ILogger;
	class CLogger;

	namespace gui
	{
		class IGUIEnvironment;
		//IGUIEnvironment* createGUIEnvironment(io::IFileSystem* fs,
		//	video::IVideoDriver* Driver, IOSOperator* op);
	}

	namespace scene
	{
		//ISceneManager* createSceneManager(video::IVideoDriver* driver,
		//	io::IFileSystem* fs, gui::ICursorControl* cc, gui::IGUIEnvironment *gui);
	}

	namespace io
	{
		//IFileSystem* createFileSystem();
	}

	namespace video
	{
		//IVideoDriver* createSoftwareDriver(const core::dimension2d<unsigned int>& windowSize,
		//		bool fullscreen, io::IFileSystem* io,
		//		video::IImagePresenter* presenter);
		//IVideoDriver* createSoftwareDriver2(const core::dimension2d<unsigned int>& windowSize,
		//		bool fullscreen, io::IFileSystem* io,
		//		video::IImagePresenter* presenter);
		//IVideoDriver* createNullDriver(io::IFileSystem* io, const core::dimension2d<unsigned int>& screenSize);
	}



	//! Stub for an Irrlicht Device implementation
	class CDeviceStub : public IDevice
	{
	public:

		//! constructor
		CDeviceStub(const SCreationParameters& param);

		//! destructor
		virtual ~CDeviceStub();

		//! returns the video driver
		virtual video::IVideoDriver* getVideoDriver();

		//! return file system
		virtual io::IFileSystem* getFileSystem();

		//! returns the gui environment
		virtual gui::IGUIEnvironment* getGUIEnvironment();

		//! returns the scene manager
		virtual scene::ISceneManager* getSceneManager();

		//! \return Returns a pointer to the mouse cursor control interface.
		//virtual gui::ICursorControl* getCursorControl();

		//! Returns a pointer to a list with all video modes supported by the gfx adapter.
		//virtual video::IVideoModeList* getVideoModeList();

		//! Returns a pointer to the ITimer object. With it the current Time can be received.
		//virtual ITimer* getTimer();

		//! Returns the version of the engine.
		virtual const char* getVersion() const;

		//! send the event to the right receiver
		//virtual bool postEventFromUser(const SEvent& event);

		////! Sets a new event receiver to receive events
		virtual void setEventReceiver(IEventReceiver* receiver);

		//! Returns pointer to the current event receiver. Returns 0 if there is none.
		//virtual IEventReceiver* getEventReceiver();

		//! Sets the input receiving scene manager.
		/** If set to null, the main scene manager (returned by GetSceneManager()) will receive the input */
		virtual void setInputReceivingSceneManager(scene::ISceneManager* sceneManager);

		//! Returns a pointer to the logger.
		//virtual ILogger* getLogger();

		//! Returns the operation system opertator object.
		//virtual IOSOperator* getOSOperator();

		//! Checks if the window is running in fullscreen mode.
		virtual bool isFullscreen() const;

		//! get color format of the current window
		virtual video::ECOLOR_FORMAT getColorFormat() const;

		//! Activate any joysticks, and generate events for them.
		//virtual bool activateJoysticks(core::array<SJoystickInfo> & joystickInfo);

		//! Set the current Gamma Value for the Display
		virtual bool setGammaRamp( float red, float green, float blue, float brightness, float contrast );

		//! Get the current Gamma Value for the Display
		virtual bool getGammaRamp( float &red, float &green, float &blue, float &brightness, float &contrast );

		//! Set the maximal elapsed time between 2 clicks to generate doubleclicks for the mouse. It also affects tripleclick behaviour.
		//! When set to 0 no double- and tripleclicks will be generated.
		virtual void setDoubleClickTime( unsigned int timeMs );

		//! Get the maximal elapsed time between 2 clicks to generate double- and tripleclicks for the mouse.
		virtual unsigned int getDoubleClickTime() const;

		//! Remove all messages pending in the system message loop
		virtual void clearSystemMessages();


	protected:

		void createGUIAndScene();

		//! checks version of SDK and prints warning if there might be a problem
		bool checkVersion(const char* version);

		//! Compares to the last call of this function to return double and triple clicks.
		//! \return Returns only 1,2 or 3. A 4th click will start with 1 again.
		//virtual unsigned int checkSuccessiveClicks(int mouseX, int mouseY, EMOUSE_INPUT_EVENT inputEvent );

		void calculateGammaRamp ( unsigned short *ramp, float gamma, float relativebrightness, float relativecontrast );
		void calculateGammaFromRamp ( float &gamma, const unsigned short *ramp );

		video::IVideoDriver* VideoDriver;
		gui::IGUIEnvironment* GUIEnvironment;
		scene::ISceneManager* SceneManager;
		//ITimer* Timer;
		//gui::ICursorControl* CursorControl;
		IEventReceiver* UserReceiver;
		CLogger* Logger;
		//IOSOperator* Operator;
		io::IFileSystem* FileSystem;
		scene::ISceneManager* InputReceivingSceneManager;

		struct SMouseMultiClicks
		{
			SMouseMultiClicks()
				: DoubleClickTime(500), CountSuccessiveClicks(0), LastClickTime(0)//, LastMouseInputEvent(EMIE_COUNT)
			{}

			unsigned int DoubleClickTime;
			unsigned int CountSuccessiveClicks;
			unsigned int LastClickTime;
			core::position2di LastClick;
			//EMOUSE_INPUT_EVENT LastMouseInputEvent;
		};
		SMouseMultiClicks MouseMultiClicks;
		//video::CVideoModeList VideoModeList;
		SCreationParameters CreationParams;
		bool Close;
	};

} // end namespace doubal

#endif


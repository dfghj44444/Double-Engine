/************************************************************************/
/* Copyright (C) 2012-20112 OneDouble
/* This file is part of the "Double Engine".
/* dfghj77777@gmail.com                                                 
/************************************************************************/
#ifndef _DEVICE_H_
#define _DEVICE_H_
#include "CDeviceWin32.h"
namespace doubal
{

	extern "C" DLL_EXPORT IDevice* CALLBACK createDevice(
		video::E_DRIVER_TYPE deviceType = video::EDT_SOFTWARE,
		// parantheses are necessary for some compilers
		const core::dimension2d<unsigned int>& windowSize = (core::dimension2d<unsigned int>(640,480)),
		unsigned int bits = 16,
		bool fullscreen = false,
		bool stencilbuffer = false,
		bool vsync = false,
		IEventReceiver* receiver = 0);

	//! typedef for Function Pointer
	typedef IDevice* (CALLBACK *funcptr_createDevice )(
			video::E_DRIVER_TYPE deviceType,
			const core::dimension2d<unsigned int>& windowSize,
			unsigned int bits,
			bool fullscreen,
			bool stencilbuffer,
			bool vsync,
			IEventReceiver* receiver);


	//! Creates an double device with the option to specify advanced parameters.
	/** Usually you should used createDevice() for creating an double Engine device.
	Use this function only if you wish to specify advanced parameters like a window
	handle in which the device should be created.
	\param parameters: Structure containing advanced parameters for the creation of the device.
	See double::SdoubleCreationParameters for details.
	\return Returns pointer to the created doubleDevice or null if the
	device could not be created. */
	extern "C" DLL_EXPORT IDevice* CALLBACK createDeviceEx(
		const SCreationParameters& parameters);

	//! typedef for Function Pointer
	typedef IDevice* (CALLBACK *funcptr_createDeviceEx )( const SCreationParameters& parameters );


	// THE FOLLOWING IS AN EMPTY LIST OF ALL SUB NAMESPACES
	// EXISTING ONLY FOR THE DOCUMENTATION SOFTWARE DOXYGEN.

	//! Basic classes such as vectors, planes, arrays, lists, and so on can be found in this namespace.
	namespace core
	{
	}

	//! The gui namespace contains useful classes for easy creation of a graphical user interface.
	namespace gui
	{
	}

	//! This namespace provides interfaces for input/output: Reading and writing files, accessing zip archives, xml files, ...
	namespace io
	{
	}

	//! All scene management can be found in this namespace: Mesh loading, special scene nodes like octrees and billboards, ...
	namespace scene
	{
	}

	//! The video namespace contains classes for accessing the video driver. All 2d and 3d rendering is done here.
	namespace video
	{
	}
}

/*! \file double.h
	\brief Main header file of the double, the only file needed to include.
*/

#endif


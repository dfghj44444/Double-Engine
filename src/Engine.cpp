/************************************************************************/
/* Copyright (C) 2012-20112 OneDouble
/* This file is part of the "Double Engine".
/* dfghj77777@gmail.com                                                 
/************************************************************************/
#include "CDeviceWin32.h"

static const char* const copyright = "Copyright (C) 2012-20112 OneDouble";

#ifdef _WINDOWS
	#include <windows.h>
	#if defined(_DEBUG) && !defined(__GNUWIN32__) && !defined(_WIN32_WCE)
		#include <crtdbg.h>
	#endif // _DEBUG
#endif

namespace doubal
{
	//! stub for calling createDeviceEx
	extern "C" DLL_EXPORT  IDevice* CALLBACK createDevice(video::E_DRIVER_TYPE driverType,
			const core::dimension2d<unsigned int>& windowSize,
			unsigned int bits, bool fullscreen,
			bool stencilbuffer, bool vsync, IEventReceiver* res)
	{
		SCreationParameters p;
		p.DriverType = driverType;
		p.WindowSize = windowSize;
		p.Bits = (char)bits;
		p.Fullscreen = fullscreen;
		p.Stencilbuffer = stencilbuffer;
		p.Vsync = vsync;
		p.EventReceiver = res;

		return createDeviceEx(p);
	}

	extern "C" DLL_EXPORT IDevice* CALLBACK createDeviceEx(const SCreationParameters& params)
	{

		IDevice* dev = 0;

#ifdef _WINDOWS
		if (params.DeviceType == EIDT_WIN32 || (!dev && params.DeviceType == EIDT_BEST))
			dev = new CDeviceWin32(params);
#endif



		if (dev && !dev->getVideoDriver() && params.DriverType != video::EDT_NULL)
		{
			dev->closeDevice(); // destroy window
			dev->run(); // consume quit message
			dev = 0;
		}

		return dev;
	}

namespace core
{
	const matrix4 IdentityMatrix(matrix4::EM4CONST_IDENTITY);
}

namespace video
{
	//SMaterial IdentityMaterial;
}

} // end namespace double


#if defined(_double_WINDOWS_API_)

BOOL APIENTRY DllMain( HANDLE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved )
{
	// _crtBreakAlloc = 139;

    switch (ul_reason_for_call)
	{
		case DLL_PROCESS_ATTACH:
			#if defined(_DEBUG) && !defined(__GNUWIN32__) && !defined(__BORLANDC__) && !defined (_WIN32_WCE) && !defined (_double_XBOX_PLATFORM_)
				_CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF);
			#endif
			break;
		case DLL_THREAD_ATTACH:
		case DLL_THREAD_DETACH:
		case DLL_PROCESS_DETACH:
			break;
    }
    return TRUE;
}

#endif // defined(_double_WINDOWS_)


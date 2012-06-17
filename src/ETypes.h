/************************************************************************/
/* Copyright (C) 2012-20112 OneDouble
/* This file is part of the "Double Engine".
/* dfghj77777@gmail.com                                                 
/************************************************************************/


#ifndef __E_TYPES_H_
#define __E_TYPES_H_

namespace doubal
{
		//! An enum for the different device types supported by the Irrlicht Engine.
	enum E_DEVICE_TYPE
	{

		//! A device native to Microsoft Windows
		/** This device uses the Win32 API and works in all versions of Windows. */
		EIDT_WIN32,

		//! A device native to Windows CE devices
		/** This device works on Windows Mobile, Pocket PC and Microsoft SmartPhone devices */
		EIDT_WINCE,

		//! A device native to Unix style operating systems.
		/** This device uses the X11 windowing system and works in Linux, Solaris, FreeBSD, OSX and
		other operating systems which support X11. */
		EIDT_X11,

		//! A device native to Mac OSX
		/** This device uses Apple's Cocoa API and works in Mac OSX 10.2 and above. */
		EIDT_OSX,

		//! A device which uses Simple DirectMedia Layer
		/** The SDL device works under all platforms supported by SDL but first must be compiled
		in by defining the IRR_USE_SDL_DEVICE macro in IrrCompileConfig.h */
		EIDT_SDL,

		//! A device for raw framebuffer access
		/** Best used with embedded devices and mobile systems.
		Does not need X11 or other graphical subsystems.
		May support hw-acceleration via OpenGL-ES for FBDirect */
		EIDT_FRAMEBUFFER,

		//! A simple text only device supported by all platforms.
		/** This device allows applications to run from the command line without opening a window.
		It can render the output of the software drivers to the console as ASCII. It only supports
		mouse and keyboard in Windows operating systems. */
		EIDT_CONSOLE,

		//! This selection allows Irrlicht to choose the best device from the ones available.
		/** If this selection is chosen then Irrlicht will try to use the IrrlichtDevice native
		to your operating system. If this is unavailable then the X11, SDL and then console device
		will be tried. This ensures that Irrlicht will run even if your platform is unsupported,
		although it may not be able to render anything. */
		EIDT_BEST
	};
namespace video
{

	//! An enum for all types of drivers the doubal Engine supports.
	enum E_DRIVER_TYPE
	{
		//able to load textures, but does not render and display any graphics. 
		EDT_NULL,

		/** Runs on all platforms, with every hardware. It should only	be used for 2d graphics, but it can also perform some primitive
		3d functions. These 3d drawing functions are quite fast, but very inaccurate, and don't even support clipping in 3D mode. */
		EDT_SOFTWARE,

		//! The Burning's Software Renderer, an alternative software renderer
		/** Basically it can be described as the doubal Software
		renderer on steroids. It rasterizes 3D geometry perfectly: It
		is able to perform correct 3d clipping, perspective correct
		texture mapping, perspective correct color mapping, and renders
		sub pixel correct, sub texel correct primitives. In addition,
		it does bilinear texel filtering and supports more materials
		than the EDT_SOFTWARE driver. This renderer has been written
		entirely by Thomas Alten, thanks a lot for this huge
		contribution. */
		EDT_BURNINGSVIDEO,

		//! Direct3D 9 device, only available on Win32 platforms.
		/** Performs hardware accelerated rendering of 3D and 2D
		primitives. */
		EDT_DIRECT3D9,
		EDT_COUNT
	};

	//! enumeration for querying features of the video driver.
	enum E_VIDEO_DRIVER_FEATURE
	{
		//! Is driver able to render to a surface?
		EVDF_RENDER_TO_TARGET = 0,

		//! Is hardeware transform and lighting supported?
		EVDF_HARDWARE_TL,

		//! Are multiple textures per material possible?
		EVDF_MULTITEXTURE,

		//! Is driver able to render with a bilinear filter applied?
		EVDF_BILINEAR_FILTER,

		//! Can the driver handle mip maps?
		EVDF_MIP_MAP,

		//! Can the driver update mip maps automatically?
		EVDF_MIP_MAP_AUTO_UPDATE,

		//! Are stencilbuffers switched on and does the device support stencil buffers?
		EVDF_STENCIL_BUFFER,

		//! Is Vertex Shader 1.1 supported?
		EVDF_VERTEX_SHADER_1_1,

		//! Is Vertex Shader 2.0 supported?
		EVDF_VERTEX_SHADER_2_0,

		//! Is Vertex Shader 3.0 supported?
		EVDF_VERTEX_SHADER_3_0,

		//! Is Pixel Shader 1.1 supported?
		EVDF_PIXEL_SHADER_1_1,

		//! Is Pixel Shader 1.2 supported?
		EVDF_PIXEL_SHADER_1_2,

		//! Is Pixel Shader 1.3 supported?
		EVDF_PIXEL_SHADER_1_3,

		//! Is Pixel Shader 1.4 supported?
		EVDF_PIXEL_SHADER_1_4,

		//! Is Pixel Shader 2.0 supported?
		EVDF_PIXEL_SHADER_2_0,

		//! Is Pixel Shader 3.0 supported?
		EVDF_PIXEL_SHADER_3_0,

		//! Are ARB vertex programs v1.0 supported?
		EVDF_ARB_VERTEX_PROGRAM_1,

		//! Are ARB fragment programs v1.0 supported?
		EVDF_ARB_FRAGMENT_PROGRAM_1,

		//! Is GLSL supported?
		EVDF_ARB_GLSL,

		//! Is HLSL supported?
		EVDF_HLSL,

		//! Are non-square textures supported?
		EVDF_TEXTURE_NSQUARE,

		//! Are non-power-of-two textures supported?
		EVDF_TEXTURE_NPOT,

		//! Are framebuffer objects supported?
		EVDF_FRAMEBUFFER_OBJECT,

		//! Are vertex buffer objects supported?
		EVDF_VERTEX_BUFFER_OBJECT,

		//! Supports Alpha To Coverage
		EVDF_ALPHA_TO_COVERAGE,

		//! Supports Color masks (disabling color planes in output)
		EVDF_COLOR_MASK,

		//! Supports multiple render targets at once
		EVDF_MULTIPLE_RENDER_TARGETS,

		//! Supports separate blend settings for multiple render targets
		EVDF_MRT_BLEND,

		//! Supports separate color masks for multiple render targets
		EVDF_MRT_COLOR_MASK,

		//! Supports separate blend functions for multiple render targets
		EVDF_MRT_BLEND_FUNC,

		//! Supports geometry shaders
		EVDF_GEOMETRY_SHADER,

		//! Only used for counting the elements of this enum
		EVDF_COUNT
	};

	//! Enumeration for all vertex types there are.
	enum E_VERTEX_TYPE
	{
		//! Standard vertex type used by the Irrlicht engine, video::S3DVertex.
		EVT_STANDARD = 0,

		//! Vertex with two texture coordinates, video::S3DVertex2TCoords.
		/** Usually used for geometry with lightmaps or other special materials. */
		EVT_2TCOORDS,

		//! Vertex with a tangent and binormal vector, video::S3DVertexTangents.
		/** Usually used for tangent space normal mapping. */
		EVT_TANGENTS
	};

	enum E_INDEX_TYPE
	{
		EIT_16BIT = 0,
		EIT_32BIT
	};

	enum ECOLOR_FORMAT
	{
	//! 16 bit color format used by the software driver.
	/** It is thus preferred by all other irrlicht engine video drivers.
	There are 5 bits for every color component, and a single bit is left
	for alpha information. */
	ECF_A1R5G5B5 = 0,

	//! Standard 16 bit color format.
	ECF_R5G6B5,

	//! 24 bit color, no alpha channel, but 8 bit for red, green and blue.
	ECF_R8G8B8,

	//! Default 32 bit color format. 8 bits are used for every component: red, green, blue and alpha.
	ECF_A8R8G8B8,

	/** Floating Point formats. The following formats may only be used for render target textures. */

	//! 16 bit floating point format using 16 bits for the red channel.
	ECF_R16F,

	//! 32 bit floating point format using 16 bits for the red channel and 16 bits for the green channel.
	ECF_G16R16F,

	//! 64 bit floating point format 16 bits are used for the red, green, blue and alpha channels.
	ECF_A16B16G16R16F,

	//! 32 bit floating point format using 32 bits for the red channel.
	ECF_R32F,

	//! 64 bit floating point format using 32 bits for the red channel and 32 bits for the green channel.
	ECF_G32R32F,

	//! 128 bit floating point format. 32 bits are used for the red, green, blue and alpha channels.
	ECF_A32B32G32R32F,

	//! Unknown color format:
	ECF_UNKNOWN
	};


} // end namespace video

namespace scene
{
	enum E_PRIMITIVE_TYPE
	{
		//! All vertices are non-connected points.
		EPT_POINTS=0,

		//! All vertices form a single connected line.
		EPT_LINE_STRIP,

		//! Just as LINE_STRIP, but the last and the first vertex is also connected.
		EPT_LINE_LOOP,

		//! Every two vertices are connected creating n/2 lines.
		EPT_LINES,

		//! After the first two vertices each vertex defines a new triangle.
		//! Always the two last and the new one form a new triangle.
		EPT_TRIANGLE_STRIP,

		//! After the first two vertices each vertex defines a new triangle.
		//! All around the common first vertex.
		EPT_TRIANGLE_FAN,

		//! Explicitly set all vertices for each triangle.
		EPT_TRIANGLES,

		//! After the first two vertices each further tw vetices create a quad with the preceding two.
		EPT_QUAD_STRIP,

		//! Every four vertices create a quad.
		EPT_QUADS,

		//! Just as LINE_LOOP, but filled.
		EPT_POLYGON,

		//! The single vertices are expanded to quad billboards on the GPU.
		EPT_POINT_SPRITES
	};
}

//! Enumeration for all mouse input events
enum EMOUSE_INPUT_EVENT
{
	//! Left mouse button was pressed down.
	EMIE_LMOUSE_PRESSED_DOWN = 0,

	//! Right mouse button was pressed down.
	EMIE_RMOUSE_PRESSED_DOWN,

	//! Middle mouse button was pressed down.
	EMIE_MMOUSE_PRESSED_DOWN,

	//! Left mouse button was left up.
	EMIE_LMOUSE_LEFT_UP,

	//! Right mouse button was left up.
	EMIE_RMOUSE_LEFT_UP,

	//! Middle mouse button was left up.
	EMIE_MMOUSE_LEFT_UP,

	//! The mouse cursor changed its position.
	EMIE_MOUSE_MOVED,

	//! The mouse wheel was moved. Use Wheel value in event data to find out
	//! in what direction and how fast.
	EMIE_MOUSE_WHEEL,

	//! Left mouse button double click.
	//! This event is generated after the second EMIE_LMOUSE_PRESSED_DOWN event.
	EMIE_LMOUSE_DOUBLE_CLICK,

	//! Right mouse button double click.
	//! This event is generated after the second EMIE_RMOUSE_PRESSED_DOWN event.
	EMIE_RMOUSE_DOUBLE_CLICK,

	//! Middle mouse button double click.
	//! This event is generated after the second EMIE_MMOUSE_PRESSED_DOWN event.
	EMIE_MMOUSE_DOUBLE_CLICK,

	//! Left mouse button triple click.
	//! This event is generated after the third EMIE_LMOUSE_PRESSED_DOWN event.
	EMIE_LMOUSE_TRIPLE_CLICK,

	//! Right mouse button triple click.
	//! This event is generated after the third EMIE_RMOUSE_PRESSED_DOWN event.
	EMIE_RMOUSE_TRIPLE_CLICK,

	//! Middle mouse button triple click.
	//! This event is generated after the third EMIE_MMOUSE_PRESSED_DOWN event.
	EMIE_MMOUSE_TRIPLE_CLICK,

	//! No real event. Just for convenience to get number of events
	EMIE_COUNT
};

} // end namespace doubal


#endif


/************************************************************************/
/* Copyright (C) 2012-20112 OneDouble
/* This file is part of the "Double Engine".
/* dfghj77777@gmail.com                                                 
/************************************************************************/

#ifndef _COMPILE_CONFIG_H_
#define _COMPILE_CONFIG_H_


#define DOUBLE_SDK_VERSION "1.0"

//! Uncomment this line to compile with the SDL device
//#define _COMPILE_WITH_SDL_DEVICE_

//! Comment this line to compile without the fallback console device.
//#define _COMPILE_WITH_CONSOLE_DEVICE_

//! WIN32 for Windows32
//! WIN64 for Windows64
// The windows platform and API support SDL and WINDOW device
#if defined(_WIN32) || defined(_WIN64) || defined(WIN32) || defined(WIN64)
#define _WINDOWS_
#define _WINDOWS_API_
#define _COMPILE_WITH_WINDOWS_DEVICE_
#endif

#if defined(_MSC_VER) && (_MSC_VER < 1300)
#  error "Only Microsoft Visual Studio 7.0 and later are supported."
#endif


//! if you want joystick events.
#define _COMPILE_WITH_JOYSTICK_EVENTS_

//! Maximum number of texture an SMaterial can have, up to 8 are supported
#define _MATERIAL_MAX_TEXTURES_ 4


#if defined(_WINDOWS_API_) && (!defined(__GNUC__) || defined(_COMPILE_WITH_DX9_DEV_PACK))

//! Only define _COMPILE_WITH_DIRECT3D_8_ if you have an appropriate DXSDK
#define _COMPILE_WITH_DIRECT3D_8_
#define _COMPILE_WITH_DIRECT3D_9_

#endif

#define __COMPILE_WITH_OPENGL_

#define _COMPILE_WITH_SOFTWARE_

//#define __COMPILE_WITH_BURNINGSVIDEO_

// Only used in LinuxDevice.
//#define _COMPILE_WITH_X11_


/** Disable this if you are using an external library to draw the GUI. If you disable this then
you will not be able to use anything provided by the GUI Environment, including loading fonts. */
//#define __COMPILE_WITH_GUI_


/** This enables the engine to read/write from unicode filesystem. If you
disable this feature, the engine behave as before (ansi). This is currently only supported
for Windows based systems. */
#define _WCHAR_FILESYSTEM

/** This enables the engine to read jpeg images. If you comment this out,
the engine will no longer read .jpeg images. */
#define _COMPILE_WITH_LIBJPEG_

//! Define _USE_NON_SYSTEM_JPEG_LIB_ to let engine use the jpeglib which comes with engine.
/** If this is commented out,The Engine will try to compile using the jpeg lib installed in the system.
	This is only used when _COMPILE_WITH_LIBJPEG_ is defined. */
#define _USE_NON_SYSTEM_JPEG_LIB_


//! Define _COMPILE_WITH_LIBPNG_ to enable compiling the engine using libpng.
/** This enables the engine to read png images. If you comment this out,
the engine will no longer read .png images. */
#define _COMPILE_WITH_LIBPNG_

//! Define _USE_NON_SYSTEM_LIBPNG_ to let engine use the libpng which comes with engine.
/** If this is commented out, engine will try to compile using the libpng installed in the system.
	This is only used when _COMPILE_WITH_LIBPNG_ is defined. */
#define _USE_NON_SYSTEM_LIB_PNG_


//! Define _D3D_NO_SHADER_DEBUGGING to disable shader debugging in D3D9
#define _D3D_NO_SHADER_DEBUGGING

//! Define _D3D_USE_LEGACY_HLSL_COMPILER to enable the old HLSL compiler in recent DX SDKs
/** This enables support for ps_1_x shaders for recent DX SDKs. Otherwise, support
for this shader model is not available anymore in SDKs after Oct2006. You need to
distribute the OCT2006_d3dx9_31_x86.cab or OCT2006_d3dx9_31_x64.cab though, in order
to provide the user with the proper DLL. That's why it's disabled by default. */
//#define _D3D_USE_LEGACY_HLSL_COMPILER

//! Define _USE_NVIDIA_PERFHUD_ to opt-in to using the nVidia PerHUD tool
/** Enable, by opting-in, to use the nVidia PerfHUD performance analysis driver
tool <http://developer.nvidia.com/object/nvperfhud_home.html>. */
#undef _USE_NVIDIA_PERFHUD_

//! Define one of the three setting for Burning's Video Software Rasterizer
/** So if we were marketing guys we could say engine has 4 Software-Rasterizers.
	In a Nutshell:
		All Burnings Rasterizers use 32 Bit Backbuffer, 32Bit Texture & 32 Bit Z or WBuffer,
		16 Bit/32 Bit can be adjusted on a global flag.

		BURNINGVIDEO_RENDERER_BEAUTIFUL
			32 Bit + Vertexcolor + Lighting + Per Pixel Perspective Correct + SubPixel/SubTexel Correct +
			Bilinear Texturefiltering + WBuffer

		BURNINGVIDEO_RENDERER_FAST
			32 Bit + Per Pixel Perspective Correct + SubPixel/SubTexel Correct + WBuffer +
			Bilinear Dithering TextureFiltering + WBuffer

		BURNINGVIDEO_RENDERER_ULTRA_FAST
			16Bit + SubPixel/SubTexel Correct + ZBuffer
*/

#define BURNINGVIDEO_RENDERER_BEAUTIFUL
//#define BURNINGVIDEO_RENDERER_FAST
//#define BURNINGVIDEO_RENDERER_ULTRA_FAST
//#define BURNINGVIDEO_RENDERER_CE

//! Uncomment the following line if you want to ignore the deprecated warnings
//#define IGNORE_DEPRECATED_WARNING

//! Define _COMPILE_WITH_SKINNED_MESH_SUPPORT_ if you want to use bone based
/** animated meshes. If you compile without this, you will be unable to load
B3D, MS3D or X meshes */
#define _COMPILE_WITH_SKINNED_MESH_SUPPORT_

#ifdef _COMPILE_WITH_SKINNED_MESH_SUPPORT_
//! Define _COMPILE_WITH_B3D_LOADER_ if you want to use Blitz3D files
#define _COMPILE_WITH_B3D_LOADER_
//! Define _COMPILE_WITH_MS3D_LOADER_ if you want to Milkshape files
#define _COMPILE_WITH_MS3D_LOADER_
//! Define _COMPILE_WITH_X_LOADER_ if you want to use Microsoft X files
#define _COMPILE_WITH_X_LOADER_
//! Define _COMPILE_WITH_OGRE_LOADER_ if you want to load Ogre 3D files
#define _COMPILE_WITH_OGRE_LOADER_
#endif

//! Define _COMPILE_WITH_MESH_LOADER_ if you want to load engine Engine .irrmesh files
#define _COMPILE_WITH_MESH_LOADER_

//! Define _COMPILE_WITH_MD2_LOADER_ if you want to load Quake 2 animated files
#define _COMPILE_WITH_MD2_LOADER_
//! Define _COMPILE_WITH_MD3_LOADER_ if you want to load Quake 3 animated files
#define _COMPILE_WITH_MD3_LOADER_

//! Define _COMPILE_WITH_3DS_LOADER_ if you want to load 3D Studio Max files
#define _COMPILE_WITH_3DS_LOADER_
//! Define _COMPILE_WITH_COLLADA_LOADER_ if you want to load Collada files
#define _COMPILE_WITH_COLLADA_LOADER_
//! Define _COMPILE_WITH_CSM_LOADER_ if you want to load Cartography Shop files
#define _COMPILE_WITH_CSM_LOADER_
//! Define _COMPILE_WITH_BSP_LOADER_ if you want to load Quake 3 BSP files
#define _COMPILE_WITH_BSP_LOADER_
//! Define _COMPILE_WITH_DMF_LOADER_ if you want to load DeleD files
#define _COMPILE_WITH_DMF_LOADER_
//! Define _COMPILE_WITH_LMTS_LOADER_ if you want to load LMTools files
#define _COMPILE_WITH_LMTS_LOADER_
//! Define _COMPILE_WITH_MY3D_LOADER_ if you want to load MY3D files
#define _COMPILE_WITH_MY3D_LOADER_
//! Define _COMPILE_WITH_OBJ_LOADER_ if you want to load Wavefront OBJ files
#define _COMPILE_WITH_OBJ_LOADER_
//! Define _COMPILE_WITH_OCT_LOADER_ if you want to load FSRad OCT files
#define _COMPILE_WITH_OCT_LOADER_
//! Define _COMPILE_WITH_LWO_LOADER_ if you want to load Lightwave3D files
#define _COMPILE_WITH_LWO_LOADER_
//! Define _COMPILE_WITH_STL_LOADER_ if you want to load stereolithography files
#define _COMPILE_WITH_STL_LOADER_
//! Define _COMPILE_WITH_PLY_LOADER_ if you want to load Polygon (Stanford Triangle) files
#define _COMPILE_WITH_PLY_LOADER_

//! Define _COMPILE_WITH_WRITER_ if you want to write static .irrMesh files
#define _COMPILE_WITH_WRITER_
//! Define _COMPILE_WITH_COLLADA_WRITER_ if you want to write Collada files
#define _COMPILE_WITH_COLLADA_WRITER_
//! Define _COMPILE_WITH_STL_WRITER_ if you want to write .stl files
#define _COMPILE_WITH_STL_WRITER_
//! Define _COMPILE_WITH_OBJ_WRITER_ if you want to write .obj files
#define _COMPILE_WITH_OBJ_WRITER_
//! Define _COMPILE_WITH_PLY_WRITER_ if you want to write .ply files
#define _COMPILE_WITH_PLY_WRITER_

//! Define _COMPILE_WITH_BMP_LOADER_ if you want to load .bmp files
//! Disabling this loader will also disable the built-in font
#define _COMPILE_WITH_BMP_LOADER_
//! Define _COMPILE_WITH_JPG_LOADER_ if you want to load .jpg files
#define _COMPILE_WITH_JPG_LOADER_
//! Define _COMPILE_WITH_PCX_LOADER_ if you want to load .pcx files
#define _COMPILE_WITH_PCX_LOADER_
//! Define _COMPILE_WITH_PNG_LOADER_ if you want to load .png files
#define _COMPILE_WITH_PNG_LOADER_
//! Define _COMPILE_WITH_PPM_LOADER_ if you want to load .ppm/.pgm/.pbm files
#define _COMPILE_WITH_PPM_LOADER_
//! Define _COMPILE_WITH_PSD_LOADER_ if you want to load .psd files
#define _COMPILE_WITH_PSD_LOADER_
//! Define _COMPILE_WITH_TGA_LOADER_ if you want to load .tga files
#define _COMPILE_WITH_TGA_LOADER_
//! Define _COMPILE_WITH_WAL_LOADER_ if you want to load .wal files
#define _COMPILE_WITH_WAL_LOADER_
//! Define _COMPILE_WITH_RGB_LOADER_ if you want to load Silicon Graphics .rgb/.rgba/.sgi/.int/.inta/.bw files
#define _COMPILE_WITH_RGB_LOADER_

//! Define _COMPILE_WITH_BMP_WRITER_ if you want to write .bmp files
#define _COMPILE_WITH_BMP_WRITER_
//! Define _COMPILE_WITH_JPG_WRITER_ if you want to write .jpg files
#define _COMPILE_WITH_JPG_WRITER_
//! Define _COMPILE_WITH_PCX_WRITER_ if you want to write .pcx files
#define _COMPILE_WITH_PCX_WRITER_
//! Define _COMPILE_WITH_PNG_WRITER_ if you want to write .png files
#define _COMPILE_WITH_PNG_WRITER_
//! Define _COMPILE_WITH_PPM_WRITER_ if you want to write .ppm files
#define _COMPILE_WITH_PPM_WRITER_
//! Define _COMPILE_WITH_PSD_WRITER_ if you want to write .psd files
#define _COMPILE_WITH_PSD_WRITER_
//! Define _COMPILE_WITH_TGA_WRITER_ if you want to write .tga files
#define _COMPILE_WITH_TGA_WRITER_

//! Define __COMPILE_WITH_ZIP_ARCHIVE_LOADER_ if you want to open ZIP and GZIP archives
/** ZIP reading has several more options below to configure. */
#define __COMPILE_WITH_ZIP_ARCHIVE_LOADER_
#ifdef __COMPILE_WITH_ZIP_ARCHIVE_LOADER_
//! Define _COMPILE_WITH_ZLIB_ to enable compiling the engine using zlib.
/** This enables the engine to read from compressed .zip archives. If you
disable this feature, the engine can still read archives, but only uncompressed
ones. */
#define _COMPILE_WITH_ZLIB_
//! Define _USE_NON_SYSTEM_ZLIB_ to let engine use the zlib which comes with engine.
/** If this is commented out, engine will try to compile using the zlib
installed on the system. This is only used when _COMPILE_WITH_ZLIB_ is
defined. */
#define _USE_NON_SYSTEM_ZLIB_
//! Define _COMPILE_WITH_ZIP_ENCRYPTION_ if you want to read AES-encrypted ZIP archives
#define _COMPILE_WITH_ZIP_ENCRYPTION_
//! Define _COMPILE_WITH_BZIP2_ if you want to support bzip2 compressed zip archives
/** bzip2 is superior to the original zip file compression modes, but requires
a certain amount of memory for decompression and adds several files to the
library. */
#define _COMPILE_WITH_BZIP2_
//! Define _USE_NON_SYSTEM_BZLIB_ to let engine use the bzlib which comes with engine.
/** If this is commented out, engine will try to compile using the bzlib
installed on the system. This is only used when _COMPILE_WITH_BZLIB_ is
defined. */
#define _USE_NON_SYSTEM_BZLIB_
//! Define _COMPILE_WITH_LZMA_ if you want to use LZMA compressed zip files.
/** LZMA is a very efficient compression code, known from 7zip. engine
currently only supports zip archives, though. */
#define _COMPILE_WITH_LZMA_
#endif

//! Define _COMPILE_WITH_MOUNT_ARCHIVE_LOADER_ if you want to mount folders as archives
#define _COMPILE_WITH_MOUNT_ARCHIVE_LOADER_
//! Define _COMPILE_WITH_PAK_ARCHIVE_LOADER_ if you want to open ID software PAK archives
#define _COMPILE_WITH_PAK_ARCHIVE_LOADER_
//! Define _COMPILE_WITH_NPK_ARCHIVE_LOADER_ if you want to open Nebula Device NPK archives
#define _COMPILE_WITH_NPK_ARCHIVE_LOADER_
//! Define _COMPILE_WITH_TAR_ARCHIVE_LOADER_ if you want to open TAR archives
#define _COMPILE_WITH_TAR_ARCHIVE_LOADER_


#ifdef _WINDOWS_API_

#ifdef _LIB
#define DLL_EXPORT __declspec(dllimport)
#else
#define DLL_EXPORT __declspec(dllexport)
#endif // _LIB


#endif // _WINDOWS_API_

// We need to disable DIRECT3D9 support for Visual Studio 6.0 because
// those $%&$!! disabled support for it since Dec. 2004 and users are complaining
// about linker errors. Comment this out only if you are knowing what you are
// doing. (Which means you have an old DX9 SDK and VisualStudio6).
#ifdef _MSC_VER
#if (_MSC_VER < 1300 && !defined(__GNUC__))
#undef _COMPILE_WITH_DIRECT3D_9_
#pragma message("Compiling engine with Visual Studio 6.0, support for DX9 is disabled.")
#endif
#endif


#endif // __COMPILE_CONFIG_H_INCLUDED__


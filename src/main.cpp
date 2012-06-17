/************************************************************************/
/* Copyright (C) 2012-20112 OneDOuble
/* This file is part of the "Double Engine".
/* dfghj77777@gmail.com                                                 
/************************************************************************/
#include "StdAfx.h"
using namespace doubal;
int main()
{
	IDevice *device = createDevice(video::EDT_DIRECT3D9,
		core::dimension2d<unsigned int>(640, 480), 16, false);

	// 这里运行程序，并在下面的函数调用之前delete掉所有new的东西 Learned By VCZH
	_CrtDumpMemoryLeaks();
	return 0 ;
}
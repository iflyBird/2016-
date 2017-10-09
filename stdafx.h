// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             //  从 Windows 头文件中排除极少使用的信息
// Windows 头文件: 
#include <windows.h>

// C 运行时头文件
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <string>
#include <mmsystem.h>	//音乐播放设置
#pragma comment(lib, "winmm.lib")	//音乐播放设置

// TODO:  在此处引用程序需要的其他头文件
#include "xcgui.h"
#ifdef _DEBUG
#pragma comment(lib, "XCGUId.lib")
#else
#pragma comment(lib, "XCGUI.lib")
#endif
#include"XCUtil.h"
#include "LoginWin.h"


#ifndef __UNILPTX_H__
#define __UNILPTX_H__

// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the UNILPTX_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// UNILPTX_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.

#ifdef UNILPTX_EXPORTS
#define UNILPTX_API __declspec(dllexport) 
#else
#define UNILPTX_API __declspec(dllimport)
#endif

#define UNILPTX_CALL __stdcall

// This class is exported from the UniLPTX.dll

#include "DevTypes.h"

namespace UNILPTDrv
{
	CDeviceID* UNILPTX_CALL LockDevice(CDeviceType DeviceType);
	// захватить устройство в индивидуальное пользование
	// возвращаен указатель на первое свободное устройство типа DeviceType либо NULL, если свободных устройств нет

	bool UNILPTX_CALL UnLockDevice(CDeviceID& DeviceID);
	// освободить устройство, захваченное ранее при помощи LockDevice.
}
#endif
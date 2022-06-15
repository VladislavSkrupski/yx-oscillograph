//this file contains common device definitions and constants
#ifndef __DEVICE_DEFINITIONS_H__
#define __DEVICE_DEFINITIONS_H__

#include "DevTypes.h"
#include <ctime>

namespace DevDef
{
	const int DeviceInfoEPROMAddr = 0;

	const ULONG Undefined = 0;
	const ULONG NULLDevice = 1;
	const ULONG Oscilloscope = 2;
	const ULONG Generator = 3;
	const ULONG Analyzer = 4;
	const ULONG Viking = 5;
	const ULONG Manom = 6;
	const ULONG GIVI = 7;
	const ULONG ADC0 = 8;

	typedef struct CEPROMDeviceInfo
	{
		ULONG nDeviceID;

		// Interface type(3) - version(2) - device serial number (0,1);
		// Version > 2  -  EPROM supported;
		ULONG nVersion; 
		ULONG nVendor;
		time_t ExpTime;
	} CEPROMDeviceInfo;

	typedef struct CDeviceTypeInfo
	{
		LPCTSTR Title;
		ULONG nEPROMID;
		CDeviceType Type;
	} CDeviceTypeInfo;

	const DeviceTypesCount = 9;

	const tiUndefined = 0;
	const tiNoDevice = 1;
	const tiOscilloscope = 2;
	const tiGenerator = 3;
	const tiAnalyzer = 4;
	const tiViking = 5;
	const tiManom = 6;
	const tiGIVI = 7;
	const tiADC0 = 8;

	const CDeviceTypeInfo DeviceTypeInfo[DeviceTypesCount] = 
	{
		{"Undefined", Undefined, dtUndefined},
		{"No device", NULLDevice, dtNULL},
		{"Oscilloscope", Oscilloscope, dtOscilloscope},
		{"Generator", Generator, dtGenerator},
		{"Analyzer", Analyzer, dtAnalyzer},
		{"Viking", Viking, dtViking},
		{"Manom", Manom, dtManom},
		{"GIVI", GIVI, dtGIVI},
		{"Static ADC 0", ADC0, dtADC0}
	};

}

#endif
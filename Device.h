#ifndef __DEVICE_H_
#define __DEVICE_H_

#include <windows.h>
#include <math.h>
#include "b181.h"

typedef BOOL (*(__stdcall pIOControl(DWORD, CDeviceID&, void*)));

class CB181Device {
	BOOL DevicePresent;
	BOOL DllPresent;
	CDeviceID DeviceID;
	pIOControl* IOCONTROL;
	ULONG MemExt0[0x10000];
	ULONG MemExt1[0x10000];
	ULONG MemInt0[512];
	ULONG MemInt1[512];
	HINSTANCE dllInstall;
	CClbrInfoStruct m_ClbrInfo;
	WORD VoltageToDACCode(BYTE ch, float fValue);
	float ADCCodeToVoltage(BYTE ch, WORD nCode);
public:
	CB181Device(){DevicePresent=FALSE;DllPresent=FALSE;};
	int InitializeDevice();
	void SecondInit(void);
	void GetIDString(char* str);
	void DeinitializeDevice();
	void ConfigCmn(void);
	void ConfigADC(void);
	void ConfigDAC(void);
	void ResetD();
	void RunD(BOOL bADC, BOOL bDAC);
	void StopD(BOOL bADC, BOOL bDAC);
	void ReadFromADC(float *SignalIn);
	void ReadFromADCDirect(float *SignalIn);
	void WriteToDAC(float *SignalOut);
	void WriteToDACDirect(float fValue);
	void PreWriteToDAC(void);
	void WriteToDACMem1(float *SignalOut);
	void WriteToDACMem2(float *SignalOut);
	void ReadFromADCMem1(float * SignalIn);
	void ReadFromADCMem2(float * SignalIn);
	BOOL ReadStatus(CmnStatusStruct& status);
};
#endif//__DEVICE_H_

#include <stdio.h>
#include "device.h"

#define min(a, b) (((a)<(b))?(a):(b))
#define max(a, b) (((a)>(b))?(a):(b))

int ADCCH=0x3,CLB1=0,CLB2=1;
//--------------------- Инициализация устройства  ----------------------------
int CB181Device::InitializeDevice()
 {
	DevicePresent=FALSE;
	DllPresent=FALSE;
	dllInstall=LoadLibrary("B181.dll");
	if (dllInstall) {DllPresent=TRUE;} else return -1;
	IOCONTROL=(pIOControl*)GetProcAddress(dllInstall,"IOControl");
	if (IOCONTROL==NULL) return -2;
	if (!IOCONTROL(IOCTRL_Initialize,DeviceID,NULL))
	{
	 if (DllPresent) FreeLibrary(dllInstall);
	 return -3;
	}
	DevicePresent=TRUE;
	if (!IOCONTROL(IOCTRL_InitClbrInfo,DeviceID,&m_ClbrInfo)) return -4;
	return 0;
 };
//--------------------- Повторная инициализация ------------------------------
void CB181Device::SecondInit(void)
 {
	IOCONTROL(IOCTRL_Initialize,DeviceID,NULL);
 }
//--------------------- Получение версии устройства  -------------------------
void CB181Device::GetIDString(char* str)
 {
	ULONG nVer=DeviceID.m_nDeviceVersion;
	ULONG nSer=nVer & 0xFFFF;
	sprintf(str,"B%d%d%d.%d\n",nVer>>24,DeviceID.m_DeviceType,(nVer>>16) & 0xFF,nSer);
 };
//--------------------- Деинициализация устройства  --------------------------
void CB181Device::DeinitializeDevice()
 {
	if (DevicePresent)
	{
		IOCONTROL(IOCTRL_Deinitialize,DeviceID,0);
		DevicePresent=FALSE;
		IOCONTROL = NULL;
	};
	if (DllPresent) FreeLibrary(dllInstall);
 };
//--------------------- Общая конфигурация -----------------------------------
void CB181Device::ConfigCmn(void)
 {
	CmnConfigStruct cc;
	cc.m_cExtMem0Source=MemSrc_ADC0;
	cc.m_cExtMem1Source=MemSrc_ADC1;
	cc.m_cIntMem0Source=MemSrc_DAC0;
	cc.m_cIntMem1Source=MemSrc_DAC1;
	cc.m_bLD3_0Direction=TRUE;
	cc.m_bLD7_4Direction=TRUE;
	cc.m_bLD11_8Direction=TRUE;
	cc.m_bLD15_12Direction=TRUE;
	cc.m_wInternalScale0=50000;
	cc.m_wInternalScale1=50000;
	IOCONTROL(IOCTRL_CmnConfig,DeviceID,&cc);
 };
//--------------------- Конфигурация АЦП -------------------------------------
void CB181Device::ConfigADC(void)
 {
	ADCConfigStruct ca;
	ca.m_bRecorder=1;
	ca.m_cChannels=ADCCH;
	ca.m_cRunSource=RunSrc_SW;
	ca.m_cClockSource=ClockSrc_IntGen0;
	ca.m_wWorkLen=500;
	IOCONTROL(IOCTRL_ADCConfig,DeviceID,&ca);
 };
//--------------------- Конфигурация ЦАП -------------------------------------
void CB181Device::ConfigDAC(void)
 {
	DACConfigStruct cd;
	cd.m_bSingleCycle=0;
	cd.m_bEndlessGenerator=1;
	cd.m_cChannels=0;
	cd.m_cRunSource=RunSrc_SW;
	cd.m_cClockSource=ClockSrc_IntGen0;
	cd.m_wWorkLen=500;
	IOCONTROL(IOCTRL_DACConfig,DeviceID,&cd);
 };
//--------------------- Состояние устройства ---------------------------------
BOOL CB181Device::ReadStatus(CmnStatusStruct& status)
 {
	IOCONTROL(IOCTRL_CmnReadStatus,DeviceID,&status);
	return TRUE;
 };
//--------------------- Вольты в ЦАП код -------------------------------------
WORD CB181Device::VoltageToDACCode(BYTE ch, float fValue)
 {
	double Coef=(m_ClbrInfo.m_DACCodePlus10[ch]-m_ClbrInfo.m_DACCodeMinus10[ch])/20.;
	return max(0,min(4095,(short)floor(0.5+(fValue+10)*Coef+m_ClbrInfo.m_DACCodeMinus10[ch])));
 };
//--------------------- АЦП код в вольты -------------------------------------
float CB181Device::ADCCodeToVoltage(BYTE ch, WORD nCode)
 {
	return float(((nCode^0x2000)-8192-m_ClbrInfo.m_ADCZeroCode[ch])*m_ClbrInfo.m_ADCCoef[ch]);
 };
//--------------------- Чтение из АЦП ----------------------------------------
void CB181Device::ReadFromADC(float * SignalIn)
 {
	CmnControlStruct cc;
	cc.m_bADC_Run=cc.m_bADC_StartSingleRead=FALSE;
	cc.m_bDAC_Reset=cc.m_bDAC_SW_Stop=cc.m_bDAC_Run=cc.m_bDAC_MemCntClear=FALSE;
	cc.m_bLA_Reset=cc.m_bLA_SW_Stop=cc.m_bLA_Run=FALSE;
	cc.m_bLG_Reset=cc.m_bLG_SW_Stop=cc.m_bLG_Run=cc.m_bLG_MemCntClear=FALSE;
	cc.m_bADC_Reset=cc.m_bADC_SW_Stop=TRUE;
	IOCONTROL(IOCTRL_CmnControl,DeviceID,&cc);
	ReadADCStruct ra;
	ra.m_pData=(WORD*)MemExt0;
	ra.m_cDataSource=DtSrc_Mem0;
	ra.m_wCount=1000;
	IOCONTROL(IOCTRL_ADCReadData,DeviceID,&ra);
	for(int i=0;i<1000;i+=2)
	 {
	  SignalIn[i]=ADCCodeToVoltage(CLB1,ra.m_pData[i]);i++;
	  SignalIn[i]=ADCCodeToVoltage(CLB2,ra.m_pData[i]);i--;
	 }
 };
//--------------------- Чтение из АЦП Mem 1 ----------------------------------
void CB181Device::ReadFromADCMem1(float * SignalIn)
 {
	ReadADCStruct ra;
	ra.m_pData=(WORD*)MemExt0;
	ra.m_cDataSource=DtSrc_Mem0;
	ra.m_wCount=1000;
	IOCONTROL(IOCTRL_ADCReadData,DeviceID,&ra);
	for(int i=0;i<1000;i+=2)
	 {
	  SignalIn[i]=ADCCodeToVoltage(CLB1,ra.m_pData[i]);i++;
	  SignalIn[i]=ADCCodeToVoltage(CLB2,ra.m_pData[i]);i--;
	 }
 };
//--------------------- Чтение из АЦП Mem 2 ----------------------------------
void CB181Device::ReadFromADCMem2(float * SignalIn)
 {
	ReadADCStruct ra;
	ra.m_pData=(WORD*)MemExt1;
	ra.m_cDataSource=DtSrc_Mem1;
	ra.m_wCount=1000;
	IOCONTROL(IOCTRL_ADCReadData,DeviceID,&ra);
	for(int i=0;i<1000;i+=2)
	 {
	  SignalIn[i]=ADCCodeToVoltage(CLB1,ra.m_pData[i]);i++;
	  SignalIn[i]=ADCCodeToVoltage(CLB2,ra.m_pData[i]);i--;
	 }
 };
//--------------------- Однократное чтение из АЦП ----------------------------
void CB181Device::ReadFromADCDirect(float * SignalIn)
 {
	CmnControlStruct cc;
	cc.m_bADC_Reset=cc.m_bADC_SW_Stop=cc.m_bADC_Run=FALSE;
	cc.m_bDAC_Reset=cc.m_bDAC_SW_Stop=cc.m_bDAC_Run=cc.m_bDAC_MemCntClear=FALSE;
	cc.m_bLA_Reset=cc.m_bLA_SW_Stop=cc.m_bLA_Run=FALSE;
	cc.m_bLG_Reset=cc.m_bLG_SW_Stop=cc.m_bLG_Run=cc.m_bLG_MemCntClear=FALSE;
	cc.m_bADC_StartSingleRead=TRUE;
	IOCONTROL(IOCTRL_CmnControl,DeviceID,&cc);
	Sleep(1);
	WORD Data[4]={0,0,0,0};
	ReadADCStruct ra;
	ra.m_pData=Data;
	ra.m_cDataSource=DtSrc_DirectChannels;
	IOCONTROL(IOCTRL_ADCReadData,DeviceID,&ra);
	for(int i=0;i<4;i++)
	  SignalIn[i]=ADCCodeToVoltage(i,Data[i]);
 };
//--------------------- Запись в ЦАП -----------------------------------------
void CB181Device::WriteToDAC(float *SignalOut)
 {
	CmnControlStruct cc;
	cc.m_bADC_Reset=cc.m_bADC_SW_Stop=cc.m_bADC_Run=cc.m_bADC_StartSingleRead=FALSE;
	cc.m_bDAC_SW_Stop=cc.m_bDAC_Run=FALSE;
	cc.m_bLA_Reset=cc.m_bLA_SW_Stop=cc.m_bLA_Run=FALSE;
	cc.m_bLG_Reset=cc.m_bLG_SW_Stop=cc.m_bLG_Run=cc.m_bLG_MemCntClear=FALSE;
	cc.m_bDAC_Reset=cc.m_bDAC_MemCntClear=TRUE;
	IOCONTROL(IOCTRL_CmnControl,DeviceID,&cc);
	WriteDACCStruct wd;
	wd.m_cDataDestination=DtSrc_Mem0;
	wd.m_pData=MemInt0;
	wd.m_wCount=500;
	wd.m_cChannel=0;
	wd.m_bLDAC_=FALSE;
	for(int i=0;i<500;i++)
		wd.m_pData[i]=VoltageToDACCode(0,SignalOut[i]);
	IOCONTROL(IOCTRL_DACWriteData,DeviceID,&wd);
 };
//--------------------- Презапись в ЦАП --------------------------------------
void CB181Device::PreWriteToDAC(void)
 {
	CmnControlStruct cc;
	cc.m_bADC_Reset=cc.m_bADC_SW_Stop=cc.m_bADC_Run=cc.m_bADC_StartSingleRead=FALSE;
	cc.m_bDAC_SW_Stop=cc.m_bDAC_Run=FALSE;
	cc.m_bLA_Reset=cc.m_bLA_SW_Stop=cc.m_bLA_Run=FALSE;
	cc.m_bLG_Reset=cc.m_bLG_SW_Stop=cc.m_bLG_Run=cc.m_bLG_MemCntClear=FALSE;
	cc.m_bDAC_Reset=cc.m_bDAC_MemCntClear=TRUE;
	IOCONTROL(IOCTRL_CmnControl,DeviceID,&cc);
 };
//--------------------- Запись в ЦАП Mem 1 -----------------------------------
void CB181Device::WriteToDACMem1(float *SignalOut)
 {
	WriteDACCStruct wd;
	wd.m_cDataDestination=DtSrc_Mem0;
	wd.m_pData=MemInt0;
	wd.m_wCount=500;
	wd.m_cChannel=0;
	wd.m_bLDAC_=TRUE;
	for(int i=0;i<500;i++)
		wd.m_pData[i]=VoltageToDACCode(0,SignalOut[i]);
	IOCONTROL(IOCTRL_DACWriteData,DeviceID,&wd);
 };
//--------------------- Запись в ЦАП Mem 2 -----------------------------------
void CB181Device::WriteToDACMem2(float *SignalOut)
 {
	WriteDACCStruct wd;
	wd.m_cDataDestination=DtSrc_Mem1;
	wd.m_pData=MemInt1;
	wd.m_wCount=500;
	wd.m_cChannel=0;
	wd.m_bLDAC_=TRUE;
	for(int i=0;i<500;i++)
		wd.m_pData[i]=VoltageToDACCode(0,SignalOut[i]);
	IOCONTROL(IOCTRL_DACWriteData,DeviceID,&wd);
 };
//--------------------- Однократная запись в ЦАП -----------------------------
void CB181Device::WriteToDACDirect(float fValue)
 {
	ULONG dwCode=VoltageToDACCode(0,fValue);
	WriteDACCStruct wd;
	wd.m_cDataDestination=DtSrc_DirectChannels;
	wd.m_pData=&dwCode;
	wd.m_cChannel=0;
	wd.m_bLDAC_=FALSE;
	IOCONTROL(IOCTRL_DACWriteData,DeviceID,&wd);
 };
//--------------------- Сброс устройства -------------------------------------
void CB181Device::ResetD()
 {
	CmnControlStruct cc;
	cc.m_bADC_StartSingleRead=FALSE;
	cc.m_bADC_SW_Stop=cc.m_bADC_Run=FALSE;
	cc.m_bDAC_SW_Stop=cc.m_bDAC_Run=FALSE;
	cc.m_bLA_SW_Stop=cc.m_bLA_Run=FALSE;
	cc.m_bLG_SW_Stop=cc.m_bLG_Run=FALSE;
	cc.m_bADC_Reset=TRUE;
	cc.m_bDAC_Reset=TRUE;
	cc.m_bDAC_MemCntClear=TRUE;
	cc.m_bLA_Reset=TRUE;
	cc.m_bLG_Reset=TRUE;
	cc.m_bLG_MemCntClear=TRUE;
	IOCONTROL(IOCTRL_CmnControl, DeviceID, &cc);
 };
//--------------------- Запуск устройства ------------------------------------
void CB181Device::RunD(BOOL bADC, BOOL bDAC)
 {
	CmnControlStruct cc;
	cc.m_bADC_SW_Stop=cc.m_bADC_Run=cc.m_bADC_StartSingleRead=FALSE;
	cc.m_bDAC_SW_Stop=cc.m_bDAC_Run=FALSE;
	cc.m_bLA_Reset=cc.m_bLA_SW_Stop=cc.m_bLA_Run=FALSE;
	cc.m_bLG_Reset=cc.m_bLG_SW_Stop=cc.m_bLG_Run=cc.m_bLG_MemCntClear=FALSE;
	cc.m_bADC_Reset=bADC;
	cc.m_bDAC_Reset=cc.m_bDAC_MemCntClear=bDAC;
	IOCONTROL(IOCTRL_CmnControl,DeviceID,&cc);
	cc.m_bADC_Reset=cc.m_bADC_SW_Stop=cc.m_bADC_StartSingleRead=FALSE;
	cc.m_bDAC_Reset=cc.m_bDAC_SW_Stop=cc.m_bDAC_MemCntClear=FALSE;
	cc.m_bLA_Reset=cc.m_bLA_SW_Stop=cc.m_bLA_Run=FALSE;
	cc.m_bLG_Reset=cc.m_bLG_SW_Stop=cc.m_bLG_Run=cc.m_bLG_MemCntClear=FALSE;
	cc.m_bADC_Run=bADC;
	cc.m_bDAC_Run=bDAC;
	IOCONTROL(IOCTRL_CmnControl,DeviceID,&cc);
 };
//--------------------- Програмный останов -----------------------------------
void CB181Device::StopD(BOOL bADC, BOOL bDAC)
 {
	CmnControlStruct cc;
	cc.m_bADC_Reset=cc.m_bADC_Run=cc.m_bADC_StartSingleRead=FALSE;
	cc.m_bDAC_Reset=cc.m_bDAC_Run=cc.m_bDAC_MemCntClear=FALSE;
	cc.m_bLA_Reset=cc.m_bLA_Run=cc.m_bLA_SW_Stop=FALSE;
	cc.m_bLG_Reset=cc.m_bLG_Run=cc.m_bLG_SW_Stop=cc.m_bLG_MemCntClear=FALSE;
	cc.m_bADC_SW_Stop=bADC;
	cc.m_bDAC_SW_Stop=bDAC;
	IOCONTROL(IOCTRL_CmnControl, DeviceID, &cc);
 }

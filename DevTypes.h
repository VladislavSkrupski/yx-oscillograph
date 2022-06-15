#ifndef	_DEVTYPES__H_
#define	_DEVTYPES__H_

// ��� ���������� ��������� ����������
enum CRegType 
{
	rt8 = 0, 
	rt16,
	rt32,
	rt64
};

// ��� ����������
enum CDeviceType 
{	
	dtUndefined,
	dtNULL,
	dtOscilloscope,
	dtGenerator,
	dtAnalyzer,
	dtViking,
	dtManom,
	dtGIVI,
	dtADC0
};


// ������������� ������������� ����������
struct CDeviceID
{
	CDeviceType m_DeviceType;
	ULONG m_nDeviceVersion;
	ULONG m_nBaseAddress;
	int	m_nIRQ;
	ULONG m_nVendorID;
};

// CallBack ��� ����������� ���� ������������� ����������
// ������ �������� - �����������-���������, ������ �������� - �������
typedef void (*PDrvCallBack) (int nHandle , int nCommand);

#endif
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "progress.h"
#include "Device.h"
#include "Oscilloscope.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cgauges"
#pragma resource "*.dfm"
TForm5 *Form5;
extern float MatPeriod, matrixdat[500][6000];
extern float x[500][6000],y[500][6000];
extern CB181Device device;
BOOL DES=FALSE;
//---------------------------------------------------------------------------
__fastcall TForm5::TForm5(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm5::FormShow(TObject *Sender)
{
 CGauge1->Progress=0;
 Label1->Caption="Идёт получение данных...";
 Timer1->Enabled=TRUE;
}
//---------------------------------------------------------------------------
void __fastcall TForm5::Timer1Timer(TObject *Sender)
{
 float SignalIn[1000],SignalOut[500];
 int j=0,ProgressStat=0;
 DES=FALSE;
 Timer1->Enabled=FALSE;
 CmnStatusStruct status;
 device.PreWriteToDAC();
 for (int i=0; i<500; i++)
  {SignalOut[i]=matrixdat[i][0];}
 device.WriteToDACMem1(SignalOut);
 for (int i=0; i<500; i++)
  {SignalOut[i]=matrixdat[i][1];}
 device.WriteToDACMem2(SignalOut);
 device.RunD(TRUE,TRUE);
 do
  {
   if (!DES)
	{
	 do {device.ReadStatus(status);Sleep(1);}
	 while ((!status.m_bADC_Mem0Full)&&(!status.m_bDAC_Mem0Empty));
	 device.ReadFromADCMem1(SignalIn);
	 for (int i=0; i<1000; i+=2)
	  {
	   x[i/2][j]=SignalIn[i];i++;
	   y[(i-1)/2][j]=SignalIn[i];i--;
	  };
	 ProgressStat++;
	 j+=2;
	 CGauge1->Progress=100*ProgressStat/MatPeriod;
	 if (j<MatPeriod)
	  {
	   for (int i=0; i<500; i++)
		{SignalOut[i]=matrixdat[i][j];}
	   device.WriteToDACMem1(SignalOut);
	  }
	 j--;
	 device.ReadStatus(status);
	 if (!status.m_bADC_Mem0Full)
	  {
	   Label1->Caption="Десинхронизация";
	   device.StopD(TRUE,TRUE);
	   DES=TRUE;
	  }
	 else
	  {
	   do {device.ReadStatus(status);Sleep(1);}
	   while ((!status.m_bADC_Mem1Full)&&(!status.m_bDAC_Mem1Empty));
	   device.ReadFromADCMem2(SignalIn);
	   for (int i=0; i<1000; i+=2)
		{
		 x[i/2][j]=SignalIn[i];i++;
		 y[(i-1)/2][j]=SignalIn[i];i--;
		};
	   ProgressStat++;
	   j+=2;
	   CGauge1->Progress=100*ProgressStat/MatPeriod;
	   if (j<MatPeriod)
		{
		 for (int i=0; i<500; i++)
		  {SignalOut[i]=matrixdat[i][j];}
		 device.WriteToDACMem2(SignalOut);
		}
	   j--;
	   device.ReadStatus(status);
	   if (!status.m_bADC_Mem1Full)
		{
		 Label1->Caption="Десинхронизация";
		 device.StopD(TRUE,TRUE);
		 DES=TRUE;
		}
	  }
	}
   else
	{
	 j=MatPeriod;
	}
  }
 while (j<MatPeriod);
 if (!DES) {device.StopD(TRUE,TRUE);}
 else {Timer2->Enabled=TRUE;}
 device.WriteToDACDirect(0);
 Form1->Button1->Enabled=TRUE;
 Form1->PaintBox1->Refresh();
 Form1->PaintBox2->Refresh();
 Form1->PaintBox3->Refresh();
 Form5->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm5::Timer2Timer(TObject *Sender)
{
 Timer2->Enabled=FALSE;
 device.WriteToDACDirect(0);
 Form1->Button1->Enabled=TRUE;
 Form1->PaintBox1->Refresh();
 Form1->PaintBox2->Refresh();
 Form1->PaintBox3->Refresh();
 Form5->Close();
}
//---------------------------------------------------------------------------

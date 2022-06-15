//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FStartD.h"
#include "device.h"
#include "Oscilloscope.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
extern CB181Device device;
extern int ADCCH,CLB1,CLB2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{
 int a=0;
 a=device.InitializeDevice();
 switch (ADCCH)
  {
   case 0x3: CLB1=0; CLB2=1; break;
   case 0x5: CLB1=0; CLB2=2; break;
   case 0x9: CLB1=0; CLB2=3; break;
   case 0x6: CLB1=1; CLB2=2; break;
   case 0xA: CLB1=1; CLB2=3; break;
   case 0xC: CLB1=2; CLB2=3; break;
  };
 switch (a)
  {
   case -1: Label1->Caption="B181.DLL не найдена";break;
   case -2: Label1->Caption="Функция IOCONTROL не найдена";break;
   case -3: Label1->Caption="Устройство не найдено";break;
   case -4: Label1->Caption="Устройство не откалибровано";break;
   case  0: Label1->Caption="Инициализация прошла успешно";
	Button1->Enabled=FALSE;Form1->N1->Enabled=FALSE;Form1->N15->Enabled=TRUE;
	device.ConfigCmn();device.ConfigDAC();device.ConfigADC();
	Timer1->Enabled=TRUE;break;
  };
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button2Click(TObject *Sender)
{
 Form2->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Timer1Timer(TObject *Sender)
{
 Timer1->Enabled=FALSE;
 Label1->Caption="";
 Form2->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::RadioButton1Click(TObject *Sender)
{
 ADCCH=0x3;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::RadioButton2Click(TObject *Sender)
{
 ADCCH=0x5;	
}
//---------------------------------------------------------------------------

void __fastcall TForm2::RadioButton3Click(TObject *Sender)
{
 ADCCH=0x9;	
}
//---------------------------------------------------------------------------

void __fastcall TForm2::RadioButton4Click(TObject *Sender)
{
 ADCCH=0x6;	
}
//---------------------------------------------------------------------------

void __fastcall TForm2::RadioButton5Click(TObject *Sender)
{
 ADCCH=0xA;	
}
//---------------------------------------------------------------------------

void __fastcall TForm2::RadioButton6Click(TObject *Sender)
{
 ADCCH=0xC;
}
//---------------------------------------------------------------------------


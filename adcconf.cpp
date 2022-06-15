//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "adcconf.h"
#include "Device.h"
#include "Oscilloscope.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm5 *Form5;
extern CB181Device device;
extern int ADC_SAMPLES_PER_CH,ADCCH;
BOOL adcconf=FALSE;
extern BOOL dacconf;
//---------------------------------------------------------------------------
__fastcall TForm5::TForm5(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm5::Button1Click(TObject *Sender)
{
 BOOL ClockGenADC,Plotting;
 Edit1->OnExit;
 if (RadioButton1->Checked) {ClockGenADC=TRUE;} else {ClockGenADC=FALSE;}
 if (CheckBox1->Checked) {Plotting=TRUE;} else {Plotting=FALSE;}
 ADC_SAMPLES_PER_CH=StrToInt(Edit1->Text);
 device.ConfigADC(Plotting,ClockGenADC);
 adcconf=TRUE;
 if (adcconf&&dacconf)
  {Form1->N15->Enabled=TRUE;}
 Form5->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm5::Button2Click(TObject *Sender)
{
 Edit1->OnExit;
 Form5->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm5::Edit1Exit(TObject *Sender)
{
 if ((Edit1->Text=="")||(StrToInt(Edit1->Text)<4)) Edit1->Text="4";
 else if (StrToInt(Edit1->Text)>65534) Edit1->Text="65534";
}
//---------------------------------------------------------------------------
void __fastcall TForm5::Edit1KeyPress(TObject *Sender, char &Key)
{
 if (((Key>='0')&&(Key<='9'))||(Key==VK_BACK)) Key;
 else Key=0;
}
//---------------------------------------------------------------------------
void __fastcall TForm5::RadioButton3Click(TObject *Sender)
{
 ADCCH=0x3;
}
//---------------------------------------------------------------------------
void __fastcall TForm5::RadioButton4Click(TObject *Sender)
{
 ADCCH=0x5;
}
//---------------------------------------------------------------------------
void __fastcall TForm5::RadioButton5Click(TObject *Sender)
{
 ADCCH=0x9;
}
//---------------------------------------------------------------------------
void __fastcall TForm5::RadioButton6Click(TObject *Sender)
{
 ADCCH=0x6;
}
//---------------------------------------------------------------------------
void __fastcall TForm5::RadioButton7Click(TObject *Sender)
{
 ADCCH=0xA;
}
//---------------------------------------------------------------------------
void __fastcall TForm5::RadioButton8Click(TObject *Sender)
{
 ADCCH=0xC;
}
//---------------------------------------------------------------------------

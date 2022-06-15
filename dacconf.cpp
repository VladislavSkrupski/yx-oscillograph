//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "dacconf.h"
#include "Device.h"
#include "Oscilloscope.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
extern CB181Device device;
extern int DAC_SAMPLES_PER_CH;
BOOL dacconf=FALSE,TacGen;
extern BOOL adcconf;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm4::RadioButton2Click(TObject *Sender)
{
 if (RadioButton2->Checked) CheckBox1->Enabled=TRUE;
}
//---------------------------------------------------------------------------
void __fastcall TForm4::RadioButton1Click(TObject *Sender)
{
 if (RadioButton1->Checked) CheckBox1->Enabled=FALSE;
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Button1Click(TObject *Sender)
{
 BOOL ClockGenDAC,SCycle,EGen;
 Edit1->OnExit;
 if (RadioButton3->Checked) {ClockGenDAC=TRUE;}
 else {ClockGenDAC=FALSE;}
 if (RadioButton1->Checked) {SCycle=TRUE;EGen=FALSE;}
 else if ((RadioButton2->Checked)&&(CheckBox1->Checked))
		{SCycle=FALSE;EGen=TRUE;}
	  else {SCycle=FALSE;EGen=FALSE;}
 DAC_SAMPLES_PER_CH=StrToInt(Edit1->Text);
 TacGen=ClockGenDAC;
 device.ConfigDAC(SCycle,EGen,ClockGenDAC);
 dacconf=TRUE;
 if (adcconf&&dacconf)
  {Form1->N15->Enabled=TRUE;}
 Form4->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Button2Click(TObject *Sender)
{
 Edit1->OnExit;
 Form4->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Edit1KeyPress(TObject *Sender, char &Key)
{
 if (((Key>='0')&&(Key<='9'))||(Key==VK_BACK)) Key;
 else Key=0;
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Edit1Exit(TObject *Sender)
{
 if ((Edit1->Text=="")||(StrToInt(Edit1->Text)<1)) Edit1->Text="1";
 else if (StrToInt(Edit1->Text)>32768) Edit1->Text="32768";
}
//---------------------------------------------------------------------------


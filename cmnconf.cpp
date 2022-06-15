//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "cmnconf.h"
#include "device.h"
#include "Oscilloscope.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
extern CB181Device device;
BOOL cmnconf=FALSE;
float GenTime[2];
extern BOOL dacconf,adcconf;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Edit1KeyPress(TObject *Sender, char &Key)
{
 if (((Key>='0')&&(Key<='9'))||(Key==VK_BACK)) Key;
 else Key=0;
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Edit2KeyPress(TObject *Sender, char &Key)
{
 if (((Key>='0')&&(Key<='9'))||(Key==VK_BACK)) Key;
 else Key=0;
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Edit1Change(TObject *Sender)
{
 if (Edit1->Text!="")
 Label3->Caption="нс = "+FloatToStr((StrToFloat(Edit1->Text))/1000)+" мкс";
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Edit2Change(TObject *Sender)
{
 if (Edit2->Text!="")
 Label4->Caption="нс = "+FloatToStr((StrToFloat(Edit2->Text))/1000)+" мкс";
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Edit1Exit(TObject *Sender)
{
 if ((Edit1->Text=="")||(StrToInt(Edit1->Text)<10000))
  Edit1->Text="10000";
 else if (StrToInt(Edit1->Text)>1310700)
	   Edit1->Text="1310700";
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Edit2Exit(TObject *Sender)
{
 if ((Edit2->Text=="")||(StrToInt(Edit2->Text)<10000))
  Edit2->Text="10000";
 else if (StrToInt(Edit2->Text)>1310700)
	   Edit2->Text="1310700";
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button2Click(TObject *Sender)
{
 Edit1->OnExit;
 Edit2->OnExit;
 Form3->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button1Click(TObject *Sender)
{
 int IS0,IS1;
 Edit1->OnExit;
 Edit2->OnExit;
 GenTime[0]=StrToInt(Edit1->Text)/1000000.;
 GenTime[1]=StrToInt(Edit2->Text)/1000000.;
 IS0=StrToInt(Edit1->Text)/20;
 IS1=StrToInt(Edit2->Text)/20;
 device.ConfigCmn(IS0,IS1);
 cmnconf=TRUE;
 if (cmnconf&&adcconf&&dacconf)
  {Form1->N15->Enabled=TRUE;}
 Form3->Close();
}
//---------------------------------------------------------------------------

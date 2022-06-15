//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "numexport.h"
#include "exporting.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm7 *Form7;
extern int DACTime;
int krat;
//---------------------------------------------------------------------------
__fastcall TForm7::TForm7(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm7::Button2Click(TObject *Sender)
{
 Form7->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm7::Edit1KeyPress(TObject *Sender, char &Key)
{
 if (((Key>='0')&&(Key<='9'))||(Key==VK_BACK)) Key;
 else Key=0;
}
//---------------------------------------------------------------------------
void __fastcall TForm7::Button1Click(TObject *Sender)
{
 Edit1->OnExit;
 krat=StrToInt(Edit1->Text);
 Form3->Show();
 Form7->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm7::Edit1Exit(TObject *Sender)
{
 if ((Edit1->Text=="")||(StrToInt(Edit1->Text)<1)) Edit1->Text="1";
 else if (StrToInt(Edit1->Text)>(DACTime*1000)) Edit1->Text=IntToStr(DACTime*1000);
}
//---------------------------------------------------------------------------

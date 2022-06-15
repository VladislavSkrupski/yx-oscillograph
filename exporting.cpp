//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "exporting.h"
#include "numexport.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
extern float x[500][6000],y[500][6000],MatPeriod;
extern int krat;
AnsiString xx,yy;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button1Click(TObject *Sender)
{
 if (SaveDialog1->Execute())
 if (SaveDialog1->FileName!=NULL)
 Memo1->Lines->SaveToFile(SaveDialog1->FileName);
 Form3->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button2Click(TObject *Sender)
{
 Form3->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm3::FormShow(TObject *Sender)
{
 int j=0;
 div_t DI;
 Memo1->Clear();
 do
  {
   DI=div(j,500);
   xx=FloatToStrF(x[DI.rem][DI.quot],ffFixed,8,6);
   yy=FloatToStrF(y[DI.rem][DI.quot],ffFixed,8,6);
   Memo1->Lines->Add(xx+"\t"+yy);
   j+=krat;
  }
 while (j<(MatPeriod*500));
}
//---------------------------------------------------------------------------


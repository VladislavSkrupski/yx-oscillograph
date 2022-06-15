//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "generator.h"
#include "Device.h"
#include "Oscilloscope.h"
#include "exporting.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm6 *Form6;
float matrixdat[500][6000];
int matrixgraphX[500][6000],matrixgraphY[500][6000];
int DACTime=30;
float MatPeriod;
extern CB181Device device;
#define PB Form6->PaintBox1
#define PBC Form6->PaintBox1->Canvas
//---------------------------------------------------------------------------
__fastcall TForm6::TForm6(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm6::Button1Click(TObject *Sender)
{
 Form1->Button1->Enabled=TRUE;
 Form1->Button3->Enabled=TRUE;
 Form6->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm6::PaintBox1Paint(TObject *Sender)
{
 int GdX,GdY,j;
 float dX,dY;
 PB->Color=clWhite;
 PBC->Pen->Color=clBlack;
 PBC->Pen->Style=psSolid;
 PBC->Rectangle(0,0,500,200);
  //-------- Сетка ------
 GdX=42;GdY=14;
 PBC->Pen->Color=clSilver;
 PBC->Pen->Style=psDot;
 for (int i=40; i<=460; i+=GdX)
  {PBC->MoveTo(i,30); PBC->LineTo(i,170);};
 for (int i=30; i<=170; i+=GdY)
  {PBC->MoveTo(40,i); PBC->LineTo(460,i);};
  //-------- Оси --------
 PBC->Pen->Color=clBlack;
 PBC->Pen->Style=psSolid;
 PBC->MoveTo(30,100);PBC->LineTo(470,100);
 PBC->MoveTo(40,180);PBC->LineTo(40,20);
  //-------- Стрелки ----
 PBC->LineTo(42,25);PBC->MoveTo(40,20);PBC->LineTo(38,25);
 PBC->MoveTo(470,100);PBC->LineTo(465,102);PBC->MoveTo(470,100);
 PBC->LineTo(465,98);
  //-------- Деления ----
 PBC->MoveTo(460,97);PBC->LineTo(460,104);
 PBC->MoveTo(37,30);PBC->LineTo(44,30);
 PBC->MoveTo(37,170);PBC->LineTo(44,170);
  //-------- Подписи ----
 PBC->Font->Color=clNavy;
 PBC->Font->Size=8;
 PBC->TextOutA(35-PBC->TextWidth("0"),105,"0");
 PBC->TextOutA(475,105,"t, c");
 PBC->TextOutA(35-PBC->TextWidth(10),30-PBC->TextHeight(10)/2,"10");
 PBC->TextOutA(35-PBC->TextWidth(-10),170-PBC->TextHeight(10)/2,"-10");
  //-------- График -----
 dX=420./(DACTime*1000.);
 dY=7;
 j=0;
 do
  {
   for (int i=0; i<500; i++)
	{
	 matrixgraphX[i][j]=40+(i+500*j)*dX;
	 matrixgraphY[i][j]=100-dY*matrixdat[i][j];
	}
   j++;
  }
 while (j<MatPeriod);
 PBC->Pen->Style=psSolid;
 PBC->Pen->Color=clRed;
 PBC->MoveTo(matrixgraphX[0][0],matrixgraphY[0][0]);
 j=0;
 do
  {
   for (int i=0; i<500; i++)
   PBC->LineTo(matrixgraphX[i][j],matrixgraphY[i][j]);
   j++;
  }
 while (j<MatPeriod);

}
//---------------------------------------------------------------------------
void __fastcall TForm6::Button4Click(TObject *Sender)
{
 float dV,V;
 int j=0;
 Edit5->OnExit;
 Edit6->OnExit;
 DACTime=StrToInt(Edit5->Text);
 MatPeriod=DACTime*2;
 V=StrToInt(Edit6->Text)/1000.;
 dV=(2*V)/(DACTime*500.);
 do
  {
   for (int i=0; i<500; i++)
	{
	 if ((dV*(i+j*500)-V)<V)
	  {matrixdat[i][j]=dV*(i+j*500)-V;}
	 else if ((dV*(-i-j*500)+3*V)>(-V))
		   {matrixdat[i][j]=dV*(-i-j*500)+3*V;}
	}
   j++;
  }
 while (j<MatPeriod);
 PB->Refresh();
 Button1->Enabled=TRUE;
}
//---------------------------------------------------------------------------
void __fastcall TForm6::Edit5KeyPress(TObject *Sender, char &Key)
{
 if (((Key>='0')&&(Key<='9'))||(Key==VK_BACK)) Key;
 else Key=0;
}
//---------------------------------------------------------------------------
void __fastcall TForm6::Edit6KeyPress(TObject *Sender, char &Key)
{
 if (((Key>='0')&&(Key<='9'))||(Key==VK_BACK)) Key;
 else Key=0;
}
//---------------------------------------------------------------------------

void __fastcall TForm6::Edit6Exit(TObject *Sender)
{
 if ((Edit6->Text=="")||(StrToInt(Edit6->Text)<0)) Edit6->Text="0";
 else if (StrToInt(Edit6->Text)>10000) Edit6->Text="10000";
}
//---------------------------------------------------------------------------


void __fastcall TForm6::Edit5Exit(TObject *Sender)
{
 if ((Edit5->Text=="")||(StrToInt(Edit5->Text)<1)) Edit5->Text="1";
 else if (StrToInt(Edit5->Text)>3000) Edit5->Text="3000";
}
//---------------------------------------------------------------------------

void __fastcall TForm6::Label5Click(TObject *Sender)
{
 if (Label5->Caption=="+")
  Label5->Caption="-";
 else
  Label5->Caption="+";
}
//---------------------------------------------------------------------------

void __fastcall TForm6::Button3Click(TObject *Sender)
{
 float WTDD;
 Edit1->OnExit;
 Edit2->OnExit;
 if (Label5->Caption=="+")
  {
   WTDD=StrToInt(Edit2->Text)/1000.;
  }
 else
  {
   WTDD=(0-StrToInt(Edit2->Text))/1000.;
  }
 device.WriteToDACDirect(WTDD);
}
//---------------------------------------------------------------------------

void __fastcall TForm6::Edit1KeyPress(TObject *Sender, char &Key)
{
 if (((Key>='0')&&(Key<='9'))||(Key==VK_BACK)) Key;
 else Key=0;	
}
//---------------------------------------------------------------------------

void __fastcall TForm6::Edit2KeyPress(TObject *Sender, char &Key)
{
 if (((Key>='0')&&(Key<='9'))||(Key==VK_BACK)) Key;
 else Key=0;
}
//---------------------------------------------------------------------------

void __fastcall TForm6::Edit2Exit(TObject *Sender)
{
 if ((Edit2->Text=="")||(StrToInt(Edit2->Text)<0)) Edit2->Text="0";
 else if (StrToInt(Edit2->Text)>10000) Edit2->Text="10000";
}
//---------------------------------------------------------------------------

void __fastcall TForm6::Edit1Exit(TObject *Sender)
{
 if ((Edit1->Text=="")||(StrToInt(Edit1->Text)<1)) Edit1->Text="1";
 else if (StrToInt(Edit1->Text)>3000) Edit1->Text="3000";
}
//---------------------------------------------------------------------------

void __fastcall TForm6::Button2Click(TObject *Sender)
{
 float V;
 int j=0;
 Edit1->OnExit;
 Edit2->OnExit;
 DACTime=StrToInt(Edit1->Text);
 MatPeriod=DACTime*2;
 V=StrToInt(Edit2->Text)/1000.;
 do
  {
   for (int i=0; i<500; i++)
	{
	 if (Label5->Caption=="+")
	  {
	   matrixdat[i][j]=V;
	  }
	 else
	  {
	   matrixdat[i][j]=0-V;
	  }
	}
   j++;
  }
 while (j<MatPeriod);
 PB->Refresh();
 Button1->Enabled=TRUE;
}
//---------------------------------------------------------------------------


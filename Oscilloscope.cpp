//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Device.h"
#include "Oscilloscope.h"
#include "FStartD.h"
#include "generator.h"
#include "exporting.h"
#include "numexport.h"
#include "progress.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
CB181Device device;
extern int DACTime;
float x[500][6000],y[500][6000],datxy[500][6000];
signed int GX[500][6000],GY[500][6000],GXa[500][6000],GYa[500][6000],GXb[500][6000],GYb[500][6000];
extern float MatPeriod, matrixdat[500][6000];
BOOL LinePoint=TRUE;
div_t DJ;
#define PB Form1->PaintBox1
#define PBC Form1->PaintBox1->Canvas
#define PB2 Form1->PaintBox2
#define PBC2 Form1->PaintBox2->Canvas
#define PB3 Form1->PaintBox3
#define PBC3 Form1->PaintBox3->Canvas
//---------- Оси -------------------------------------------
void Axis(void)
{
 int CdX, CdY;
 float LdX, LdY, TVX, TVY;
  //-------- Оси --------
 PBC->Pen->Color=clBlack;
 PBC->Pen->Style=psSolid;
 PBC->MoveTo(10,PB->Height/2);
 PBC->LineTo(PB->Width-10,PB->Height/2);
 PBC->MoveTo(PB->Width/2,PB->Height-10);
 PBC->LineTo(PB->Width/2,10);
  //-------- Стрелки ----
 PBC->LineTo(PB->Width/2+2,20);
 PBC->MoveTo(PB->Width/2,10);
 PBC->LineTo(PB->Width/2-2,20);
 PBC->MoveTo(PB->Width-10,PB->Height/2);
 PBC->LineTo(PB->Width-20,PB->Height/2+2);
 PBC->MoveTo(PB->Width-10,PB->Height/2);
 PBC->LineTo(PB->Width-20,PB->Height/2-2);
  //-------- Деления ----
 CdX=(PB->Width-60)/10;
 CdY=(PB->Height-60)/10;
 for (int i=30; i<=(PB->Width-30); i+=CdX)
  {PBC->MoveTo(i,PB->Height/2-3); PBC->LineTo(i,PB->Height/2+4);};
 for (int i=30; i<=(PB->Height-30); i+=CdY)
  {PBC->MoveTo(PB->Width/2-3,i); PBC->LineTo(PB->Width/2+4,i);};
  //-------- Подписи ----
 TVX=10-Form1->TrackBar1->Position;
 TVY=10-Form1->TrackBar2->Position;
 PBC->Font->Color=clNavy;
 PBC->Font->Size=8;
 LdX=Form1->TrackBar1->Position-10; LdY=Form1->TrackBar2->Position-10;
 for (int i=30; i<=(PB->Width-30); i+=CdX)
 {
  if (LdX<-0.1||LdX>0.1)
  PBC->TextOutA(i-PBC->TextWidth(FloatToStrF(LdX,ffFixed,4,1))/2,PB->Height/2+5,FloatToStrF(LdX,ffFixed,4,1));
  LdX+=(TVX*2)/10;
 };
 for (int i=(PB->Width-30); i>=30; i-=CdY)
 {
  if (LdY<-0.1||LdY>0.1)
  PBC->TextOutA(PB->Width/2-PBC->TextWidth(FloatToStrF(LdY,ffFixed,4,1))-5,i-PBC->TextHeight(FloatToStrF(LdY,ffFixed,4,1))/2,FloatToStrF(LdY,ffFixed,4,1));
  LdY+=(TVY*2)/10;
 };
 PBC->TextOutA(PB->Width/2-PBC->TextWidth("0")-5,PB->Height/2+5,"0");
}
//---------- Сетка -----------------------------------------
void GridLines(void)
{
 int GdX,GdY;
 GdX=(PB->Width-60)/10;
 GdY=(PB->Height-60)/10;
 PBC->Pen->Color=clSilver;
 PBC->Pen->Style=psDot;
 for (int i=30; i<=(PB->Width-30); i+=GdX)
  {PBC->MoveTo(i,30); PBC->LineTo(i,PB->Height-30);};
 for (int i=30; i<=(PB->Height-30); i+=GdY)
  {PBC->MoveTo(30,i); PBC->LineTo(PB->Width-30,i);};
}
//---------- График ----------------------------------------
void Graphik(void)
{
 int dX,dY,j=0,N=0;
 dX=(PB->Width-60)/((10-Form1->TrackBar1->Position)*2);
 dY=(PB->Height-60)/((10-Form1->TrackBar2->Position)*2);
 do
  {
   for (int i=0; i<500; i++)
	{
	 GX[i][j]=PB->Width/2+x[i][j]*dX;
	 GY[i][j]=PB->Height/2-y[i][j]*dY;
	};
   j++;
  }
 while (j<MatPeriod);
 PBC->Pen->Style=psSolid;
 PBC->Pen->Color=clRed;
 PBC->MoveTo(GX[0][0],GY[0][0]);
 j=0;
 Form1->Edit1->OnExit;
 N=StrToInt(Form1->Edit1->Text);
 DJ=div(N,500);
 Form1->Button5->Caption="Тест "+IntToStr(DJ.quot)+":"+IntToStr(DJ.rem);
 j=0;
 if (LinePoint)
  {
   do
	{
	 DJ=div(j,500);
	 PBC->LineTo(GX[DJ.rem][DJ.quot],GY[DJ.rem][DJ.quot]);
	 j+=N;
	}
   while (j<(MatPeriod*500));
  }
 else
  {
   do
	{
	 DJ=div(j,500);
	 PBC->Pixels[GX[DJ.rem][DJ.quot]][GY[DJ.rem][DJ.quot]]=clRed;
	 j+=N;
	}
   while (j<(MatPeriod*500));
  }
}
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N6Click(TObject *Sender)
{
 device.DeinitializeDevice();
 Application->Terminate();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N2Click(TObject *Sender)
{
 device.DeinitializeDevice();
 N1->Enabled=TRUE;
 N15->Enabled=FALSE;
 Button1->Enabled=FALSE;
 Button3->Enabled=FALSE;
 Form2->Button1->Enabled=TRUE;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N1Click(TObject *Sender)
{
 Form2->Show();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N15Click(TObject *Sender)
{
 Form6->Show();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::PaintBox1Paint(TObject *Sender)
{
 PBC->Pen->Color=clBlack;
 PBC->Pen->Style=psSolid;
 PBC->Rectangle(0,0,PaintBox1->Width,PaintBox1->Height);
 GridLines();
 Axis();
 Graphik();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TrackBar1Change(TObject *Sender)
{
 if (Label1->Caption=="+")
 {
  TrackBar2->Position=TrackBar1->Position;
  PB->Refresh();
 }
 else PB->Refresh();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TrackBar2Change(TObject *Sender)
{
 if (Label1->Caption=="+")
 {
  TrackBar1->Position=TrackBar2->Position;
  PB->Refresh();
 }
 else PB->Refresh();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Label1Click(TObject *Sender)
{
 if (Label1->Caption=="+")
  Label1->Caption="";
 else
  Label1->Caption="+";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
 Button1->Enabled=FALSE;
 if (CheckBox1->Checked)
  {
   device.WriteToDACDirect(matrixdat[0][0]);
   Sleep(1000);
  }
 else
  {
   device.WriteToDACDirect(0);
  }
 Label4->Caption="t = "+IntToStr(DACTime)+" с";
 Label5->Caption="t = "+IntToStr(DACTime)+" с";
 Form5->Show();
 }
//---------------------------------------------------------------------------
void __fastcall TForm1::PaintBox2Paint(TObject *Sender)
{
 int GdX,GdY,j=0,N=0;
 float dX,dY,W,H;
 PBC2->Pen->Color=clBlack;
 PBC2->Pen->Style=psSolid;
 PBC2->Rectangle(0,0,PB2->Width,PB2->Height);
  //-------- Сетка ------
 GdX=(PB2->Width-50)/5;
 GdY=(PB2->Height-40)/6;
 PBC2->Pen->Color=clSilver;
 PBC2->Pen->Style=psDot;
 for (int i=30; i<=(PB2->Width-20); i+=GdX)
  {PBC2->MoveTo(i,20); PBC2->LineTo(i,PB2->Height-20);};
 for (int i=20; i<=(PB2->Height-20); i+=GdY)
  {PBC2->MoveTo(30,i); PBC2->LineTo(PB2->Width-20,i);};
  //-------- Оси --------
 PBC2->Pen->Color=clBlack;
 PBC2->Pen->Style=psSolid;
 PBC2->MoveTo(20,PB2->Height/2);
 PBC2->LineTo(PB2->Width-10,PB2->Height/2);
 PBC2->MoveTo(30,PB2->Height-10);
 PBC2->LineTo(30,10);
  //-------- Стрелки ----
 PBC2->LineTo(32,15);
 PBC2->MoveTo(30,10);
 PBC2->LineTo(28,15);
 PBC2->MoveTo(PB2->Width-10,PB2->Height/2);
 PBC2->LineTo(PB2->Width-15,PB2->Height/2+2);
 PBC2->MoveTo(PB2->Width-10,PB2->Height/2);
 PBC2->LineTo(PB2->Width-15,PB2->Height/2-2);
  //-------- Деления ----
 PBC2->MoveTo(PB2->Width-20,PB2->Height/2-3);
 PBC2->LineTo(PB2->Width-20,PB2->Height/2+4);
 PBC2->MoveTo(27,20);
 PBC2->LineTo(34,20);
 PBC2->MoveTo(27,PB2->Height-20);
 PBC2->LineTo(34,PB2->Height-20);
  //-------- Подписи ----
 PBC2->Font->Color=clNavy;
 PBC2->Font->Size=8;
 PBC2->TextOutA(30-PBC2->TextWidth("0")-5,PB2->Height/2+5,"0");
 PBC2->TextOutA(PB2->Width-15,PB2->Height/2+5,"t");
 PBC2->TextOutA(25-PBC2->TextWidth(IntToStr(TrackBar3->Position)),20-PBC2->TextHeight(IntToStr(TrackBar3->Position))/2,IntToStr(TrackBar3->Position));
 PBC2->TextOutA(25-PBC2->TextWidth("-"+IntToStr(TrackBar3->Position)),PB2->Height-20-PBC2->TextHeight(IntToStr(TrackBar3->Position))/2,"-"+IntToStr(TrackBar3->Position));
  //-------- График -----
 W=PB2->Width;
 H=PB2->Height;
 dX=(W-50)/(DACTime*1000.);
 dY=(H-40)/(TrackBar3->Position*2);
 do
  {
   for (int i=0; i<500; i++)
	{
	 GXa[i][j]=30+(i+j*500)*dX;
	 GYa[i][j]=PB2->Height/2-x[i][j]*dY;
	};
   j++;
  }
 while (j<MatPeriod);
 PBC2->Pen->Style=psSolid;
 PBC2->Pen->Color=clRed;
 PBC2->MoveTo(GXa[0][0],GYa[0][0]);
 j=0;
 Edit1->OnExit;
 N=StrToInt(Edit1->Text);
 if (LinePoint)
  {
   do
	{
	 DJ=div(j,500);
	 PBC2->LineTo(GXa[DJ.rem][DJ.quot],GYa[DJ.rem][DJ.quot]);
	 j+=N;
	}
   while (j<(MatPeriod*500));
  }
 else
  {
   do
	{
	 DJ=div(j,500);
	 PBC2->Pixels[GXa[DJ.rem][DJ.quot]][GYa[DJ.rem][DJ.quot]]=clRed;
	 j+=N;
	}
   while (j<(MatPeriod*500));
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TrackBar3Change(TObject *Sender)
{
 PB2->Refresh();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::PaintBox3Paint(TObject *Sender)
{
 int GdX,GdY,j=0,N=0;
 div_t DJ;
 float dX,dY,W,H;
 PBC3->Pen->Color=clBlack;
 PBC3->Pen->Style=psSolid;
 PBC3->Rectangle(0,0,PB3->Width,PB3->Height);
  //-------- Сетка ------
 GdX=(PB3->Width-50)/5;
 GdY=(PB3->Height-40)/6;
 PBC3->Pen->Color=clSilver;
 PBC3->Pen->Style=psDot;
 for (int i=30; i<=(PB3->Width-20); i+=GdX)
  {PBC3->MoveTo(i,20); PBC3->LineTo(i,PB3->Height-20);};
 for (int i=20; i<=(PB3->Height-20); i+=GdY)
  {PBC3->MoveTo(30,i); PBC3->LineTo(PB3->Width-20,i);};
  //-------- Оси --------
 PBC3->Pen->Color=clBlack;
 PBC3->Pen->Style=psSolid;
 PBC3->MoveTo(20,PB3->Height/2);
 PBC3->LineTo(PB3->Width-10,PB3->Height/2);
 PBC3->MoveTo(30,PB3->Height-10);
 PBC3->LineTo(30,10);
  //-------- Стрелки ----
 PBC3->LineTo(32,15);
 PBC3->MoveTo(30,10);
 PBC3->LineTo(28,15);
 PBC3->MoveTo(PB3->Width-10,PB3->Height/2);
 PBC3->LineTo(PB3->Width-15,PB3->Height/2+2);
 PBC3->MoveTo(PB3->Width-10,PB3->Height/2);
 PBC3->LineTo(PB3->Width-15,PB3->Height/2-2);
  //-------- Деления ----
 PBC3->MoveTo(PB3->Width-20,PB3->Height/2-3);
 PBC3->LineTo(PB3->Width-20,PB3->Height/2+4);
 PBC3->MoveTo(27,20);
 PBC3->LineTo(34,20);
 PBC3->MoveTo(27,PB3->Height-20);
 PBC3->LineTo(34,PB3->Height-20);
  //-------- Подписи ----
 PBC3->Font->Color=clNavy;
 PBC3->Font->Size=8;
 PBC3->TextOutA(30-PBC3->TextWidth("0")-5,PB3->Height/2+5,"0");
 PBC3->TextOutA(PB3->Width-15,PB3->Height/2+5,"t");
 PBC3->TextOutA(25-PBC3->TextWidth(IntToStr(TrackBar4->Position)),20-PBC3->TextHeight(IntToStr(TrackBar4->Position))/2,IntToStr(TrackBar4->Position));
 PBC3->TextOutA(25-PBC3->TextWidth("-"+IntToStr(TrackBar4->Position)),PB3->Height-20-PBC3->TextHeight(IntToStr(TrackBar4->Position))/2,"-"+IntToStr(TrackBar4->Position));
  //-------- График -----
 W=PB3->Width;
 H=PB3->Height;
 dX=(W-50)/(DACTime*1000.);
 dY=(H-40)/(TrackBar4->Position*2);
 do
  {
   for (int i=0; i<500; i++)
	{
	 GXb[i][j]=30+(i+j*500)*dX;
	 GYb[i][j]=PB3->Height/2-y[i][j]*dY;
	};
   j++;
  }
 while (j<MatPeriod);
 PBC3->Pen->Style=psSolid;
 PBC3->Pen->Color=clRed;
 PBC3->MoveTo(GXb[0][0],GYb[0][0]);
 j=0;
 Edit1->OnExit;
 N=StrToInt(Edit1->Text);
 if (LinePoint)
  {
   do
	{
	 DJ=div(j,500);
	 PBC3->LineTo(GXb[DJ.rem][DJ.quot],GYb[DJ.rem][DJ.quot]);
	 j+=N;
	}
   while (j<(MatPeriod*500));
  }
 else
  {
   do
	{
	 DJ=div(j,500);
	 PBC3->Pixels[GXb[DJ.rem][DJ.quot]][GYb[DJ.rem][DJ.quot]]=clRed;
	 j+=N;
	}
   while (j<(MatPeriod*500));
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TrackBar4Change(TObject *Sender)
{
 PB3->Refresh();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N4Click(TObject *Sender)
{
 Form7->Show();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button2Click(TObject *Sender)
{
 Edit1->OnExit;
 if (LinePoint)
  {
   LinePoint=FALSE;
   Button2->Caption="Точечный";
  }
 else
  {
   LinePoint=TRUE;
   Button2->Caption="Линейный";
  }
 PB->Refresh();
 PB2->Refresh();
 PB3->Refresh();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit1KeyPress(TObject *Sender, char &Key)
{
 if (((Key>='0')&&(Key<='9'))||(Key==VK_BACK)) Key;
 else Key=0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit1Exit(TObject *Sender)
{
 if ((Edit1->Text=="")||(StrToInt(Edit1->Text)<1)) Edit1->Text="1";
 else if (StrToInt(Edit1->Text)>(DACTime*1000)) Edit1->Text=IntToStr(DACTime*1000);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
 int j=0;
 MatPeriod=1000;
 DACTime=500;
 do
  {
   for (int i=0; i<500; i++)
	{
	 x[i][j]=10*Sin((i+j*500)/25.12);
	 y[i][j]=10*Cos((i+j*500)/25.12);
	};
   j++;
  }
 while (j<MatPeriod);
 Edit1->OnExit;
 PB->Refresh();
 PB2->Refresh();
 PB3->Refresh();
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button6Click(TObject *Sender)
{
 int j=0;
 do
  {
   for (int i=0; i<500; i++)
	{
	 x[i][j]=y[i][j]=
	 GX[i][j]=GY[i][j]=
	 GXa[i][j]=GYa[i][j]=
	 GXb[i][j]=GYb[i][j]=
	 matrixdat[i][j]=0;
	}
   j++;
  }
 while (j<6000);
 MatPeriod=0;
 DACTime=30;
 PB->Refresh();
 PB2->Refresh();
 PB3->Refresh();
 Button1->Enabled=FALSE;
 Button3->Enabled=FALSE;
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

#ifndef OscilloscopeH
#define OscilloscopeH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *MainMenu1;
	TMenuItem *gsg1;
	TMenuItem *N1;
	TMenuItem *N2;
	TMenuItem *N3;
	TMenuItem *N4;
	TMenuItem *N5;
	TMenuItem *N6;
	TMenuItem *N10;
	TMenuItem *N11;
	TMenuItem *N12;
	TMenuItem *N13;
	TMenuItem *N15;
	TShape *Shape1;
	TPaintBox *PaintBox1;
	TButton *Button1;
	TButton *Button3;
	TTrackBar *TrackBar2;
	TGroupBox *GroupBox1;
	TTrackBar *TrackBar1;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TPaintBox *PaintBox2;
	TGroupBox *GroupBox2;
	TShape *Shape2;
	TTrackBar *TrackBar3;
	TGroupBox *GroupBox3;
	TShape *Shape3;
	TPaintBox *PaintBox3;
	TTrackBar *TrackBar4;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TButton *Button2;
	TEdit *Edit1;
	TGroupBox *GroupBox4;
	TButton *Button5;
	TCheckBox *CheckBox1;
	TButton *Button6;
	void __fastcall N6Click(TObject *Sender);
	void __fastcall N2Click(TObject *Sender);
	void __fastcall N1Click(TObject *Sender);
	void __fastcall N15Click(TObject *Sender);
	void __fastcall PaintBox1Paint(TObject *Sender);
	void __fastcall TrackBar1Change(TObject *Sender);
	void __fastcall TrackBar2Change(TObject *Sender);
	void __fastcall Label1Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall PaintBox2Paint(TObject *Sender);
	void __fastcall TrackBar3Change(TObject *Sender);
	void __fastcall PaintBox3Paint(TObject *Sender);
	void __fastcall TrackBar4Change(TObject *Sender);
	void __fastcall N4Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Edit1KeyPress(TObject *Sender, char &Key);
	void __fastcall Edit1Exit(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif

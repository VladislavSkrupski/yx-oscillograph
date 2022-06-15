//---------------------------------------------------------------------------

#ifndef generatorH
#define generatorH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "Chart.hpp"
#include "Series.hpp"
#include "TeEngine.hpp"
#include "TeeProcs.hpp"
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm6 : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TLabel *Label7;
	TLabel *Label8;
	TPaintBox *PaintBox1;
	TShape *Shape1;
	TGroupBox *GroupBox2;
	TGroupBox *GroupBox3;
	TButton *Button4;
	TLabel *Label10;
	TEdit *Edit5;
	TEdit *Edit6;
	TLabel *Label11;
	TBevel *Bevel1;
	TGroupBox *GroupBox1;
	TButton *Button2;
	TEdit *Edit1;
	TEdit *Edit2;
	TLabel *Label1;
	TLabel *Label2;
	TBevel *Bevel2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TButton *Button3;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall PaintBox1Paint(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Edit5KeyPress(TObject *Sender, char &Key);
	void __fastcall Edit6KeyPress(TObject *Sender, char &Key);
	void __fastcall Edit6Exit(TObject *Sender);
	void __fastcall Edit5Exit(TObject *Sender);
	void __fastcall Label5Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Edit1KeyPress(TObject *Sender, char &Key);
	void __fastcall Edit2KeyPress(TObject *Sender, char &Key);
	void __fastcall Edit2Exit(TObject *Sender);
	void __fastcall Edit1Exit(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm6(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm6 *Form6;
//---------------------------------------------------------------------------
#endif

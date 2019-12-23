//---------------------------------------------------------------------------

#ifndef UnitTicTacH
#define UnitTicTacH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Objects.hpp>
#include <FMX.Types.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
//---------------------------------------------------------------------------
const int FreeCell = 0;
const int iks = 1;
const int zero = 2;
const int frozen = 3;
														   /*
														   field [i][j]=0the cell is free
														   field [i][j]=1the cell is occupied by x
														   field [i][j]=2the cell is occupied by 0
														   field [i][j]=3the cell is frozen */
class TFormTicTac : public TForm
{
__published:	// IDE-managed Components
	TImage *ImageTicClose;
	TImage *ImageRetry;
	TImage *Im1;
	TImage *Im2;
	TImage *Im3;
	TImage *Im4;
	TImage *Im5;
	TImage *Im6;
	TImage *Im7;
	TImage *Im8;
	TImage *Im9;
	TImage *ImageNext;
	TImage *ImageWin;
	void __fastcall ImageTicCloseClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Im1Click(TObject *Sender);
	void __fastcall ImageRetryClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Im2Click(TObject *Sender);
	void __fastcall Im3Click(TObject *Sender);
	void __fastcall Im4Click(TObject *Sender);
	void __fastcall Im5Click(TObject *Sender);
	void __fastcall Im6Click(TObject *Sender);
	void __fastcall Im7Click(TObject *Sender);
	void __fastcall Im8Click(TObject *Sender);
	void __fastcall Im9Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
	__fastcall TFormTicTac(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormTicTac *FormTicTac;
//---------------------------------------------------------------------------
#endif

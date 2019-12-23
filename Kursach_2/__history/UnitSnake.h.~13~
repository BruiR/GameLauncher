//---------------------------------------------------------------------------

#ifndef UnitSnakeH
#define UnitSnakeH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Objects.hpp>
#include <FMX.Types.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
//---------------------------------------------------------------------------
const int FieldsPosition = 120;
const int N = 8, M = 8;
const int size = 70;
const int MaxSpeed = 300;

class TFormSnake : public TForm
{
__published:	// IDE-managed Components
	TImage *ImageLeftField;
	TImage *ImageCloseSnake;
	TImage *Image1;
	TTimer *Timer1;
	void __fastcall ImageCloseSnakeClick(TObject *Sender);
	void __fastcall Image1Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key, System::WideChar &KeyChar,
          TShiftState Shift);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);

private:	// User declarations
public:		// User declarations
	__fastcall TFormSnake(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormSnake *FormSnake;
//---------------------------------------------------------------------------
#endif

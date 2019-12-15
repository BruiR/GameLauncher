//---------------------------------------------------------------------------

#ifndef UnitSnakeH
#define UnitSnakeH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Objects.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
class TFormSnake : public TForm
{
__published:	// IDE-managed Components
	TImage *ImageLeftField;
	TImage *ImageCloseSnake;
	void __fastcall ImageCloseSnakeClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormSnake(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormSnake *FormSnake;
//---------------------------------------------------------------------------
#endif

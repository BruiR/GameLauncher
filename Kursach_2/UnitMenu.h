//---------------------------------------------------------------------------

#ifndef UnitMenuH
#define UnitMenuH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Objects.hpp>
#include <FMX.ImgList.hpp>
#include <System.ImageList.hpp>
//---------------------------------------------------------------------------
const int StandartWidth =444;
const int StandartHeight =228;
const int SelectWidth =429;
const int SelectHeight =220;

class TFormMainMenu : public TForm
{
__published:	// IDE-managed Components
	TImage *ImageClose;
	TImage *ImageSnake;
	TImage *ImageRandom;
	TImage *ImageKrestiki;
	TImage *Image4game;
	void __fastcall ImageCloseClick(TObject *Sender);
	void __fastcall ImageSnakeMouseMove(TObject *Sender, TShiftState Shift, float X,
          float Y);
	void __fastcall ImageRandomMouseMove(TObject *Sender, TShiftState Shift, float X,
          float Y);
	void __fastcall ImageKrestikiMouseMove(TObject *Sender, TShiftState Shift, float X,
          float Y);
	void __fastcall Image4gameMouseMove(TObject *Sender, TShiftState Shift, float X,
          float Y);
	void __fastcall ImageSnakeClick(TObject *Sender);
	void __fastcall ImageKrestikiClick(TObject *Sender);

	void __fastcall Image4gameClick(TObject *Sender);
	void __fastcall ImageRandomClick(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TFormMainMenu(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormMainMenu *FormMainMenu;
//---------------------------------------------------------------------------
#endif

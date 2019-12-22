//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "UnitMenu.h"
#include "UnitSnake.h"
#include "UnitTicTac.h"
#include "UnitInfo.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TFormMainMenu *FormMainMenu;

void MakeSize(TImage *Im, int WidthSize, int HeightSize);
//---------------------------------------------------------------------------
__fastcall TFormMainMenu::TFormMainMenu(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormMainMenu::ImageCloseClick(TObject *Sender)
{
 FormMainMenu->Close();
}
//---------------------------------------------------------------------------

void SelectIcon(TImage *SelectIm)
{                                                                             //reduce picture
  MakeSize(FormMainMenu->ImageSnake, StandartWidth, StandartHeight);
  MakeSize(FormMainMenu->Image4game, StandartWidth, StandartHeight);
  MakeSize(FormMainMenu->ImageKrestiki, StandartWidth, StandartHeight);
  MakeSize(FormMainMenu->ImageRandom, StandartWidth, StandartHeight);
  MakeSize(SelectIm, SelectWidth, SelectHeight);
}

void MakeSize(TImage *Im, int WidthSize, int HeightSize)                     //resize picture
{
  Im->Width=WidthSize;
  Im->Height=HeightSize;
}

void __fastcall TFormMainMenu::ImageSnakeMouseMove(TObject *Sender, TShiftState Shift,
		  float X, float Y)
{
  SelectIcon(ImageSnake);
}
//---------------------------------------------------------------------------
void __fastcall TFormMainMenu::ImageRandomMouseMove(TObject *Sender, TShiftState Shift,
          float X, float Y)
{
  SelectIcon(ImageRandom);
}
//---------------------------------------------------------------------------
void __fastcall TFormMainMenu::ImageKrestikiMouseMove(TObject *Sender, TShiftState Shift,
          float X, float Y)
{
  SelectIcon(ImageKrestiki);
}
//---------------------------------------------------------------------------
void __fastcall TFormMainMenu::Image4gameMouseMove(TObject *Sender, TShiftState Shift,
          float X, float Y)
{
  SelectIcon(Image4game);
}
//---------------------------------------------------------------------------
void __fastcall TFormMainMenu::ImageSnakeClick(TObject *Sender)
{
  FormSnake->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TFormMainMenu::ImageKrestikiClick(TObject *Sender)
{
  FormTicTac->ShowModal();
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

void __fastcall TFormMainMenu::Image4gameClick(TObject *Sender)
{
 FormInfo->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TFormMainMenu::ImageRandomClick(TObject *Sender)                // open random game
{
 srand ( time(NULL) );
 int RandomGame = rand()%2+ 1;
	switch (RandomGame)
	{
	 case 1:
		FormSnake->ShowModal();
		break;
	 case 2:
		FormTicTac->ShowModal();
	 }
}
//---------------------------------------------------------------------------


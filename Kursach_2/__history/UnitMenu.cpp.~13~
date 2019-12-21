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

void SelectIcon(TImage *Im, int WidthSize, int HeightSize);
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

void MakeRegularSizes()
{
  SelectIcon(FormMainMenu->ImageSnake, StandartWidth, StandartHeight);
  SelectIcon(FormMainMenu->Image4game, StandartWidth, StandartHeight);
  SelectIcon(FormMainMenu->ImageKrestiki, StandartWidth, StandartHeight);
  SelectIcon(FormMainMenu->ImageRandom, StandartWidth, StandartHeight);
}

void SelectIcon(TImage *Im, int WidthSize, int HeightSize)
{
  Im->Width=WidthSize;
  Im->Height=HeightSize;
}

void __fastcall TFormMainMenu::ImageSnakeMouseMove(TObject *Sender, TShiftState Shift,
		  float X, float Y)
{
  MakeRegularSizes();
  SelectIcon(ImageSnake, SelectWidth, SelectHeight);
}
//---------------------------------------------------------------------------
void __fastcall TFormMainMenu::ImageRandomMouseMove(TObject *Sender, TShiftState Shift,
          float X, float Y)
{
  MakeRegularSizes();
  SelectIcon(ImageRandom, SelectWidth, SelectHeight);
}
//---------------------------------------------------------------------------
void __fastcall TFormMainMenu::ImageKrestikiMouseMove(TObject *Sender, TShiftState Shift,
          float X, float Y)
{
  MakeRegularSizes();
  SelectIcon(ImageKrestiki, SelectWidth, SelectHeight);
}
//---------------------------------------------------------------------------
void __fastcall TFormMainMenu::Image4gameMouseMove(TObject *Sender, TShiftState Shift,
          float X, float Y)
{
  MakeRegularSizes();
  SelectIcon(Image4game, SelectWidth, SelectHeight);
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

void __fastcall TFormMainMenu::ImageRandomClick(TObject *Sender)
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


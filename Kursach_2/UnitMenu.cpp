//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "UnitMenu.h"
#include "UnitSnake.h"
#include "UnitTicTac.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TFormMainMenu *FormMainMenu;
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
void __fastcall TFormMainMenu::ImageSnakeMouseMove(TObject *Sender, TShiftState Shift,
          float X, float Y)
{
  FormMainMenu->ImageSnake->Width=429;
  FormMainMenu->ImageSnake->Height=220;

  FormMainMenu->Image4game->Width=444;
  FormMainMenu->Image4game->Height=228;

  FormMainMenu->ImageKrestiki->Width=444;
  FormMainMenu->ImageKrestiki->Height=228;

  FormMainMenu->ImagePong->Width=444;
  FormMainMenu->ImagePong->Height=228;

}
//---------------------------------------------------------------------------
void __fastcall TFormMainMenu::ImagePongMouseMove(TObject *Sender, TShiftState Shift,
          float X, float Y)
{
  FormMainMenu->ImagePong->Width=429;
  FormMainMenu->ImagePong->Height=220;

  FormMainMenu->ImageSnake->Width=444;
  FormMainMenu->ImageSnake->Height=228;

  FormMainMenu->ImageKrestiki->Width=444;
  FormMainMenu->ImageKrestiki->Height=228;

  FormMainMenu->Image4game->Width=444;
  FormMainMenu->Image4game->Height=228;

}
//---------------------------------------------------------------------------
void __fastcall TFormMainMenu::ImageKrestikiMouseMove(TObject *Sender, TShiftState Shift,
          float X, float Y)
{
  FormMainMenu->ImageKrestiki->Width=429;
  FormMainMenu->ImageKrestiki->Height=220;

  FormMainMenu->ImageSnake->Width=444;
  FormMainMenu->ImageSnake->Height=228;

  FormMainMenu->Image4game->Width=444;
  FormMainMenu->Image4game->Height=228;

  FormMainMenu->ImagePong->Width=444;
  FormMainMenu->ImagePong->Height=228;

}
//---------------------------------------------------------------------------
void __fastcall TFormMainMenu::Image4gameMouseMove(TObject *Sender, TShiftState Shift,
          float X, float Y)
{
  FormMainMenu->Image4game->Width=429;
  FormMainMenu->Image4game->Height=220;

  FormMainMenu->ImageSnake->Width=444;
  FormMainMenu->ImageSnake->Height=228;

  FormMainMenu->ImageKrestiki->Width=444;
  FormMainMenu->ImageKrestiki->Height=228;

  FormMainMenu->ImagePong->Width=444;
  FormMainMenu->ImagePong->Height=228;

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


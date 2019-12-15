//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "UnitSnake.h"
#include "UnitMenu.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TFormSnake *FormSnake;
//---------------------------------------------------------------------------
__fastcall TFormSnake::TFormSnake(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormSnake::ImageCloseSnakeClick(TObject *Sender)
{
 FormMainMenu->Visible=True;
 Close();
}
//---------------------------------------------------------------------------

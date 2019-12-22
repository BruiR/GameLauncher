//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "UnitInfo.h"
#include "UnitMenu.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TFormInfo *FormInfo;
//---------------------------------------------------------------------------

__fastcall TFormInfo::TFormInfo(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormInfo::ImageCloseClick(TObject *Sender)
{
 FormInfo->Close();
}
//---------------------------------------------------------------------------


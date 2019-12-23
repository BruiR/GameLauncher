//---------------------------------------------------------------------------
#include <cstdlib>
#include <fmx.h>
#pragma hdrstop

#include "UnitTicTac.h"
#include "UnitMenu.h"
#include <ctime>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TFormTicTac *FormTicTac;
//---------------------------------------------------------------------------

int field [4][4];                                         //game field
int Play;                                                 //who is playing now
void IsWin ();
void DrawAndCheck(int i,int j, TImage *Im);
//---------------------------------------------------------------------------
void Clear() //clear game field
{
 FormTicTac->Im1->Bitmap = NULL;
 FormTicTac->Im2->Bitmap = NULL;
 FormTicTac->Im3->Bitmap = NULL;
 FormTicTac->Im4->Bitmap = NULL;
 FormTicTac->Im5->Bitmap = NULL;
 FormTicTac->Im6->Bitmap = NULL;
 FormTicTac->Im7->Bitmap = NULL;
 FormTicTac->Im8->Bitmap = NULL;
 FormTicTac->Im9->Bitmap = NULL;
}
//---------------------------------------------------------------------------
__fastcall TFormTicTac::TFormTicTac(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void CloseGame()
{
	for (int i = 1; i < 4; i++)
		for (int j = 1; j < 4; j++)
		{
		 field[i][j]=FreeCell;
		}
 Clear();
 FormTicTac->ImageWin->Bitmap= NULL;
 FormTicTac->Close();
}
//---------------------------------------------------------------------------
void __fastcall TFormTicTac::ImageTicCloseClick(TObject *Sender)
{
 CloseGame();
}
//---------------------------------------------------------------------------
 void StartGame()
 {
  Clear();
  srand ( time(NULL) );
  Play = rand()%2 + 1;  //who is playing first
	if (Play == iks)
	{
	 FormTicTac->ImageNext->Bitmap->LoadFromFile("../../Photo/iks.png");
	}
	else
	{
	 FormTicTac->ImageNext->Bitmap->LoadFromFile("..//..//Photo//zero.png");
	}

   for (int i = 1; i < 4; i++)       //clear field array
		for (int j = 1; j < 4; j++)
		{
		 field[i][j]=FreeCell;
		}

 }

void __fastcall TFormTicTac::FormCreate(TObject *Sender)
{
 StartGame();
}
//---------------------------------------------------------------------------
void __fastcall TFormTicTac::Im1Click(TObject *Sender)
{
 DrawAndCheck(1,1,Im1);
}
//---------------------------------------------------------------------------
void __fastcall TFormTicTac::ImageRetryClick(TObject *Sender)
{
 StartGame();
 ImageWin->Bitmap= NULL;
}
//---------------------------------------------------------------------------
void __fastcall TFormTicTac::Button1Click(TObject *Sender)
{
 ImageNext->Bitmap = NULL;
}
//---------------------------------------------------------------------------
void DrawAndCheck(int i,int j, TImage *Im)   //draw x or 0 if cell is empty
{
  if ((Play ==iks) &&  (field[i][j]== FreeCell))
  {
   field[i][j]=iks;
   Play = zero;
   Im->Bitmap->LoadFromFile("../../Photo/iks.png");
   FormTicTac->ImageNext->Bitmap->LoadFromFile("..//..//Photo//zero.png");
  }
  else
	if ((Play ==zero) &&  (field[i][j]== FreeCell))
	{
	 field[i][j]=zero;
	 Play = iks;
	 Im->Bitmap->LoadFromFile("../../Photo/zero.png");
	 FormTicTac->ImageNext->Bitmap->LoadFromFile("../../Photo/iks.png");
	}
 IsWin ();
}
//---------------------------------------------------------------------------
void __fastcall TFormTicTac::Im2Click(TObject *Sender)
{
 DrawAndCheck(1,2,Im2);
}
//---------------------------------------------------------------------------
void __fastcall TFormTicTac::Im3Click(TObject *Sender)
{
 DrawAndCheck(1,3,Im3);
}
//---------------------------------------------------------------------------
void __fastcall TFormTicTac::Im4Click(TObject *Sender)
{
 DrawAndCheck(2,1,Im4);
}
//---------------------------------------------------------------------------
void __fastcall TFormTicTac::Im5Click(TObject *Sender)
{
 DrawAndCheck(2,2,Im5);
}
//---------------------------------------------------------------------------
void __fastcall TFormTicTac::Im6Click(TObject *Sender)
{
 DrawAndCheck(2,3,Im6);
}
//---------------------------------------------------------------------------
void __fastcall TFormTicTac::Im7Click(TObject *Sender)
{
 DrawAndCheck(3,1,Im7);
}
//---------------------------------------------------------------------------
void __fastcall TFormTicTac::Im8Click(TObject *Sender)
{
 DrawAndCheck(3,2,Im8);
}
//---------------------------------------------------------------------------
void __fastcall TFormTicTac::Im9Click(TObject *Sender)
{
 DrawAndCheck(3,3,Im9);
}
//---------------------------------------------------------------------------
void FreezeField()      //freeze all cell if smbdy win
{
 for (int q = 1; q < 4; q++)
	for (int w = 1; w < 4; w++)
	{
	 field[q][w]=frozen;
	}
}
//---------------------------------------------------------------------------
void DiagonalCheck()
{
  if ( (((field[1][1]== field[2][2]) && (field[2][2]== field[3][3])) || ((field[1][3]== field[2][2]) && (field[2][2]== field[3][1]))) && (field[2][2]!=FreeCell))
  {
	if (field[2][2]==iks)
	{
	 FormTicTac->ImageWin->Bitmap->LoadFromFile("../../Photo/x_win.png");
	 FreezeField();
	}
	if (field[2][2]==zero)
	{
	 FormTicTac->ImageWin->Bitmap->LoadFromFile("../../Photo/zero_win.png");
	 FreezeField();
	}
  }
}
//---------------------------------------------------------------------------
void ColumnCheck()
{
  for (int q=1; q <= 3; q++)
  {
	if (((field[1][q]== field[2][q]) && ( field[2][q]== field[3][q])) && field[1][q]!=FreeCell)
	{
	   if (field[1][q]==iks)
	   {
		 FormTicTac->ImageWin->Bitmap->LoadFromFile("../../Photo/x_win.png");
		 FreezeField();
	   }
	   else
		if (field[1][q]==zero)
		{
		 FormTicTac->ImageWin->Bitmap->LoadFromFile("../../Photo/zero_win.png");
		 FreezeField();
		}
	}
  }
}
//---------------------------------------------------------------------------
void RowCheck()
{
  for (int q=1; q <= 3; q++)
  {
	if (((field[q][1]== field[q][2]) && ( field[q][2]== field[q][3])) && field[q][1]!=FreeCell)
	{
		if (field[q][1]==iks)
		{
		 FormTicTac->ImageWin->Bitmap->LoadFromFile("../../Photo/x_win.png");
		 FreezeField();
		}

		if (field[q][1]==zero)
		{
		 FormTicTac->ImageWin->Bitmap->LoadFromFile("../../Photo/zero_win.png");
         FreezeField();
		}
	}
  }
}
//---------------------------------------------------------------------------
void IsWin()
{
 RowCheck();
 ColumnCheck();
 DiagonalCheck();
}
//---------------------------------------------------------------------------
void __fastcall TFormTicTac::FormClose(TObject *Sender, TCloseAction &Action)
{
 CloseGame();
}
//---------------------------------------------------------------------------


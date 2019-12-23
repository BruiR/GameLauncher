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

int field [4][4];                                        /*game field
														   field [i][j]=0the cell is free
														   field [i][j]=1the cell is occupied by x
														   field [i][j]=2the cell is occupied by 0
														   field [i][j]=3the cell is frozen */

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
		 field[i][j]=0;
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
	if (Play == 1)
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
		 field[i][j]=0;
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
  if ((Play ==1) &&  (field[i][j]== 0))
  {
   field[i][j]=1;
   Play = 2;
   Im->Bitmap->LoadFromFile("../../Photo/iks.png");
   FormTicTac->ImageNext->Bitmap->LoadFromFile("..//..//Photo//zero.png");
  }
  else
	if ((Play ==2) &&  (field[i][j]== 0))
	{
	 field[i][j]=2;
	 Play = 1;
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
	 field[q][w]=3;
	}
}
//---------------------------------------------------------------------------
void DiagonalCheck()
{
  if ( (((field[1][1]== field[2][2]) && (field[2][2]== field[3][3])) || ((field[1][3]== field[2][2]) && (field[2][2]== field[3][1]))) && (field[2][2]!=0))
  {
	if (field[2][2]==1)
	{
	 FormTicTac->ImageWin->Bitmap->LoadFromFile("../../Photo/x_win.png");
	 FreezeField();
	}
	if (field[2][2]==2)
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
	if (((field[1][q]== field[2][q]) && ( field[2][q]== field[3][q])) && field[1][q]!=0)
	{
	   if (field[1][q]==1)
	   {
		 FormTicTac->ImageWin->Bitmap->LoadFromFile("../../Photo/x_win.png");
		 FreezeField();
	   }
	   else
		if (field[1][q]==2)
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
	if (((field[q][1]== field[q][2]) && ( field[q][2]== field[q][3])) && field[q][1]!=0)
	{
		if (field[q][1]==1)
		{
		 FormTicTac->ImageWin->Bitmap->LoadFromFile("../../Photo/x_win.png");
		 FreezeField();
		}

		if (field[q][1]==2)
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


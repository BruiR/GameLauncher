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

int field [4][4];
int Play;  
void IsWin ();    
void DrawAndCheck(int i,int j, int Player, TImage *Im);

void Clear()
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
void __fastcall TFormTicTac::FormCreate(TObject *Sender)
{
 Clear();
 srand ( time(NULL) );
 Play = rand()%2 + 1;
	if (Play == 1)
	{
	 FormTicTac->ImageNext->Bitmap->LoadFromFile("../../Photo/iks.png");
	}
	else
	{
	 FormTicTac->ImageNext->Bitmap->LoadFromFile("..//..//Photo//zero.png");
	}

   for (int i = 1; i < 4; i++)
		for (int j = 1; j < 4; j++)
		{
		 field[i][j]=0;
		}
}
//---------------------------------------------------------------------------
void __fastcall TFormTicTac::Im1Click(TObject *Sender)
{
 DrawAndCheck(1,1, Play, Im1);
}
//---------------------------------------------------------------------------
void __fastcall TFormTicTac::ImageRetryClick(TObject *Sender)
{
 srand ( time(NULL) );
 Play = rand()%2+ 1;
	if (Play == 1)
	{
	 FormTicTac->ImageNext->Bitmap->LoadFromFile("../../Photo/iks.png");
	}
	else
	{
	FormTicTac->ImageNext->Bitmap->LoadFromFile("..//..//Photo//zero.png");
	}

	for (int i = 1; i < 4; i++)
		for (int j = 1; j < 4; j++)
		{
		 field[i][j]=0;
		}
 ImageWin->Bitmap= NULL;
 Clear();
}
//---------------------------------------------------------------------------
void __fastcall TFormTicTac::Button1Click(TObject *Sender)
{
 ImageNext->Bitmap = NULL;
}
//---------------------------------------------------------------------------
void DrawAndCheck(int i,int j, int Player, TImage *Im)
{
  if ((Player ==1) &&  (field[i][j]== 0))
  {
   field[i][j]=1;
   Play = 2;
   Im->Bitmap->LoadFromFile("../../Photo/iks.png");
  }
  else
	if ((Player ==2) &&  (field[i][j]== 0))
	{
	 field[i][j]=2;
	 Play = 1;
	 Im->Bitmap->LoadFromFile("../../Photo/zero.png");
	}

 if (Play == 1)
  {
	FormTicTac->ImageNext->Bitmap->LoadFromFile("../../Photo/iks.png");
  }
 else
  FormTicTac->ImageNext->Bitmap->LoadFromFile("..//..//Photo//zero.png");

 IsWin ();
}
//---------------------------------------------------------------------------
void __fastcall TFormTicTac::Im2Click(TObject *Sender)
{
 DrawAndCheck(1,2, Play, Im2);
}
//---------------------------------------------------------------------------
void __fastcall TFormTicTac::Im3Click(TObject *Sender)
{
 DrawAndCheck(1,3, Play, Im3);
}
//---------------------------------------------------------------------------
void __fastcall TFormTicTac::Im4Click(TObject *Sender)
{
 DrawAndCheck(2,1, Play, Im4);
}
//---------------------------------------------------------------------------
void __fastcall TFormTicTac::Im5Click(TObject *Sender)
{
 DrawAndCheck(2,2, Play, Im5);
}
//---------------------------------------------------------------------------
void __fastcall TFormTicTac::Im6Click(TObject *Sender)
{
 DrawAndCheck(2,3, Play, Im6);
}
//---------------------------------------------------------------------------
void __fastcall TFormTicTac::Im7Click(TObject *Sender)
{
 DrawAndCheck(3,1, Play, Im7);
}
//---------------------------------------------------------------------------
void __fastcall TFormTicTac::Im8Click(TObject *Sender)
{
 DrawAndCheck(3,2, Play, Im8);
}
//---------------------------------------------------------------------------
void __fastcall TFormTicTac::Im9Click(TObject *Sender)
{
 DrawAndCheck(3,3, Play, Im9);
}
//---------------------------------------------------------------------------
void FreezeField()
{
 for (int q = 1; q < 4; q++)
	for (int w = 1; w < 4; w++)
	{
	 field[q][w]=3;
	}
}


void DiagonalCheck()
{
  if (((field[1][1]== field[2][2]) && (field[2][2]== field[3][3])) || ((field[1][3]== field[2][2]) && (field[2][2]== field[3][1])) && (field[2][2]!=0))
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


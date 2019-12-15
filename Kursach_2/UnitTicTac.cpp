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
void otrisovka(int i,int j, int Player, TImage *Im);
__fastcall TFormTicTac::TFormTicTac(TComponent* Owner)
	: TForm(Owner)
{
}
//--------------------------------------------------------------------------- 
void __fastcall TFormTicTac::ImageTicCloseClick(TObject *Sender)
{
 for (int i = 1; i < 4; i++)
 {
	for (int j = 1; j < 4; j++)
	{
		field[i][j]=0;
	}
 }
 Im1->Bitmap = NULL;
 Im2->Bitmap = NULL;
 Im3->Bitmap = NULL;
 Im4->Bitmap = NULL;
 Im5->Bitmap = NULL;
 Im6->Bitmap = NULL;
 Im7->Bitmap = NULL;
 Im8->Bitmap = NULL;
 Im9->Bitmap = NULL;
 FormTicTac->Close();
}                   
//---------------------------------------------------------------------------
void __fastcall TFormTicTac::FormCreate(TObject *Sender)
{
 Im1->Bitmap = NULL;
 Im2->Bitmap = NULL;
 Im3->Bitmap = NULL;
 Im4->Bitmap = NULL;
 Im5->Bitmap = NULL;
 Im6->Bitmap = NULL;
 Im7->Bitmap = NULL;
 Im8->Bitmap = NULL;
 Im9->Bitmap = NULL;
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
 {
	for (int j = 1; j < 4; j++)
	{
		field[i][j]=0;
	}
 }
}
//---------------------------------------------------------------------------

void __fastcall TFormTicTac::Im1Click(TObject *Sender)
{
 otrisovka(1,1, Play, Im1);

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
 {
	for (int j = 1; j < 4; j++)
	{
		field[i][j]=0;
	}
 }
 ImageWin->Bitmap= NULL;
 Im1->Bitmap = NULL;
 Im2->Bitmap = NULL;
 Im3->Bitmap = NULL;
 Im4->Bitmap = NULL;
 Im5->Bitmap = NULL;
 Im6->Bitmap = NULL;
 Im7->Bitmap = NULL;
 Im8->Bitmap = NULL;
 Im9->Bitmap = NULL;
}
//---------------------------------------------------------------------------
void __fastcall TFormTicTac::Button1Click(TObject *Sender)
{

ImageNext->Bitmap = NULL;
}
//---------------------------------------------------------------------------


void otrisovka(int i,int j, int Player, TImage *Im)
{
   if ((Player ==1) &&  (field[i][j]== 0))
 {
	 field[i][j]=1;
	 Play = 2;
	 Im->Bitmap->LoadFromFile("../../Photo/iks.png");
 } else
	{
	 if ((Player ==2) &&  (field[i][j]== 0))
	 {
	 field[i][j]=2;
	 Play = 1;
	 Im->Bitmap->LoadFromFile("../../Photo/zero.png");
	 }
	}
if (Play == 1)
  {
	FormTicTac->ImageNext->Bitmap->LoadFromFile("../../Photo/iks.png");
  }
	else
	{
	FormTicTac->ImageNext->Bitmap->LoadFromFile("..//..//Photo//zero.png");
	}
 IsWin (); 
}
void __fastcall TFormTicTac::Im2Click(TObject *Sender)
{
otrisovka(1,2, Play, Im2);
}
//---------------------------------------------------------------------------

void __fastcall TFormTicTac::Im3Click(TObject *Sender)
{
otrisovka(1,3, Play, Im3);
}
//---------------------------------------------------------------------------

void __fastcall TFormTicTac::Im4Click(TObject *Sender)
{
otrisovka(2,1, Play, Im4);
}
//---------------------------------------------------------------------------

void __fastcall TFormTicTac::Im5Click(TObject *Sender)
{
otrisovka(2,2, Play, Im5);
}
//---------------------------------------------------------------------------

void __fastcall TFormTicTac::Im6Click(TObject *Sender)
{
otrisovka(2,3, Play, Im6);
}
//---------------------------------------------------------------------------

void __fastcall TFormTicTac::Im7Click(TObject *Sender)
{
otrisovka(3,1, Play, Im7);
}
//---------------------------------------------------------------------------

void __fastcall TFormTicTac::Im8Click(TObject *Sender)
{
otrisovka(3,2, Play, Im8);
}
//---------------------------------------------------------------------------

void __fastcall TFormTicTac::Im9Click(TObject *Sender)
{
otrisovka(3,3, Play, Im9);
}
//---------------------------------------------------------------------------

void IsWin()
{
//FormTicTac->ImageNext->Bitmap = NULL;
//FormTicTac->ImageTicClose->Visible = False;
 for (int q=1; q <= 3; q++) 
 {
 //�������� �� �������
  if (((field[q][1]== field[q][2]) && ( field[q][2]== field[q][3])) && field[q][1]!=0)
  {
	if (field[q][1]==1) 
	{
		FormTicTac->ImageWin->Bitmap->LoadFromFile("../../Photo/x_win.png");
		for (int qq = 1; qq < 4; qq++)
		{
			for (int ww = 1; ww < 4; ww++)
			{
			field[qq][ww]=3;
			}
		}	
	}  
	if (field[q][1]==2) 
	{
		FormTicTac->ImageWin->Bitmap->LoadFromFile("../../Photo/zero_win.png");
			for (int qq = 1; qq < 4; qq++)
		{
			for (int ww = 1; ww < 4; ww++)
			{
			field[qq][ww]=3;
			}
		}	
	} 
  }	 
  //�� ��������
  if (((field[1][q]== field[2][q]) && ( field[2][q]== field[3][q])) && field[1][q]!=0)
  {
	if (field[1][q]==1) 
	{
		FormTicTac->ImageWin->Bitmap->LoadFromFile("../../Photo/x_win.png");
		for (int qq = 1; qq < 4; qq++)
		{
			for (int ww = 1; ww < 4; ww++)
			{
			field[qq][ww]=3;
			}
		}	
	}  
	if (field[1][q]==2) 
	{
		FormTicTac->ImageWin->Bitmap->LoadFromFile("../../Photo/zero_win.png");
			for (int qq = 1; qq < 4; qq++)
		{
			for (int ww = 1; ww < 4; ww++)
			{
			field[qq][ww]=3;
			}
		}	
	} 
  }	 
  // �������� �� ����������

  if (  ((field[1][1]== field[2][2]) && ( field[2][2]== field[3][3])) || ( (field[1][3]== field[2][2]) && ( field[2][2]== field[3][1]) ) && (field[2][2]!=0) )
  {
	if (field[2][2]==1) 
	{
		FormTicTac->ImageWin->Bitmap->LoadFromFile("../../Photo/x_win.png");
		for (int qq = 1; qq < 4; qq++)
		{
			for (int ww = 1; ww < 4; ww++)
			{
			field[qq][ww]=3;
			}
		}	
	}  
	if (field[2][2]==2) 
	{
		FormTicTac->ImageWin->Bitmap->LoadFromFile("../../Photo/zero_win.png");
			for (int qq = 1; qq < 4; qq++)
		{
			for (int ww = 1; ww < 4; ww++)
			{
			field[qq][ww]=3;
			}
		}	
	} 
  }	 


   
 }
 
 


 
}

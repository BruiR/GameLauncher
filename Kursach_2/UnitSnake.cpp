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
int dir, num = 1;
int Speed = 500;   //speed of snake
TImage* t[8][8];   //snake pic
TImage* coin;      //fruit pic
struct Snake       //x,y of snake
{
 int x, y;
} s[70];

struct Fruit       //x,y of apple
{
 int x, y;
} f;

void EraseTheSnake();
void draw();
void Tick();

__fastcall TFormSnake::TFormSnake(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void CloseSnakeGame()
{
 EraseTheSnake();
 num = 0;
 coin->Visible=false;
 FormSnake->Timer1->Enabled=False;
 FormMainMenu->Visible=True;
 FormSnake->Close();
}


void __fastcall TFormSnake::ImageCloseSnakeClick(TObject *Sender)
{
 CloseSnakeGame();
}
//---------------------------------------------------------------------------
void __fastcall TFormSnake::Image1Click(TObject *Sender) //start game
{

 num=1;
 s[0].x = rand() % N;    //place snake  randomly
 s[0].y = rand() % M;
 f.x = rand() % N;       //place apple  randomly
 f.y = rand() % M;
 coin->Position->X=FieldsPosition+(f.x)*size;  //redraw apple
 coin->Position->Y=FieldsPosition+(f.y)*size;
 FormSnake->Timer1->Interval = Speed;
 FormSnake->Timer1->Enabled=True;
 coin->Visible=true;
}
//---------------------------------------------------------------------------

void AppleLoading()
{
 coin = new TImage (FormSnake);
 coin->Visible=false;
 coin->Bitmap->LoadFromFile("../../Photo/snake/coin.png");
 coin->Width=size;
 coin->Height=size;
 coin->Parent = FormSnake;
}

void SnakeLoading()
{
 for (int i=0; i<N; i++)
	for (int j=0; j<M; j++)
	{
	 t[i][j]= new TImage (FormSnake);
	 t[i][j]->Visible=false;
	 t[i][j]->Bitmap->LoadFromFile("../../Photo/snake/telo3.png");
	 t[i][j]->Position->X=FieldsPosition+(i)*size;
	 t[i][j]->Position->Y=FieldsPosition+(j)*size;
	 t[i][j]->Width=size;
	 t[i][j]->Height=size;
	 t[i][j]->Parent = FormSnake;
	}
}


void __fastcall TFormSnake::FormCreate(TObject *Sender)
{
 FormSnake->Timer1->Enabled=False;
 AppleLoading();
 SnakeLoading();
}
//---------------------------------------------------------------------------

int IsAppleInSnake()    //Did apple appeare in snake?
{
 for (int i = 0; i < num; i++)
	if (s[i].x == f.x && s[i].y == f.y)
	{
	 return 1;
	}
 return 0;
}

void NewShift()
{
	switch (dir)
	{
	 case 0:
		s[0].y += 1;
		break;
	 case 1:
		s[0].x -= 1;
		break;
	 case 2:
		s[0].x += 1;
		break;
	 case 3:
		s[0].y -= 1;
	 }
}

void EatTheApple()   //Have you eaten an apple?
{
 if ((s[0].x == f.x) && (s[0].y == f.y))
	{
	 num++;
		while (IsAppleInSnake())
		{
		 f.x = rand() % N;
		 f.y = rand() % M;
		}
	 if(FormSnake->Timer1->Interval > MaxSpeed)
	  FormSnake->Timer1->Interval -=25;

	 coin->Position->X=FieldsPosition+(f.x)*size;
	 coin->Position->Y=FieldsPosition+(f.y)*size;
	}
}

void DirectionIntoWall()
{
 if (s[0].x > N-1) s[0].x = 0;
 if (s[0].x < 0) s[0].x = N-1;
 if (s[0].y > M-1) s[0].y = 0;
 if (s[0].y < 0) s[0].y = M-1;
}

void DeathCheck()
{
	for (int i = 1; i < num; i++)
		if (s[0].x == s[i].x && s[0].y == s[i].y)
		{
		 num = 0;
		 coin->Visible=false;
		 FormSnake->Timer1->Enabled=False;
		}
}

void BodyShift()
{
	for (int i = num; i > 0; --i)
	{
	 s[i].x = s[i - 1].x;
	 s[i].y = s[i - 1].y;
	}
}

void Tick()
{
 BodyShift();
 NewShift();
 DirectionIntoWall();
 EatTheApple();
 DeathCheck();
}

void EraseTheSnake() //delete old snake
{
	for (int i=0; i<N; i++)
		for (int j=0; j<M; j++)
		{
		 t[i][j]->Visible=false;
		}
}

void draw() //redraw snake
{
 EraseTheSnake();
 int x_1,y_1;
	for (int i=0;i<num;i++)
	{
	 x_1= s[i].x;
	 y_1= s[i].y;
	 t[x_1][y_1]->Visible=true;
	}
}

void __fastcall TFormSnake::Timer1Timer(TObject *Sender) //Game loop
{
	 Tick();
	 draw();
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

void __fastcall TFormSnake::FormKeyDown(TObject *Sender, WORD &Key, System::WideChar &KeyChar,
          TShiftState Shift)
{
	switch (Key)   //New Direction
	{
	 case vkLeft:
		dir = 1;
		break;
	 case vkRight:
		dir = 2;
		break;
	 case vkUp:
		dir = 3;
		break;
	 case vkDown:
		dir = 0;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TFormSnake::FormClose(TObject *Sender, TCloseAction &Action)
{
 CloseSnakeGame();
}
//---------------------------------------------------------------------------


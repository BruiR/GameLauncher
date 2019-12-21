//---------------------------------------------------------------------------

#include <fmx.h>
#ifdef _WIN32
#include <tchar.h>
#endif
#pragma hdrstop
#include <System.StartUpCopy.hpp>
//---------------------------------------------------------------------------
USEFORM("UnitTicTac.cpp", FormTicTac);
USEFORM("UnitSnake.cpp", FormSnake);
USEFORM("UnitMenu.cpp", FormMainMenu);
USEFORM("UnitInfo.cpp", FormInfo);
//---------------------------------------------------------------------------
extern "C" int FMXmain()
{
	try
	{
		Application->Initialize();
		Application->CreateForm(__classid(TFormMainMenu), &FormMainMenu);
		Application->CreateForm(__classid(TFormSnake), &FormSnake);
		Application->CreateForm(__classid(TFormTicTac), &FormTicTac);
		Application->CreateForm(__classid(TFormInfo), &FormInfo);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------

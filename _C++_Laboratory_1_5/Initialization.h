#pragma once
#include "OOP_Menu.h"
#include "Laba5.h"

class Init
{
private:
	Menu lab5;
public:

	Init()
	{
		lab5.AddMenuItem("ног: ", RNP);
	}
	void Show_Lab()
	{
		lab5.ShowMenu();
	}
};
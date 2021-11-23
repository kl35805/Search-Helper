#include <nana/gui.hpp>
#include "kid.h"
#include "add.h"
#include "del.h"
#include "alert.h"
#include "init_browser.h"
#include <iostream>
#include <fstream>
#include <Windows.h>
#define _WIN32_WINNT 0x0500
using namespace nana;
using namespace std;

int main()
{
	HWND hWnd = GetConsoleWindow();
	ShowWindow(hWnd, SW_HIDE);
	ifstream check_init("./txts/userbrowser.txt");
	if (!check_init.is_open())
	{
		init_browser ib(0);
		ib.show();
		exec();
	}
	else
		check_init.close();
	kid k(0);
	k.show();
	exec();
}
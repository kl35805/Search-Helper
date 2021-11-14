#include <nana/gui.hpp> // always include this
#include "kid.h"
#include <Windows.h>

using namespace nana;

int CALLBACK WinMain(__in HINSTANCE hInstance, __in HINSTANCE hPrevInstance, __in LPSTR lpCmdLine, __in int nCmdShow)
{
	kid k(0);
	k.show();
    //Start to event loop process, it blocks until the form is closed.
    exec();
}
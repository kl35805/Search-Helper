#include <nana/gui.hpp>
#include <iostream>
#include "kid.h"
#include "add.h"
#include "del.h"
#include "alert.h"
//#include "init_browser.h"

using namespace nana;

int main()
{
	kid k(0);
	add a(0);
	del d(0);
	alert al(0);
	k.set_ptr(&a, &d, &al);
	a.set_ptr(&k, &d, &al);
	d.set_ptr(&k, &a, &al);
	al.set_ptr(&k, &a, &d);
	k.show();
	exec();
}
#include <nana/gui.hpp>
#include "kid.h"
#include "add.h"
#include "del.h"
#include "alert.h"
#include "init_browser.h"
#include <iostream>
#include <fstream>
#include <nana/threads/pool.hpp>
#include <thread>
using namespace nana;
using namespace std;

int main()
{
	ifstream check_init("./txts/userbrowser.txt");
	if (!check_init.is_open())
	{
		thread init_thr([=]
			{
				init_browser ib(0);
				ib.show();
				exec();
			});
		init_thr.join();
	}
	else
		check_init.close();
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
	delete& k;
	delete& a;
	delete& d;
	delete& al;
}
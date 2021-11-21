#include "kid.h"
#include "add.h"
#include "del.h"
#include "alert.h"
#include <iostream>
#include <fstream>

using namespace nana;
using namespace std;

void add::set_ptr(kid* kk, del* dd, alert* ale)
{
	k = kk;
	d = dd;
	al = ale;
}

add::add(nana::window wd, const ::nana::size& sz, const nana::appearance& apr): nana::form(wd, sz, apr)
{
	init_();

	//<*ctor
	browser_button.events().click([=]
		{
			string b = browser_box.text();
			fstream bout("./txts/userbrowser.txt", ios::app);
			if (bout.eof())
				bout << b;
			else
			{
				bout.put('\n');
				bout << b;
			}
			bout.close();
			al->show();
			exec();
		});
	site_button.events().click([=]
		{
			string s = site_box.text();
			string u = url_box.text();
			fstream sout("./txts/usersite.txt", ios::app);
			fstream uout("./txts/userurl.txt", ios::app);
			if (sout.eof())
				sout << s;
			else
			{
				sout.put('\n');
				sout << s;
			}
			if (uout.eof())
				uout << u;
			else
			{
				uout.put('\n');
				uout << u;
			}
			sout.close();
			uout.close();
			al->show();
			exec();
		});
	//*>
}
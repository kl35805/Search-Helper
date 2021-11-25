#include "kid.h"
#include "add.h"
#include "del.h"
#include "alert.h"
#include "failure.h"
#include <iostream>
#include <fstream>
#include <thread>

using namespace nana;
using namespace std;

add::add(kid* kk, nana::window wd, const ::nana::size& sz, const nana::appearance& apr): nana::form(wd, sz, apr)
{
	k = kk;
	init_();

	//<*ctor
	browser_button.events().click([=]
		{
			string b = browser_box.text();
			if (b == "")
			{
				failure fa(this, NULL, 0);
				fa.show();
				fa.modality();
			}
			else
			{
				fstream bout("./txts/userbrowser.txt", ios::app);
				if (bout.eof())
					bout << b;
				else
				{

					bout.put('\n');
					bout << b;
				}
				bout.close();
				k->reset_variables();
				k->reset_comboxs();
				alert al(this, NULL, 0);
				al.show();
				al.modality();
			}
		});
	site_button.events().click([=]
		{
			string s = site_box.text();
			string u = url_box.text();
			if (s == "" || u == "")
			{
				failure fa(this, NULL, 0);
				fa.show();
				fa.modality();
			}
			else
			{
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
				k->reset_variables();
				k->reset_comboxs();
				alert al(this, NULL, 0);
				al.show();
				al.modality();
			}
		});
	//*>
}
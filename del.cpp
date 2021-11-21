#include <nana/gui.hpp>
#include <nana/gui/place.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/widgets/combox.hpp>
#include <nana/gui/widgets/button.hpp>
#include "kid.h"
#include "add.h"
#include "del.h"
#include "alert.h"
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <fstream>

using namespace nana;
using namespace std;

void del::set_ptr(kid* kk, add* aa, alert* ale)
{
	k = kk;
	a = aa;
	al = ale;
}
void del::set_variables(const vector<string>& vv, const map<string, string>& m1)
{
	Browsers = vv;
	Website_Urls = m1;
}
void del::load_list()
{
	for (int i = 0; i < Browsers.size(); i++)
		browser_list.push_back(Browsers[i]);
	map<string, string>::iterator uit;
	for (uit = Website_Urls.begin(); uit != Website_Urls.end(); uit++)
		site_list.push_back(uit->first);
}

del::del(nana::window wd, const ::nana::size& sz, const nana::appearance& apr): nana::form(wd, sz, apr)
{
	init_();

	//<*ctor
	browser_button.events().click([=]
		{
			string b = browser_list.text(browser_list.option());
			vector<std::string>::iterator it;
			for (it = Browsers.begin(); it != Browsers.end(); it++)
			{
				if (*it == b)
				{
					Browsers.erase(it);
					break;
				}
			}
			ofstream bout("./txts/userbrowser.txt");
			for (it = Browsers.begin(); it != Browsers.end(); it++)
			{
				if (it == Browsers.end() - 1)
					bout << *it;
				else
					bout << *it << std::endl;
			}
			bout.close();
			al->show();
			exec();
		});
	site_button.events().click([=]
		{
			string s = site_list.text(site_list.option());
			string u = Website_Urls.find(site_list.text(site_list.option()))->second;
			map<std::string, std::string>::iterator it;
			for (it = Website_Urls.begin(); it != Website_Urls.end();)
			{
				if (it->first == s)
					Website_Urls.erase(it++);
				else
					++it;
			}
			vector<std::string> stemp;
			vector<std::string> utemp;
			for (it = Website_Urls.begin(); it != Website_Urls.end(); it++)
			{
				stemp.push_back(it->first);
				utemp.push_back(it->second);
			}
			ofstream sout("./txts/usersite.txt");
			ofstream uout("./txts/userurl.txt");
			vector<std::string>::iterator ite;
			for (ite = stemp.begin(); ite != stemp.end(); ite++)
			{
				if (ite == stemp.end() - 1)
					sout << *ite;
				else
					sout << *ite << std::endl;
			}
			for (ite = utemp.begin(); ite != utemp.end(); ite++)
			{
				if (ite == utemp.end() - 1)
					uout << *ite;
				else
					uout << *ite << std::endl;
			}
			sout.close();
			uout.close();
			al->show();
			exec();
		});
	//*>
}
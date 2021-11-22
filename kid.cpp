#include "kid.h"
#include "add.h"
#include "del.h"
#include "alert.h"
#include <nana/gui.hpp>
#include <nana/gui/place.hpp>
#include <nana/gui/widgets/combox.hpp>
#include <nana/gui/widgets/picture.hpp>
#include <nana/gui/widgets/panel.hpp>
#include <nana/gui/widgets/button.hpp>
#include <nana/gui/widgets/textbox.hpp>
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <shellapi.h>
#include <string>
#include <vector>
#include <map>

void kid::set_ptr(add* aa, del* dd, alert* ale)
{
	a = aa;
	d = dd;
	al = ale;
}

void kid::makeBrowsers()
{
	std::ifstream bin("./txts/userbrowser.txt");
	std::string bline;
	while (!bin.eof())
	{
		getline(bin, bline);
		Browsers.push_back(bline);
	}
	bin.close();
}

void kid::makeUrls()
{
	std::ifstream unin("./txts/usersite.txt");
	std::ifstream uuin("./txts/userurl.txt");
	std::string nline;
	std::string uline;
	while (!unin.eof())
	{
		getline(unin, nline);
		getline(uuin, uline);
		nana::to_utf8(nline);
		Website_Urls.insert({ nline,uline });
	}
	unin.close();
	uuin.close();
}

void kid::makeBicons()
{
	std::ifstream bin("./txts/browser.txt");
	std::ifstream iin("./txts/bicon.txt");
	std::string bline;
	std::string iline;
	while (!bin.eof())
	{
		getline(bin, bline);
		getline(iin, iline);
		Browser_Icons.insert({ bline,iline });
	}
	bin.close();
	iin.close();
}

void kid::makeSicons()
{
	std::ifstream sin("./txts/site.txt");
	std::ifstream iin("./txts/sicon.txt");
	std::string sline;
	std::string iline;
	while (!sin.eof())
	{
		getline(sin, sline);
		getline(iin, iline);
		Website_Icons.insert({ sline,iline });
	}
	sin.close();
	iin.close();
}

void kid::set_comboxs()
{
	for (int i = 0; i < Browsers.size(); i++)
		browser.push_back(Browsers[i]);
	std::map<std::string, std::string>::iterator uit;
	for (uit = Website_Urls.begin(); uit != Website_Urls.end(); uit++)
		site.push_back(uit->first);
}

void kid::reg_events()
{
	goto_add.events().click([=]
		{
			a->show();
			nana::exec();
		});
	goto_del.events().click([=]
		{
			d->set_variables(Browsers, Website_Urls);
			d->load_list();
			d->show();
			nana::exec();
		});
	letsgo.events().click([=]
		{
			searchbar.hide();
			upper_lip.move(nana::rectangle(49, 151, 270, 12));
			lower_lip.move(nana::rectangle(49, 163, 270, 12));
			open_search();
			searchbar.caption("");
		});
	browser.events().text_changed([=]
		{
			std::string cur_brws = browser.text(browser.option());
			std::map<std::string, std::string>::iterator it;
			for (it = Browser_Icons.begin(); it != Browser_Icons.end(); it++)
			{
				if (it->first == cur_brws)
				{
					nana::paint::image bimage(it->second);
					bicon.load(bimage);
					bicon.stretchable(0, 0, 0, 0);
					return;
				}
			}
			nana::paint::image uimage("./browsers_icon/user.bmp");
			bicon.load(uimage);
			bicon.stretchable(0, 0, 0, 0);
			left_eyebrow.show();
			left_eyebrow_click = false;
		});
	browser.events().mouse_leave([&]() {
		browser.hide();
		left_eyebrow.show();
		left_eyebrow_click = false;
	});
	left_eyebrow.events().click([&] {
		if (left_eyebrow_click == false) {
			left_eyebrow.hide();
			browser.show();
			left_eyebrow_click = true;
		}
	});
	site.events().text_changed([=]
		{
			std::string cur_site = site.text(site.option());
			if (Website_Icons.find(cur_site) != Website_Icons.end())
			{
				nana::paint::image simage(Website_Icons.find(cur_site)->second);
				sicon.load(simage);
				sicon.stretchable(0, 0, 0, 0);
			}
			else
			{
				nana::paint::image uimage("./websites_icon/user.bmp");
				sicon.load(uimage);
				sicon.stretchable(0, 0, 0, 0);
			}
			sicon.stretchable(0, 0, 0, 0);
			right_eyebrow.show();
			right_eyebrow_click = false;
		});
	site.events().mouse_leave([&]() {
		site.hide();
		right_eyebrow.show();
		right_eyebrow_click = false;
	});
	right_eyebrow.events().click([&] {
		if (right_eyebrow_click == false) {
			right_eyebrow.hide();
			site.show();
			right_eyebrow_click = true;
		}
	});
	upper_lip.events().click([&]() {
		searchbar.show();
		upper_lip.move(nana::rectangle(49, 139, 270, 12));
		lower_lip.move(nana::rectangle(49, 175, 270, 12));
	});
	lower_lip.events().click([&]() {
		searchbar.show();
		upper_lip.move(nana::rectangle(49, 139, 270, 12));
		lower_lip.move(nana::rectangle(49, 175, 270, 12));
	});
//	searchbar.events().mouse_leave([&]() {
//		searchbar.hide();
//		upper_lip.move(nana::rectangle(49, 151, 270, 12));
//		lower_lip.move(nana::rectangle(49, 163, 270, 12));
//	});
}
void kid::reset_comboxs()
{
	browser.clear();
	site.clear();
	set_comboxs();
}

void kid::reset_variables()
{
	std::vector<std::string>().swap(Browsers);
	std::map<std::string, std::string>().swap(Website_Urls);
	makeBrowsers();
	makeUrls();
}

void kid::open_search()
{
	std::string btemp = browser.text(browser.option());
	std::string utemp = (Website_Urls.find(site.text(site.option()))->second);
	std::string itemp = searchbar.text();
	std::wstring brwstemp = nana::to_wstring(btemp);
	std::wstring inputtemp = nana::to_wstring(utemp + itemp);
	LPCWSTR brws = brwstemp.c_str();
	LPCWSTR input = inputtemp.c_str();
	ShellExecute(NULL, L"open", brws, input, NULL, SW_SHOW);
}
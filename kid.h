/*****************************************************
 *	C++ code generated with Nana Creator (0.32.0)
 *	GitHub repo: https://github.com/besh81/nana-creator
 *
 * PLEASE EDIT ONLY INSIDE THE TAGS:
 *		//<*tag
 *			user code
 *		//*>
*****************************************************/
#pragma once
#ifndef KID_H
#define KID_H

#include <nana/gui.hpp>
#include <nana/gui/place.hpp>
#include <nana/gui/widgets/combox.hpp>
#include <nana/gui/widgets/picture.hpp>
#include <nana/gui/widgets/panel.hpp>
#include <nana/gui/widgets/button.hpp>
#include <nana/gui/widgets/textbox.hpp>

//<*includes
#include <string>
#include <vector>
#include <map>
#include <Windows.h>
#include <shellapi.h>
#include <iostream>
#include <fstream>
#include "add.h"
#include "del.h"
//*>

std::wstring s2ws(const std::string& s)
{
	int len;
	int slength = (int)s.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
	wchar_t* buf = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
	std::wstring r(buf);
	delete[] buf;
	return r;
}

void openSearch(const std::string& site, const std::string& brows, const std::string& word)
{
	std::string url;
	std::wstring urlTemp;
	LPCWSTR urlResult;
	std::wstring browserTemp;
	LPCWSTR browserResult;
	url = site + word;
	urlTemp = s2ws(url);
	urlResult = urlTemp.c_str();
	browserTemp = s2ws(brows);
	browserResult = browserTemp.c_str();
	ShellExecute(NULL, L"open", browserResult, urlResult, NULL, SW_SHOW);
}

class kid
	: public nana::form
{
public:
	kid(nana::window wd, const ::nana::size& sz = { 400, 200 }, const nana::appearance& apr = { true, true, false, false, false, false, false })
		: nana::form(wd, sz, apr)
	{
		init_();
		//<*ctor
		makeBrowsers();
		makeWebsites();
		int i = 0;
		for (i = 0; i < Browsers.size(); i++)
			browser.push_back(Browsers[i]);
		std::map<std::string, std::string>::iterator it;
		for (it = Websites.begin(); it != Websites.end(); it++)
			site.push_back(it->first);
		letsgo.events().click([=]
			{
				std::string input = searchbar.text();
				std::string cur_browser = browser.text(browser.option());
				std::string cur_site = (Websites.find(site.text(site.option())))->second;
				openSearch(cur_site, cur_browser, input);
			});
		goto_add.events().click([=]
			{
				add a(0);
				a.show();
				nana::exec();
			});
		goto_del.events().click([=]
			{
				del d(Browsers, Websites, 0);
				d.show();
				nana::exec();
			});
			//*>
	}

	~kid()
	{
		//<*dtor

		//*>
	}


private:
	void init_()
	{
		place_.bind(*this);
		place_.div("vert margin=[5,5,5,5] <margin=[5,5,5,5] <margin=[25,15,10,15] gap=2 left_eyebrow><margin=[5,5,5,5] gap=2 between><margin=[25,15,10,15] gap=2 right_eyebrow>><margin=[5,5,5,5] <margin=[0,15,0,15] gap=2 left_eye><margin=[25,40,0,40] gap=2 nose><margin=[0,15,0,15] gap=2 right_eye>><margin=[20,45,20,45] gap=2 arrange=[variable,30] mouse>");
		caption("Win_Search_Helper");
		bgcolor(nana::color(255,223,196));
		// browser
		browser.create(*this);
		place_["left_eyebrow"] << browser;
		browser.bgcolor(nana::color(0,0,0));
		browser.fgcolor(nana::color(0,0,0));
		browser.option(0);
		// site
		site.create(*this);
		place_["right_eyebrow"] << site;
		site.bgcolor(nana::color(0,0,0));
		site.fgcolor(nana::color(0,0,0));
		site.option(0);
		// bicon
		bicon.create(*this);
		place_["left_eye"] << bicon;
		bicon.align(static_cast<nana::align>(0), static_cast<nana::align_v>(0));
		// nose_color
		nose_color.create(*this);
		nose_color_place_.bind(nose_color);
		nose_color_place_.div("margin=[15,5,0,5] gap=2 _field_");
		nose_color.bgcolor(nana::color(205,178,69));
		place_["nose"] << nose_color;
		// goto_add
		goto_add.create(nose_color);
		nose_color_place_["_field_"] << goto_add;
		goto_add.bgcolor(nana::color(0,0,0));
		goto_add.fgcolor(nana::color(255,255,255));
		goto_add.caption("+");
		// goto_del
		goto_del.create(nose_color);
		nose_color_place_["_field_"] << goto_del;
		goto_del.bgcolor(nana::color(0,0,0));
		goto_del.fgcolor(nana::color(255,255,255));
		goto_del.caption("-");
		// sicon
		sicon.create(*this);
		place_["right_eye"] << sicon;
		sicon.align(static_cast<nana::align>(0), static_cast<nana::align_v>(0));
		// searchbar
		searchbar.create(*this);
		place_["mouse"] << searchbar;
		searchbar.bgcolor(nana::color(255,0,0));
		searchbar.typeface(nana::paint::font("", 10, {400, false, false, false}));
		searchbar.multi_lines(false);
		searchbar.focus_behavior(static_cast<nana::textbox::text_focus_behavior>(1));
		searchbar.text_align(static_cast<nana::align>(1));
		// letsgo
		letsgo.create(*this);
		place_["mouse"] << letsgo;
		letsgo.caption("go!");

		place_.collocate();
		nose_color_place_.collocate();
	}
	void load_list()
	{

	}
	void makeBrowsers(void)
	{
		std::ifstream bin("browser.txt");
		if (bin.fail())
		{
			std::cerr << "Failed to load!" << '\n';
			exit(100);
		}
		std::string bline;
		while (!bin.eof())
		{
			getline(bin, bline);
			Browsers.push_back(bline);
		}
		bin.close();
	}

	void makeWebsites(void)
	{
		std::ifstream sin("site.txt");
		if (sin.fail())
		{
			std::cerr << "Failed to load!" << '\n';
			exit(0);
		}
		std::ifstream uin("url.txt");
		if (uin.fail())
		{
			std::cerr << "Failed to load!" << '\n';
			exit(0);
		}
		std::string sline;
		std::string uline;
		while (!sin.eof() || !uin.eof())
		{
			getline(sin, sline);
			getline(uin, uline);
			Websites.insert({ sline,uline });
		}
		sin.close();
		uin.close();
	}


protected:
	nana::place place_;
	nana::combox browser;
	nana::combox site;
	nana::picture bicon;
	nana::panel<true> nose_color;
	nana::place nose_color_place_;
	nana::button goto_add;
	nana::button goto_del;
	nana::picture sicon;
	nana::textbox searchbar;
	nana::button letsgo;


	//<*declarations
	std::vector<std::string> Browsers;
	std::map<std::string, std::string> Websites;
	//*>
};

#endif //KID_H


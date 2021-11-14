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
#ifndef DEL_H
#define DEL_H

#include <nana/gui.hpp>
#include <nana/gui/place.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/widgets/combox.hpp>
#include <nana/gui/widgets/button.hpp>

//<*includes
#include "alert.h"
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <fstream>
//*>


class del
	: public nana::form
{
public:
	del(const std::vector<std::string>& v, const std::map<std::string,std::string>& m, nana::window wd, const ::nana::size& sz = {400, 200}, const nana::appearance& apr = {true, true, false, false, false, false, false})
		: nana::form(wd, sz, apr)
	{
		init_();
		//<*ctor
		Browsers = v;
		Websites = m;
		std::map<std::string, std::string>::iterator it;
		for (it = Websites.begin(); it != Websites.end(); it++)
		{
			Sites.push_back(it->first);
			Urls.push_back(it->second);
		}
		int i = 0;
		for (i = 0; i < Browsers.size(); i++)
			browser_list.push_back(Browsers[i]);
		for (i = 0; i < Sites.size(); i++)
			site_list.push_back(Sites[i]);
		browser_button.events().click([=]
			{
				std::string btemp = browser_list.text(browser_list.option());
				std::vector<std::string>::iterator it;
				for (it = Browsers.begin(); it != Browsers.end(); it++)
				{
					if (*it == btemp)
					{
						Browsers.erase(it);
						break;
					}
				}
				std::ofstream bout("browser.txt");
				for (it = Browsers.begin(); it != Browsers.end(); it++)
				{
					if (it == Browsers.end() - 1)
						bout << *it;
					else
						bout << *it << std::endl;
				}
				bout.close();
				alert a(0);
				a.show();
				nana::exec();
			});
		site_button.events().click([=]
			{
				std::string stemp = site_list.text(site_list.option());
				std::string utemp = Websites.find(site_list.text(site_list.option()))->second;
				std::vector<std::string>::iterator it;
				for (it = Sites.begin(); it != Sites.end(); it++)
				{
					if (*it == stemp)
					{
						Sites.erase(it);
						break;
					}
				}
				for (it = Urls.begin(); it != Urls.end(); it++)
				{
					if (*it == utemp)
					{
						Urls.erase(it);
						break;
					}
				}
				std::ofstream sout("site.txt");
				for (it =Sites.begin(); it != Sites.end(); it++)
				{
					if (it == Sites.end() - 1)
						sout << *it;
					else
						sout << *it << std::endl;
				}
				std::ofstream uout("url.txt");
				for (it = Urls.begin(); it != Urls.end(); it++)
				{
					if (it == Urls.end() - 1)
						uout << *it;
					else
						uout << *it << std::endl;
				}
				sout.close();
				uout.close();
				alert a(0);
				a.show();
				nana::exec();
			});
		//*>
	}

	~del()
	{
		//<*dtor

		//*>
	}


private:
	void init_()
	{
		place_.bind(*this);
		place_.div("vert margin=[5,5,5,5] <margin=[5,5,5,5] <vert margin=[5,5,5,5] gap=2 browser_field><vert margin=[5,5,5,5] gap=2 site_field>><margin=[5,5,5,5] gap=2 button_field>");
		caption("Del_Setting");
		// browser_text
		browser_text.create(*this);
		place_["browser_field"] << browser_text;
		browser_text.caption("Select the browser");
		browser_text.text_align(static_cast<nana::align>(0), static_cast<nana::align_v>(1));
		// browser_list
		browser_list.create(*this);
		place_["browser_field"] << browser_list;
		browser_list.option(0);
		// site_text
		site_text.create(*this);
		place_["site_field"] << site_text;
		site_text.caption("Select the website");
		site_text.text_align(static_cast<nana::align>(0), static_cast<nana::align_v>(1));
		// site_list
		site_list.create(*this);
		place_["site_field"] << site_list;
		site_list.option(0);
		// browser_button
		browser_button.create(*this);
		place_["button_field"] << browser_button;
		browser_button.caption("del browser");
		// site_button
		site_button.create(*this);
		place_["button_field"] << site_button;
		site_button.caption("del website");

		place_.collocate();
	}


protected:
	nana::place place_;
	nana::label browser_text;
	nana::combox browser_list;
	nana::label site_text;
	nana::combox site_list;
	nana::button browser_button;
	nana::button site_button;


	//<*declarations
	std::vector<std::string> Browsers;
	std::map<std::string, std::string> Websites;
	std::vector<std::string> Sites;
	std::vector<std::string> Urls;
	//*>
};

#endif //DEL_H


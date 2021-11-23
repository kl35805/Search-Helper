/*****************************************************
 *	C++ code generated with Nana Creator (0.32.0)
 *	GitHub repo: https://github.com/besh81/nana-creator
 *
 * PLEASE EDIT ONLY INSIDE THE TAGS:
 *		//<*tag
 *			user code
 *		//*>
*****************************************************/

#ifndef INIT_BROWSER_H
#define INIT_BROWSER_H

#include <nana/gui.hpp>
#include <nana/gui/place.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/widgets/button.hpp>
#include <nana/gui/widgets/listbox.hpp>
#include <iostream>
#include <fstream>

//<*includes

//*>


class init_browser
	: public nana::form
{
public:
	init_browser(nana::window wd, const ::nana::size& sz = {380, 180}, const nana::appearance& apr = {true, true, false, false, false, false, false})
		: nana::form(wd, sz, apr)
	{
		init_();

		//<*ctor
		listbox1.at(0).append({ "chrome" });
		listbox1.at(0).append({ "safari" });
		listbox1.at(0).append({ "firefox" });
		listbox1.at(0).append({ "whale" });
		listbox1.at(0).append({ "msedge" });
		listbox1.at(0).append({ "launcher" });
		listbox1.at(0).append({ "iexplorer" });
		fin.events().click([=]
			{
				std::string sss;
				std::ofstream bout("./txts/userbrowser.txt");
				chosen = listbox1.checked();
				nana::listbox::index_pairs::iterator it;
				for (it = chosen.begin(); it != chosen.end(); it++)
				{
					if (it == chosen.end() - 1)
					{
						sss = listbox1.at(*it).text(0);
						bout << sss;
					}
					else
					{
						sss = listbox1.at(*it).text(0);
						bout << sss << std::endl;
					}
				}
				bout.close();
				this->close();
			});
		//*>
	}

private:
	void init_()
	{
		place_.bind(*this);
		place_.div("vert margin=[5,5,5,5] <margin=[5,5,5,5] gap=2 arrange=[variable,50] notice><vert weight=130 margin=[5,5,5,5] gap=2 list>");
		caption("Form");
		// text
		text.create(*this);
		place_["notice"] << text;
		text.typeface(nana::paint::font("", 14, {400, false, false, false}));
		text.caption("Check browsers in your computer.");
		text.text_align(static_cast<nana::align>(1), static_cast<nana::align_v>(0));
		// fin
		fin.create(*this);
		place_["notice"] << fin;
		fin.caption("Ok");
		// listbox1
		listbox1.create(*this);
		place_["list"] << listbox1;
		listbox1.checkable(true);
		listbox1.append_header("Browser");

		place_.collocate();
	}


protected:
	nana::place place_;
	nana::label text;
	nana::button fin;
	nana::listbox listbox1;


	//<*declarations
	nana::listbox::index_pairs chosen;
	//*>
};

#endif //INIT_BROWSER_H


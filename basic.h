/*****************************************************
 *	C++ code generated with Nana Creator (0.32.0)
 *	GitHub repo: https://github.com/besh81/nana-creator
 *
 * PLEASE EDIT ONLY INSIDE THE TAGS:
 *		//<*tag
 *			user code
 *		//*>
*****************************************************/

#ifndef BASIC_H
#define BASIC_H

#include <nana/gui.hpp>
#include <nana/gui/place.hpp>
#include <nana/gui/widgets/button.hpp>
#include <nana/gui/widgets/combox.hpp>
#include <nana/gui/widgets/textbox.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <shellapi.h>
#include <vector>
//<*includes

//*>

class basic
	: public nana::form
{
public:
	basic(nana::window wd, const ::nana::size& sz = {400, 200}, const nana::appearance& apr = {true, true, true, false, false, false, false})
		: nana::form(wd, sz, apr)
	{
		init_();

		//<*ctor

		//*>
	}

	~basic()
	{
		//<*dtor

		//*>
	}
	
private:
	void init_()
	{
		place_.bind(*this);
		place_.div("vert margin=[5,5,5,5] <margin=[5,5,5,5] <margin=[15,10,15,10] gap=2 field6><margin=[10,50,30,50] gap=2 field7><margin=[15,15,15,15] gap=2 field9>><margin=[5,5,5,5] <margin=[0,15,0,15] gap=2 field4><margin=[15,45,15,45] gap=2 field5><margin=[0,15,0,15] gap=2 field8>><margin=[20,45,10,45] gap=2 field3>");
		caption("");
		bgcolor(nana::color(255,178,102));
		// button1
		button1.create(*this);
		place_["field6"] << button1;
		button1.bgcolor(nana::color(0,0,0));
		button1.fgcolor(nana::color(255,255,255));
		button1.caption("browser");
		// button2
		button2.create(*this);
		place_["field9"] << button2;
		button2.bgcolor(nana::color(0,0,0));
		button2.fgcolor(nana::color(255,255,255));
		button2.caption("website");
		// combox1
		combox1.create(*this);
		place_["field4"] << combox1;
		combox1.bgcolor(nana::color(153,76,0));
		combox1.push_back("a");
		combox1.push_back("b");
		combox1.option(0);
		// button3
		button3.create(*this);
		place_["field5"] << button3;
		button3.bgcolor(nana::color(255,204,153));
		button3.typeface(nana::paint::font("", 8, {400, false, false, false}));
		button3.caption("option");
		// combox2
		combox2.create(*this);
		place_["field8"] << combox2;
		combox2.bgcolor(nana::color(153,76,0));
		combox2.push_back("d");
		combox2.push_back("c");
		combox2.option(0);
		// textbox1
		textbox1.create(*this);
		place_["field3"] << textbox1;
		textbox1.bgcolor(nana::color(255,102,102));
		textbox1.typeface(nana::paint::font("", 15, {400, false, false, false}));
		textbox1.multi_lines(false);
		textbox1.focus_behavior(static_cast<nana::textbox::text_focus_behavior>(1));
		textbox1.text_align(static_cast<nana::align>(1));

		place_.collocate();
	}


protected:
	nana::place place_;
	nana::button button1;
	nana::button button2;
	nana::combox combox1;
	nana::button button3;
	nana::combox combox2;
	nana::textbox textbox1;


	//<*declarations

	//*>
};

#endif //BASIC_H


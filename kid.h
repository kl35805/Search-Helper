/*****************************************************
 *	C++ code generated with Nana Creator (0.32.0)
 *	GitHub repo: https://github.com/besh81/nana-creator
 *
 * PLEASE EDIT ONLY INSIDE THE TAGS:
 *		//<*tag
 *			user code
 *		//*>
*****************************************************/

#ifndef KID_H
#define KID_H

#include <nana/gui.hpp>
#include <nana/gui/place.hpp>
#include <nana/gui/widgets/combox.hpp>
#include <nana/gui/widgets/button.hpp>
#include <nana/gui/widgets/picture.hpp>
#include <nana/gui/widgets/panel.hpp>
#include <nana/gui/widgets/textbox.hpp>

//<*includes
#include <string>
#include <vector>
#include <map>
class add;
class del;
class alert;
//*>


class kid
	: public nana::form
{
public:
	void makeBrowsers();
	void makeUrls();
	void makeBicons();
	void makeSicons();
	void set_comboxs();
	void reg_events();
	void reset_comboxs();
	void reset_variables();
	void open_search();
	kid(nana::window wd, const ::nana::size& sz = {400, 200}, const nana::appearance& apr = {true, true, false, false, false, false, false})
		: nana::form(wd, sz, apr)
	{
		init_();

		//<*ctor
		makeBrowsers();
		makeUrls();
		makeBicons();
		makeSicons();
		set_comboxs();
		reg_events();
		//*>
	}

private:
	void init_()
	{
		place_.bind(*this);
		place_.div("vert margin=[5,5,5,5] <margin=[5,5,5,5] <margin=[25,15,10,15] gap=2 left_eyebrow><margin=[5,5,5,5] gap=2 between><margin=[25,15,10,15] gap=2 right_eyebrow>><margin=[5,5,5,5] <margin=[0,30,0,30] gap=2 left_eye><margin=[25,40,0,40] gap=2 nose><margin=[0,30,0,30] gap=2 right_eye>><margin=[20,45,20,45] gap=2 arrange=[variable,30] mouse>");
		caption("Win_Search_Helper");
		bgcolor(nana::color(255, 223, 196));
		// browser
		browser.create(*this);
		place_["left_eyebrow"] << browser;
		browser.bgcolor(nana::color(0, 0, 0));
		browser.fgcolor(nana::color(0, 0, 0));
		// left eyebrow
		left_eyebrow.create(*this, nana::rectangle(23, 35, 98, 20));
		left_eyebrow.bgcolor(nana::colors::black);
		// site
		site.create(*this);
		place_["right_eyebrow"] << site;
		site.bgcolor(nana::color(0, 0, 0));
		site.fgcolor(nana::color(0, 0, 0));
		// right eyebrow
		right_eyebrow.create(*this, nana::rectangle(23 + 255, 35, 98, 20));
		right_eyebrow.bgcolor(nana::colors::black);
		// bicon
		bicon.create(*this);
		place_["left_eye"] << bicon;
		bicon.align(static_cast<nana::align>(1), static_cast<nana::align_v>(1));
		bicon.stretchable(true);
		// nose_color
		nose_color.create(*this);
		nose_color_place_.bind(nose_color);
		nose_color_place_.div("margin=[15,5,0,5] gap=2 _field_");
		nose_color.bgcolor(nana::color(205, 178, 69));
		place_["nose"] << nose_color;
		// goto_add
		goto_add.create(nose_color);
		nose_color_place_["_field_"] << goto_add;
		goto_add.bgcolor(nana::color(0, 0, 0));
		goto_add.fgcolor(nana::color(255, 255, 255));
		goto_add.caption("+");
		// goto_del
		goto_del.create(nose_color);
		nose_color_place_["_field_"] << goto_del;
		goto_del.bgcolor(nana::color(0, 0, 0));
		goto_del.fgcolor(nana::color(255, 255, 255));
		goto_del.caption("-");
		// sicon
		sicon.create(*this);
		place_["right_eye"] << sicon;
		sicon.align(static_cast<nana::align>(1), static_cast<nana::align_v>(1));
		sicon.stretchable(true);
		// searchbar
		searchbar.create(*this);
		place_["mouse"] << searchbar;
		searchbar.bgcolor(nana::color(255, 0, 0));
		searchbar.typeface(nana::paint::font("", 10, { 400, false, false, false }));
		searchbar.multi_lines(false);
		// mouse
		upper_lip.create(*this, nana::rectangle(49, 151, 270, 12));
		upper_lip.bgcolor(nana::color(250, 100, 100));
		lower_lip.create(*this, nana::rectangle(49, 163, 270, 12));
		lower_lip.bgcolor(nana::color(250, 100, 100));
		// letsgo
		letsgo.create(*this);
		place_["mouse"] << letsgo;
		letsgo.caption("go!");

		place_.collocate();
		nose_color_place_.collocate();
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

	// eyebrow
	nana::picture left_eyebrow;
	nana::picture right_eyebrow;
	bool left_eyebrow_click = false;
	bool right_eyebrow_click = false;

	// mouse
	nana::picture upper_lip;
	nana::picture lower_lip;
	bool mouse_click = false;

	std::vector<std::string> Browsers;
	std::map<std::string, std::string> Browser_Icons;
	std::map<std::string, std::string> Website_Urls;
	std::map<std::string, std::string> Website_Icons;
};

#endif //KID_H



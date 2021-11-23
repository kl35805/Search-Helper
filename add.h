/*****************************************************
 *	C++ code generated with Nana Creator (0.32.0)
 *	GitHub repo: https://github.com/besh81/nana-creator
 *
 * PLEASE EDIT ONLY INSIDE THE TAGS:
 *		//<*tag
 *			user code
 *		//*>
*****************************************************/

#ifndef ADD_H
#define ADD_H

#include <nana/gui.hpp>
#include <nana/gui/place.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/widgets/textbox.hpp>
#include <nana/gui/widgets/button.hpp>

//<*includes
class kid;
class add;
class alert;
//*>


class add
	: public nana::form
{
public:
	add(kid* kk, nana::window wd, const ::nana::size& sz = { 380, 180 }, const nana::appearance& apr = { true, true, false, false, false, false, false });

private:
	void init_()
	{
		place_.bind(*this);
		place_.div("margin=[5,5,5,5] <vert margin=[5,5,5,5] <vert weight=135 margin=[5,5,5,5] gap=2 browser_typing><vert margin=[5,5,5,5] gap=2 browser_adding>><vert margin=[5,5,5,5] <vert weight=135 margin=[5,5,5,5] <vert margin=[5,5,5,5] gap=2 arrange=[15,variable] site_typing><vert margin=[5,5,5,5] gap=2 arrange=[15,variable] url_typing>><margin=[5,5,5,5] gap=2 site_adding>>");
		caption("Add");
		// browser_text
		browser_text.create(*this);
		place_["browser_typing"] << browser_text;
		browser_text.caption("Type the original file name of browser exactly");
		browser_text.text_align(static_cast<nana::align>(1), static_cast<nana::align_v>(1));
		// browser_box
		browser_box.create(*this);
		place_["browser_typing"] << browser_box;
		// browser_button
		browser_button.create(*this);
		place_["browser_adding"] << browser_button;
		browser_button.caption("add browser");
		// site_text
		site_text.create(*this);
		place_["site_typing"] << site_text;
		site_text.typeface(nana::paint::font("", 8, {350, false, false, false}));
		site_text.caption("Type the name of website");
		site_text.text_align(static_cast<nana::align>(1), static_cast<nana::align_v>(0));
		// site_box
		site_box.create(*this);
		place_["site_typing"] << site_box;
		site_box.typeface(nana::paint::font("", 8, {400, false, false, false}));
		// url_text
		url_text.create(*this);
		place_["url_typing"] << url_text;
		url_text.typeface(nana::paint::font("", 8, {400, false, false, false}));
		url_text.caption("Type the website's search URL");
		url_text.text_align(static_cast<nana::align>(1), static_cast<nana::align_v>(0));
		// url_box
		url_box.create(*this);
		place_["url_typing"] << url_box;
		url_box.typeface(nana::paint::font("", 8, {400, false, false, false}));
		// site_button
		site_button.create(*this);
		place_["site_adding"] << site_button;
		site_button.caption("add website");

		place_.collocate();
	}


protected:
	nana::place place_;
	nana::label browser_text;
	nana::textbox browser_box;
	nana::button browser_button;
	nana::label site_text;
	nana::textbox site_box;
	nana::label url_text;
	nana::textbox url_box;
	nana::button site_button;


	//<*declarations
	kid* k;
	//*>
};

#endif //ADD_H


/*****************************************************
 *	C++ code generated with Nana Creator (0.32.0)
 *	GitHub repo: https://github.com/besh81/nana-creator
 *
 * PLEASE EDIT ONLY INSIDE THE TAGS:
 *		//<*tag
 *			user code
 *		//*>
*****************************************************/

#ifndef DEL_H
#define DEL_H

#include <nana/gui.hpp>
#include <nana/gui/place.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/widgets/combox.hpp>
#include <nana/gui/widgets/button.hpp>

//<*includes
class kid;
class add;
class alert;
#include <string>
#include <vector>
#include <map>
//*>


class del
	: public nana::form
{
public:
	del(nana::window wd, const ::nana::size& sz = { 380, 180 }, const nana::appearance& apr = { true, true, false, false, false, false, false });
	void set_ptr(kid* kk, add* aa, alert* ale);
	void set_variables(const std::vector<std::string>& vv, const std::map<std::string, std::string>& m1);
	void load_list();

private:
	void init_()
	{
		place_.bind(*this);
		place_.div("vert margin=[5,5,5,5] <margin=[5,5,5,5] <vert margin=[5,5,5,5] gap=2 browser_field><vert margin=[5,5,5,5] gap=2 site_field>><margin=[5,5,5,5] gap=2 button_field>");
		caption("Del");
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
	kid* k;
	add* a;
	alert* al;
	std::vector<std::string> Browsers;
	std::map<std::string, std::string> Website_Urls;
	//*>
};

#endif //DEL_H


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
//*>

class add;
class del;

class kid
	: public nana::form
{
public:
	void variables_clear();
	void comboxs_clear();
	void load_list(void);
	void makeBrowsers(void);
	void makeWebsites(void);
	kid(nana::window wd, const ::nana::size& sz = { 400, 200 }, const nana::appearance& apr = { true, true, false, false, false, false, false });
	~kid();

private:
	void init_();
	
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


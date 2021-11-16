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
#include <string>
#include <vector>
#include <map>
//*>

class kid;

class del
	: public nana::form
{
public:
	void del_clear();
	del(kid* kk, const std::vector<std::string>& v, const std::map<std::string, std::string>& m, nana::window wd, const ::nana::size& sz = { 380, 180 }, const nana::appearance& apr = { true, true, false, false, false, false, false });
	~del();

private:
	void init_();

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
	kid* k;
	//*>
};

#endif //DEL_H


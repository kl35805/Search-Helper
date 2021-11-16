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
#ifndef ADD_H
#define ADD_H

#include <nana/gui.hpp>
#include <nana/gui/place.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/widgets/textbox.hpp>
#include <nana/gui/widgets/button.hpp>

//<*includes
// 
//*>

class kid;

class add
	: public nana::form
{
public:
	add(kid* kk, nana::window wd, const ::nana::size& sz = { 380, 180 }, const nana::appearance& apr = { true, true, false, false, false, false, false });
	~add();

private:
	void init_();

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


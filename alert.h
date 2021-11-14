/*****************************************************
 *	C++ code generated with Nana Creator (0.32.0)
 *	GitHub repo: https://github.com/besh81/nana-creator
 *
 * PLEASE EDIT ONLY INSIDE THE TAGS:
 *		//<*tag
 *			user code
 *		//*>
*****************************************************/

#ifndef ALERT_H
#define ALERT_H

#include <nana/gui.hpp>
#include <nana/gui/place.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/widgets/button.hpp>

//<*includes

//*>


class alert
	: public nana::form
{
public:
	alert(nana::window wd, const ::nana::size& sz = {400, 200}, const nana::appearance& apr = {true, true, false, false, false, false, false})
		: nana::form(wd, sz, apr)
	{
		init_();

		//<*ctor
		button1.events().click(nana::API::exit);
		//*>
	}

	~alert()
	{
		//<*dtor

		//*>
	}


private:
	void init_()
	{
		place_.bind(*this);
		place_.div("vert margin=[5,5,5,5] gap=2 _field_");
		caption("Alert");
		// label1
		label1.create(*this);
		place_["_field_"] << label1;
		label1.typeface(nana::paint::font("", 16, {400, false, false, false}));
		label1.caption("You need to restart program.");
		label1.text_align(static_cast<nana::align>(1), static_cast<nana::align_v>(1));
		// button1
		button1.create(*this);
		place_["_field_"] << button1;
		button1.typeface(nana::paint::font("", 16, {400, false, false, false}));
		button1.caption("restrart");

		place_.collocate();
	}


protected:
	nana::place place_;
	nana::label label1;
	nana::button button1;


	//<*declarations

	//*>
};

#endif //ALERT_H


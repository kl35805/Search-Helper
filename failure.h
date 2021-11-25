/*****************************************************
 *	C++ code generated with Nana Creator (0.32.0)
 *	GitHub repo: https://github.com/besh81/nana-creator
 *
 * PLEASE EDIT ONLY INSIDE THE TAGS:
 *		//<*tag
 *			user code
 *		//*>
*****************************************************/

#ifndef FAILURE_H
#define FAILURE_H

#include <nana/gui.hpp>
#include <nana/gui/place.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/widgets/button.hpp>

//<*includes
class kid;
class add;
class del;
//*>


class failure
	: public nana::form
{
public:
	failure(add* aa, del* dd, nana::window wd, const ::nana::size& sz = { 200, 100 }, const nana::appearance& apr = { true, true, false, false, false, false, false });
private:
	void init_()
	{
		place_.bind(*this);
		place_.div("vert margin=[5,5,5,5] gap=2 _field_");
		caption("Failure");
		// label1
		label1.create(*this);
		place_["_field_"] << label1;
		label1.typeface(nana::paint::font("", 16, {400, false, false, false}));
		label1.caption("Failed!");
		label1.text_align(static_cast<nana::align>(1), static_cast<nana::align_v>(1));
		// button1
		button1.create(*this);
		place_["_field_"] << button1;
		button1.typeface(nana::paint::font("", 12, {400, false, false, false}));
		button1.caption("close");

		place_.collocate();
	}


protected:
	nana::place place_;
	nana::label label1;
	nana::button button1;


	//<*declarations
	add* a;
	del* d;
	//*>
};

#endif //FAILURE_H


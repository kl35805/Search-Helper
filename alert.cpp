#include <nana/gui.hpp>
#include <nana/gui/place.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/widgets/button.hpp>
#include "kid.h"
#include "alert.h"

void alert::reload()
{
	button1.events().click([=]
		{
			k->variables_clear();
			k->comboxs_clear();
			k->makeBrowsers();
			k->makeWebsites();
			k->load_list();
			this->close();
			f->close();
		});
}

void alert::init_()
{
	place_.bind(*this);
	place_.div("vert margin=[5,5,5,5] gap=2 _field_");
	caption("Alert");
	// label1
	label1.create(*this);
	place_["_field_"] << label1;
	label1.typeface(nana::paint::font("", 12, { 400, false, false, false }));
	label1.caption("Succeed!");
	label1.text_align(static_cast<nana::align>(1), static_cast<nana::align_v>(1));
	// button1
	button1.create(*this);
	place_["_field_"] << button1;
	button1.typeface(nana::paint::font("", 9, { 400, false, false, false }));
	button1.caption("ok");

	place_.collocate();
}

alert::alert(kid* kk, form* ff, nana::window wd, const ::nana::size& sz, const nana::appearance& apr) : nana::form(wd, sz, apr)
{
	init_();

	//<*ctor
	k = kk;
	f = ff;
	reload();
	//*>
}

alert::~alert()
{
	delete this;
}
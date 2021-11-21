#include "kid.h"
#include "add.h"
#include "del.h"
#include "alert.h"

void alert::set_ptr(kid* kk, add* aa, del* dd)
{
	k = kk;
	a = aa;
	d = dd;
}

alert::alert(nana::window wd, const ::nana::size& sz, const nana::appearance& apr): nana::form(wd, sz, apr)
{
	init_();

	//<*ctor
	button1.events().click([=]
		{
			k->reset_variables();
			k->reset_comboxs();
			if (d->visible())
			{
				this->close();
				d->close();
			}
			else if (a->visible())
			{
				this->close();
				a->close();
			}
		});
	//*>
}
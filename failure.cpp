#include "kid.h"
#include "add.h"
#include "del.h"
#include "alert.h"
#include "failure.h"

failure::failure(add* aa, del* dd, nana::window wd, const ::nana::size& sz, const nana::appearance& apr) : nana::form(wd, sz, apr)
{
	a = aa;
	d = dd;
	init_();

	//<*ctor
	button1.events().click([=]
		{
			if (a == NULL)
			{
				d->close();
				this->close();
			}
			else if (d == NULL)
			{
				a->close();
				this->close();
			}
		});
	//*>
}
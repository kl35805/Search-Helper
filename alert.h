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
#include <cstdlib>

//<*includes
//*>

class alert
	: public nana::form
{
public:
	void reload();
	alert(kid* kk, nana::form* ff, nana::window wd, const ::nana::size& sz = { 200, 100 }, const nana::appearance& apr = { true, true, false, false, false, false, false });
	~alert();

private:
	void init_();

protected:
	nana::place place_;
	nana::label label1;
	nana::button button1;


	//<*declarations
	kid* k;
	form* f;
	//*>
};

#endif //ALERT_H


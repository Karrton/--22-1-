#include <iostream>
#include "Header1.h"

int main()
{
	student p;
	p.set_age(18);
	p.set_mark(3);
	p.set_name("Oleg");
	p.set_object("Physics");
	p.chek_mark();
	std::cout << p << std::endl;
	student p2 = p;
	p2.set_name("Van");
	p2.set_mark(2);
	std::cout << p2 << std::endl;
	p2.chek_mark();
}

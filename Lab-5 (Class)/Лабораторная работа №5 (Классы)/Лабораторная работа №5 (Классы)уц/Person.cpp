#include"Person.h"
person& person::operator=(const person& t)
{
	if (&t == this)
		return *this;
	age = t.age;
	name = t.name;
	return *this;
}
void person::show()
{
	std::cout << name << std::endl;
	std::cout << age << std::endl;
}
person::~person(void) {};
std::istream& operator>>(std::istream& in, person& t)
{
	std::cout << "Name - "; in >> t.name; std::cout << "Age - "; in >> t.age; return in;
}
std::ostream& operator<<(std::ostream& out, const person& t)
{
	return (out << t.age << " : " << t.name);
}

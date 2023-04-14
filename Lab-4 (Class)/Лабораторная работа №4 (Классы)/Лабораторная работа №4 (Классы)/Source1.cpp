#include"Header.h"
person& person::operator=(const person& t)
{
	if (&t == this)
		return *this;
	age = t.age;
	name = t.name;
	return *this;
}
std::istream& operator>>(std::istream& in, person& t)
{
	std::cout << "Age - "; in >> t.age; std::cout << "Name - "; in >> t.name; return in;
}
std::ostream& operator<<(std::ostream& out, const person& t)
{
	return (out << t.age << " : " << t.name);
}

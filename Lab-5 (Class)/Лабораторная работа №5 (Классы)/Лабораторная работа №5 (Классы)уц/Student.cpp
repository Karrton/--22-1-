#include"Student.h"
#include<string>
#include<iostream>
student& student::operator=(const student& t)
{
	if (&t == this)
		return *this;
	object = t.object;
	mark = t.mark;
	return *this;
}
void student::show()
{
	std::cout << name << std::endl;
	std::cout << age << std::endl;
	std::cout << object << std::endl;
	// std::cout << mark << std::endl;
}
std::istream& operator>>(std::istream& in, student& t)
{
	std::cout << "Name - "; in >> t.name;
	std::cout << "Age - "; in >> t.age;
	std::cout << "Object - "; in >> t.object;
	return in;
}
std::ostream& operator<<(std::ostream& out, const student& t)
{
	return (out << t.age << " : " << t.name << " : " << t.object);
}

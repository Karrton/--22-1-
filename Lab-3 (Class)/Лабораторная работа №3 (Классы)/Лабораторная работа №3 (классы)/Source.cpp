#include"Header.h"
pair& pair::operator=(const pair& t)
{
	if (&t == this)
		return *this;
	first = t.first;
	second = t.second;
	return *this;
}
pair pair::operator+(const pair& t)
{
	pair p;
	p.first = first + t.first;
	p.second = second + t.second;
	return p;
}
pair pair::operator-(const pair& t)
{
	pair p;
	p.first = first - t.first;
	p.second = second - t.second;
	return p;
}
pair pair::operator-(const int d)
{
	pair p;
	p.first = first - d;
	return p;
}
pair pair::operator-(const double d)
{
	pair p;
	p.first = first - d;
	return p;
}
std::istream& operator>>(std::istream& in, pair& t)
{
	std::cout << "First - "; in >> t.first; std::cout << "Second - "; in >> t.second; return in;
}
std::ostream& operator<<(std::ostream& out, const pair& t)
{
	return (out << t.first << " : " << t.second);
}

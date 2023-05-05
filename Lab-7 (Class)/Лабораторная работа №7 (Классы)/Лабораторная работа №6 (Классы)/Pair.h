#pragma once
#include<iostream>
class pair
{
	friend std::istream& operator>>(std::istream& in, pair& t);
	friend std::ostream& operator<<(std::ostream& out, const pair& t);
	int first;
	double second;
public:
	pair() { first = 0; second = 0; };
	pair(int m, double s) { first = m; second = s; };
	pair(const pair& t) { first = t.first; second = t.second; };
	~pair() {};
	int get_first() { return first; };
	int get_second() { return second; };
	void set_first(int m) { first = m; };
	void set_second(int s) { second = s; };
	pair operator*(const pair& t)
	{
		pair a;
		a.first = first * t.first;
		a.second = second * t.second;
		return a;
	}
	pair& operator=(const pair& t)
	{
		if (&t == this)
			return *this;
		first = t.first;
		second = t.second;
		return *this;
	}
	pair operator+(const pair& t)
	{
		pair p;
		p.first = first + t.first;
		p.second = second + t.second;
		return p;
	}
	pair operator-(const pair& t)
	{
		pair p;
		p.first = first - t.first;
		p.second = second - t.second;
		return p;
	}
	pair operator-(const int d)
	{
		pair p;
		p.first = first - d;
		return p;
	}
	pair operator-(const double d)
	{
		pair p;
		p.first = first - d;
		return p;
	}
};
std::istream& operator>>(std::istream& in, pair& t)
{
	std::cout << "First - "; in >> t.first; std::cout << "Second - "; in >> t.second; return in;
}
std::ostream& operator<<(std::ostream& out, const pair& t)
{
	return (out << t.first << " : " << t.second);
}


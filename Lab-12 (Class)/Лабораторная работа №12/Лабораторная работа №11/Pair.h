#pragma once
#include<iostream>
class Pair
{
	friend std::istream& operator>>(std::istream& in, Pair& t);
	friend std::ostream& operator<<(std::ostream& out, const Pair& t);
	int first;
	double second;
public:
	Pair() { first = 0; second = 0; };
	Pair(int m, double s) { first = m; second = s; };
	Pair(const Pair& t) { first = t.first; second = t.second; };
	~Pair() {};
	int get_first() { return first; };
	double get_second() { return second; };
	void set_first(int m) { first = m; };
	void set_second(int s) { second = s; };
	Pair operator*(const Pair& t)
	{
		Pair a;
		a.first = first * t.first;
		a.second = second * t.second;
		return a;
	}
	Pair operator*() { return *this; }
	Pair operator/(const Pair& t)
	{
		Pair a;
		a.first = first / t.first;
		a.second = second / t.second;
		return a;
	}
	Pair& operator=(int t)
	{
		first = t;
		second = t;
		return *this;
	}
	Pair& operator=(const Pair& t)
	{
		if (&t == this)
			return *this;
		first = t.first;
		second = t.second;
		return *this;
	}
	bool operator==(const Pair& t) const
	{
		if (second == t.second && first == t.first)
			return true;
		else
			return false;
	}
	Pair operator+(const Pair& t) const
	{
		Pair p;
		p.first = first + t.first;
		p.second = second + t.second;
		return p;
	}
	Pair operator-(const Pair& t)
	{
		Pair p;
		p.first = first - t.first;
		p.second = second - t.second;
		return p;
	}
	Pair operator-(const int d)
	{
		Pair p;
		p.first = first - d;
		return p;
	}
	Pair operator-(const double d)
	{
		Pair p;
		p.second = second - d;
		return p;
	}
	Pair operator/(int a)
	{
		Pair p;
		p.first = first / a;
		p.second = second / a;
		return p;
	}
	bool operator<(const Pair& t) const
	{
		Pair p;
		double a = first + second;
		double a1 = t.first + t.second;
		if (a < a1)
			return true;
		else
			return false;
	}
	bool operator>(const Pair& t) const
	{
		Pair p;
		double a = first + second;
		double a1 = t.first + t.second;
		if (a > a1)
			return true;
		else
			return false;
	}
};
std::istream& operator>>(std::istream& in, Pair& t)
{
	std::cout << "First - "; in >> t.first; std::cout << "Second - "; in >> t.second; return in;
}
std::ostream& operator<<(std::ostream& out, const Pair& t)
{
	return (out << t.first << " : " << t.second);
}
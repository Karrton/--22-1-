#pragma once
#include <fstream>
#include <random>
using namespace std;

class Pair 
{
	int first;
	double second;
	friend istream& operator>>(istream& in, Pair& p);
	friend ostream& operator<<(ostream& out, const Pair& p);
	friend fstream& operator>>(fstream& fin, Pair& p);
	friend fstream& operator<<(fstream& fout, const Pair& p);
	double generate_random()
	{
		random_device rd;
		mt19937 gen(rd());
		uniform_real_distribution<double> dis(0.0, 1.0);
		return round(dis(gen) * 10000) / 10000;
	}
public:
	Pair() { first = 0;	second = 0; };
	Pair(int F, double S) { first = F; second = S; };
	Pair(const Pair& t) { first = t.first; second = t.second; };
	~Pair() {};
	int get_first() { return first; }
	double get_second() { return second; }
	void set_first(int F) { first = F; }
	void set_second(double S) { second = S; }
	double sum() { double s = second + first; return s; }
	Pair& operator+(const int X)
	{
		first += X;
		return *this;
	}

	Pair& operator+(const double X)
	{
		second += X;
		return *this;
	}

	Pair& operator/(const int X)
	{
		first = first / X;
		second = second / X;
		return *this;
	}

	Pair& operator-(const Pair& p)
	{
		this->first -= p.first;
		this->second -= p.second;
		return *this;
	}

	Pair& operator+(const Pair& p)
	{
		this->first += p.first;
		this->second += p.second;
		return *this;
	}

	Pair& operator+=(const Pair& p)
	{
		this->first += p.first;
		this->second += p.second;
		return *this;
	}

	Pair operator=(const Pair& p)
	{
		if (&p == this) return *this;
		first = p.first;
		second = p.second;
		return*this;
	}

	bool operator<(const Pair& p) const
	{
		double sthis = this->first + this->second;
		double sother = p.first + p.second;
		if (sthis < sother) return true;
		return false;
	}

	bool operator>(const Pair& p) const
	{
		double sthis = this->first + this->second;
		double sother = p.first + p.second;
		if (sthis > sother) return true;
		return false;
	}

	bool operator<=(const Pair& p) const
	{
		double sthis = this->first + this->second;
		double sother = p.first + p.second;
		if (sthis <= sother) return true;
		return false;
	}

	bool operator>=(const Pair& p) const
	{
		double sthis = this->first + this->second;
		double sother = p.first + p.second;
		if (sthis >= sother) return true;
		return false;
	}

	bool operator==(const Pair& p) const
	{
		double sthis = this->first + this->second;
		double sother = p.first + p.second;
		if (sthis == sother) return true;
		return false;
	}

	void set_random()
	{
		first = rand() % 10;
		second = generate_random();
	}
};

istream& operator>>(istream& in, Pair& t)
{
	cout << "First = "; in >> t.first;
	cout << "Second = "; in >> t.second;
	return in;
}

ostream& operator<<(ostream& out, const Pair& t) 
{
	return (out << t.first << " : " << t.second << endl);
}

fstream& operator>>(fstream& fin, Pair& p)
{
	fin >> p.first;
	fin >> p.second;
	return fin;
}

fstream& operator<<(fstream& fout, const Pair& p)
{
	fout << p.first << "\n" << p.second << "\n";
	return fout;
}
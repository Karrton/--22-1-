#pragma once
#include <set> 
#include <ctime> 

using namespace std;

double generate_random();

void add(int size, multiset<double>& a)
{
	double c = 0;
	for (unsigned i = 0; i < size; i++)
	{
		double b = generate_random();
		a.insert(b);
		c += b;
	}
	c /= size;
	a.insert(c);
}
void show(multiset<double> a)
{
	for (auto i = a.begin(); i != a.end(); i++)
		cout << *i << " ";
	cout << endl;
}
void dell(multiset<double>& a)
{
	double b, c;
	cin >> b >> c;
	if (c < b) swap(c, b);
	for (auto i = a.begin(); i != a.end();)
	{
		if (*i < c && *i > b)
			i = a.erase(i);
		else
			++i;
	}
}
void peak(multiset<double>& a)
{
	auto i = a.begin();
	double min = *i;
	double max = *i;
	for (; i != a.end(); i++)
	{
		if (*i > max)
			max = *i;
		if (*i < min)
			min = *i;
	}
	min += max;
	i = a.begin();
	int k = 0;
	for (; k < a.size();)
	{
		auto buff = i;
		max = *i + min; 
		++i;
		a.erase(buff);
		a.insert(max);
		++k;
	}
}
void ex_1()
{
	multiset<double> a;
	int size = 5;
	add(size, a);
	show(a);
	dell(a);
	show(a);
	peak(a);
	show(a);
}
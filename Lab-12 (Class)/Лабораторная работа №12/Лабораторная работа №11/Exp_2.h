#pragma once
#include"Pair.h"

using namespace std;
double generate_random();
void add_1(int size, multiset<Pair>& a)
{
	Pair c;
	for (unsigned i = 0; i < size; i++)
	{
		Pair b(rand() % 5, generate_random());
		a.insert(b);
		c = c + b;
	}
	c = c / size;
	a.insert(c);
}
void show_1(multiset<Pair> a)
{
	for (auto i = a.begin(); i != a.end(); i++)
		cout << *i << " ";
	cout << endl;
}
void dell_1(multiset<Pair>& a)
{
	Pair b, c;
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
void peak_1(multiset<Pair>& a)
{
	auto i = a.begin();
	Pair min = *i;
	Pair max = *i;
	for (; i != a.end(); i++)
	{
		if (*i > max)
			max = *i;
		if (*i < min)
			min = *i;
	}
	min = min + max;
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
void ex_2()
{
	multiset<Pair> a;
	int size = 5;
	add_1(size, a);
	show_1(a);
	dell_1(a);
	show_1(a);
	peak_1(a);
	show_1(a);
}
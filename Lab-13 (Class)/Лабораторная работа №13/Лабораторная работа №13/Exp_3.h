#pragma once
#include <map>

void add_3(int size, map<double, Pair>& m)
{
	Pair b;
	for (int i = 0; i < size; ++i) {
		Pair p;
		p.set_random();
		m.insert(make_pair(p.sum(), p));
		b = b + p;
	}
	b = b / size;
	m.insert(make_pair(b.sum(), b));
}
void find_3(map<double, Pair>& m)
{
	Pair a;
	cin >> a;
	const auto it = find_if(m.begin(), m.end(), [&a](decltype(*m.begin())& it)->bool { return it.second == a;});
	if (it == m.end())
	{
		cout << "Element not found!" << endl;
		return;
	}
	for (map<double, Pair>::iterator i = m.begin(); i != m.end(); ++i) 
		if (i == it)
			cout << "Element found! - " << i->second;
}
void dell_3(map<double, Pair>& m)
{
	Pair a, b;
	cin >> a >> b;
	if (a > b) swap(a, b);
	auto it = std::find_if(m.begin(), m.end(), [&a, &b](const auto& elem) { return elem.second >= a && elem.second <= b; });
	while (it != m.end()) 
	{
		m.erase(it++);
		it = find_if(it, m.end(), [&a, &b](const auto& elem) { return elem.second >= a && elem.second <= b; });
	}
}
void peak_3(map<double, Pair>& m)
{
	const auto min = m.begin();
	const auto max = --m.end();
	Pair sum;
	sum = min->second + max->second;
	for (auto it = m.begin(); it != m.end(); it++)
	{
		it->second.set_second(it->second.get_second() + sum.get_second());
		it->second.set_first(it->second.get_first() + sum.get_first());
	}
}
void sort_3(map<double, Pair>& m)
{
	list<Pair> temp;
	for (const auto& elem : m)
		temp.push_back(elem.second);
	cout << "Sort 1:" << endl;
	temp.sort(mem_fun_ref(&Pair::operator<));
	for_each(temp.begin(), temp.end(), [](Pair& p) {cout << p; });
	temp.sort(mem_fun_ref(&Pair::operator>));
	cout << "Sort 2:" << endl;
	for_each(temp.begin(), temp.end(), [](Pair& p) {cout << p; });
}
void show_3(const map<double, Pair>& m) 
{
	for (const auto& elem : m)
		std::cout << "Key: " << elem.first << ", Value: " << elem.second;
}
void ex_3()
{
	map<double, Pair> m;
	int size3 = 5;
	add_3(size3, m);
	show_3(m);
	find_3(m);
	peak_3(m);
	show_3(m);
	dell_3(m);
	show_3(m);
	sort_3(m);
}
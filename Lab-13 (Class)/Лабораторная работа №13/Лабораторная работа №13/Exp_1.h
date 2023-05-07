#pragma once
#include<list>
#include"Pair.h"
using namespace std;
bool check(const Pair& a, const Pair& b)
{
	if (a == b) return true;
	else return false;
}
void add(int size, list<Pair>& lst)
{
	for (int i = 0; i < size; i++)
	{
		Pair a;
		a.set_random();
		lst.push_back(a);
	}
	Pair sum;
	for_each(lst.begin(), lst.end(), [&sum](Pair& p) {sum += p; });
	sum.set_first(sum.get_first() / lst.size());
	sum.set_second(sum.get_second() / lst.size());
	lst.push_back(sum);
}
void find(list<Pair>& lst)
{
	Pair val;
	cin >> val;
	auto it = find_if(lst.begin(), lst.end(), bind(check, placeholders::_1, val));
	if (it == lst.end()) 
	{
		cout << "Element not found!" << endl;
		return;
	}
	for (auto i = lst.begin(); i != lst.end(); ++i)
		if (i == it)
			cout << "Element found! - " << *i;
}
void peak(list<Pair>& lst)
{
	auto mini = min_element(lst.begin(), lst.end());
	auto maxi = max_element(lst.begin(), lst.end());
	Pair sum;
	sum = *mini + *maxi;
	for_each(lst.begin(), lst.end(), [&sum](Pair& p) {p += sum; });
}
void dell(list<Pair>& lst)
{
	Pair a, b;
	cin >> a >> b;
	if (a > b) swap(a, b);
	auto s = remove_if(lst.begin(), lst.end(), [a, b](Pair& p) {return p >= a && p <= b; });
	lst.erase(s, lst.end());
}
void show(list<Pair>& lst)
{
	for_each(lst.begin(), lst.end(), [](Pair& p) {cout << p; });
}
void sort(list<Pair>& lst)
{
	cout << "Sort 1:" << endl;
	lst.sort(mem_fun_ref(&Pair::operator<));
	for_each(lst.begin(), lst.end(), [](Pair& p) {cout << p; });
	lst.sort(mem_fun_ref(&Pair::operator>));
	cout << "Sort 2:" << endl;
	for_each(lst.begin(), lst.end(), [](Pair& p) {cout << p; });
}
void ex_1()
{
	int size = 5;
	list<Pair> lst;
	add(size, lst);
	show(lst);
	find(lst);
	peak(lst);
	show(lst);
	dell(lst);
	show(lst);
	sort(lst);
}

#pragma once
#include <vector>
#include <queue>

void add_1(int size, priority_queue<Pair>& q)
{
	Pair b;
	for (int i = 0; i < size; i++)
	{
		Pair a;
		a.set_random();
		q.push(a);
		b = b + a;
	}
	b = b / size;
	q.push(b);
}
void find_1(priority_queue<Pair>& q)
{
	Pair val;
	cin >> val;
	vector<Pair> temp;
	int g = q.size();
	for (int i = 0; i < g; i++)
	{
		temp.push_back(q.top());
		q.pop();
	}
	for (auto i = temp.begin(); i != temp.end(); i++)
		q.push(*i);
	auto it = find_if(temp.begin(), temp.end(), bind(check, placeholders::_1, val));
	if (it == temp.end())
	{
		cout << "Element not found!" << endl;
		return;
	}
	for (auto i = temp.begin(); i != temp.end(); ++i)
		if (i == it)
			cout << "Element found! - " << *i;
}
void peak_1(priority_queue<Pair>& q)
{
	Pair sum;
	vector<Pair> temp;
	int g = q.size();
	for (int i = 0; i < g; i++)
	{
		temp.push_back(q.top());
		q.pop();
	}
	sum = temp[0] + temp[temp.size() - 1];
	for_each(temp.begin(), temp.end(), [&sum](Pair& p) {p += sum; });
	for (auto i = temp.begin(); i != temp.end(); i++)
		q.push(*i);
}
void dell_1(priority_queue<Pair>& q)
{
	Pair a, b;
	cin >> a >> b;
	if (a > b) swap(a, b);
	vector<Pair> temp;
	for (int i = 0; i < q.size(); i++)
	{
		temp.push_back(q.top());
		q.pop();
	}
	auto s = remove_if(temp.begin(), temp.end(), [a, b](Pair& p) {return p >= a && p <= b; });
	temp.erase(s, temp.end());
	for (auto i = temp.begin(); i != temp.end(); i++)
		q.push(*i);
}
void show_1(priority_queue<Pair>& q)
{
	vector<Pair> temp;
	int b = q.size();
	for (int i = 0; i < b; i++)
	{
		temp.push_back(q.top());
		q.pop();
	}
	for_each(temp.begin(), temp.end(), [](Pair& p) {cout << p; });
	for (auto i = temp.begin(); i != temp.end(); i++)
		q.push(*i);
}
void sort_1(priority_queue<Pair>& q)
{
	list<Pair> temp;
	int g = q.size();
	for (int i = 0; i < g; i++)
	{
		temp.push_back(q.top());
		q.pop();
	}
	cout << "Sort 1:" << endl;
	temp.sort(mem_fun_ref(&Pair::operator<));
	for_each(temp.begin(), temp.end(), [](Pair& p) {cout << p; });
	temp.sort(mem_fun_ref(&Pair::operator>));
	cout << "Sort 2:" << endl;
	for_each(temp.begin(), temp.end(), [](Pair& p) {cout << p; });
	for (auto i = temp.begin(); i != temp.end(); i++)
		q.push(*i);
}
void ex_2()
{
	int size1 = 5;
	priority_queue<Pair> q;
	add_1(size1, q);
	show_1(q);
	find_1(q);
	peak_1(q);
	show_1(q);
	dell_1(q);
	show_1(q);
	sort_1(q);
}
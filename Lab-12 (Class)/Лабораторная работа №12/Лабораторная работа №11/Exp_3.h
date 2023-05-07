#pragma once
#include <list>
template <class T>
class List
{
	multiset<Pair> m;
public:
	List() {};
	~List() {};
	List(int size)
	{
		Pair c;
		for (unsigned i = 0; i < size; i++)
		{
			Pair b(rand() % 5, generate_random());
			m.insert(b);
			c = c + b;
		}
		c = c / size;
		m.insert(c);
	}
	void show_3()
	{
		for (auto i = m.begin(); i != m.end(); i++)
			cout << *i << " ";
		cout << endl;
	}
	void dell_3()
	{
		Pair b, c;
		cin >> b >> c;
		if (c < b) swap(c, b);
		for (auto i = m.begin(); i != m.end();)
		{
			if (*i < c && *i > b)
				i = m.erase(i);
			else
				++i;
		}
	}
	void peak_3()
	{
		auto i = m.begin();
		Pair min = *i;
		Pair max = *i;
		for (; i != m.end(); i++)
		{
			if (*i > max)
				max = *i;
			if (*i < min)
				min = *i;
		}
		min = min + max;
		i = m.begin();
		int k = 0;
		for (; k < m.size();)
		{
			auto buff = i;
			max = *i + min;
			++i;
			m.erase(buff);
			m.insert(max);
			++k;
		}
	}
};
void ex_3()
{
	int size = 5;
	List<Pair> t(size);
	t.show_3();
	t.dell_3();
	t.show_3();
	t.peak_3();
	t.show_3();
}
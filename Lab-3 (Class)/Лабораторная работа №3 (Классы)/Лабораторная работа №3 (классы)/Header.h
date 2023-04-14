#include<iostream>
class pair
{
	int first;
	double second;
public:
	pair() { first = 0; second = 0; };
	pair(int m, int s) { first = m; second = s; };
	pair(const pair& t) { first = t.first; second = t.second; };
	~pair() {};
	int get_first() { return first; };
	int get_second() { return second; };
	void set_first(int m) { first = m; };
	void set_second(int s) { second = s; };
	pair& operator=(const pair&);
	pair operator+(const pair&);
	pair operator-(const pair&);
	pair operator-(const int d);
	pair operator-(const double d);
	friend std::istream& operator>>(std::istream& in, pair& t);
	friend std::ostream& operator<<(std::ostream& out, const pair& t);
};

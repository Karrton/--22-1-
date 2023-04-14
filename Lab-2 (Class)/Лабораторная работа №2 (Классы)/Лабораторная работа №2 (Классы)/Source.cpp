#include <iostream>
#include "Header.h"
using namespace std;
cash::cash()
{ 
	name = "";
	salary = 0;
	prize = 0; 
} 
cash::cash(string n, int s, double k)
{ 
	name = n;
	salary = k;
	prize = s;
} 
cash::cash(const cash&t)
{
	name = t.name;
	salary = t.salary;
	prize  = t.prize;
} 
cash::~cash()
{ 
	cout<<"Destructor object "<<this<<endl; 
} 
string cash::get_name()
{ 
	return name; 
} 
void cash::set_name(string n)
{
	name = n;
}
double cash::get_salary()
{ 
	return salary;
} 
void cash::set_salary(double k)
{
	salary = k;
}
int cash::get_prize()
{ 
	return prize;
} 
void cash::set_prize(int s)
{
	prize = s;
}
void cash::show()
{ 
	cout<<"Name : "<<name<<endl; 
	cout<<"Salary : "<<salary<<endl; 
	cout<<"Prize : "<<prize<<endl; 
}

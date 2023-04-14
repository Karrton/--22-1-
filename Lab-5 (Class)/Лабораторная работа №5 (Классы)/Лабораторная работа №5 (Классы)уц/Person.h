#pragma once
#include<iostream>
#include<string>
#include"Object.h"
class person :
	public Object
{
protected:
	std::string name;
	int age;
public:
	person() { name = ""; age = 0; };
	person(std::string m, int s) { name = m; age = s; };
	person(const person& t) { name = t.name; age = t.age; };
	virtual ~person(void);
	int get_age() { return age; };
	std::string get_name() { return name; };
	void set_age(int m) { age = m; };
	void set_name(std::string s) { name = s; };
	void show();
	person& operator=(const person& t);
	friend std::istream& operator>>(std::istream& in, person& t);
	friend std::ostream& operator<<(std::ostream& out, const person& t);
};

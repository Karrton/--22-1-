#pragma once
#include"Person.h"
#include<string>
#include<iostream>
class student :
	public person
{
protected:
	std::string object;
	unsigned int mark;
public:
	student() :person() { object = ""; mark = 0; };
	student(std::string a, int b, std::string c, int d) :person(a, b) { object = c; mark = d; };
	student(const student& t) { name = t.name, age = t.age, object = t.object; mark = t.mark; };
	~student(void) {};
	int get_mark() { return mark; };
	std::string get_object() { return object; };
	void set_mark(int m) { mark = m; };
	void set_object(std::string s) { object = s; };
	void chek_mark() { if (mark < 3) std::cout << "Unsatisfactory" << std::endl; }
	void show();
	student& operator=(const student& t);
	friend std::istream& operator>>(std::istream& in, student& t);
	friend std::ostream& operator<<(std::ostream& out, const student& t);
};

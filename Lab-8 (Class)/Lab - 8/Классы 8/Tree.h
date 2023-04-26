#pragma once
#include "Magazin.h"
#include "Object.h"
class Tree
{
protected:
	Object** beg;
	int size;
	int cur;
public:
	Tree();
	Tree(int);
	~Tree(void);
	void Add();
	void Del();
	void Show();
	void Get_Name();
	int operator()();
};
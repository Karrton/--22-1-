#pragma once
#include <iostream>
#include<list>
#include<ctime>
#include <random>

using namespace std;

double generate_random();

list<double> lst;

void add_1(int size)
{
    double val = 0;
    for (int i = 0; i < size; i++)
    {
        double a = (rand() % 10) + generate_random();
        val += a;
        lst.push_back(a);
    }
    val /= size;
    lst.push_back(val);
}

void show_1(const list<double>& obj)
{
    if (lst.empty())
        cout << "List empty" << endl;
    else
    {
        for (auto& i : obj)
            cout << i << " ";
        cout << endl;
    }
}

void del_1()
{
    int a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    list<double>::iterator k = lst.begin();
    while (k != lst.end())
    {
        if (*k < b && *k > a)
            k = lst.erase(k);
        else
            k++;
    }
}

void peak_1()
{
    list<double>::iterator k = lst.begin();
    if (lst.empty())
        return;
    double min = *k;
    double max = *k;
    while (k != lst.end())
    {
        if (*k > max)
            max = *k;
        if (*k < min)
            min = *k;
        k++;
    }
    min += max;
    k = lst.begin();
    while (k != lst.end())
    {
        *k += min;
        k++;
    }
}

void ex_1()
{
	srand(time(0));
    int size = 10;
    add_1(size);
    show_1(lst);
    del_1();
    show_1(lst);
    peak_1();
    show_1(lst);
}
#pragma once

#include"Pair.h"

using namespace std;

list<Pair> lst2;

double generate_random();

void add_2(int size)
{
    Pair b(0, 0);
    for (int i = 0; i < size; i++)
    {
        Pair a(rand() % 10, rand() % 10 + generate_random());
        lst2.push_back(a);
        b = b + a;
    }
    b = b / size;
    lst2.push_back(b);
}

void show_2(const list<Pair>& obj)
{
    if (lst2.empty())
        cout << "List empty" << endl;
    else
    {
        for (auto& i : obj)
            cout << i << " ";
        cout << endl;
    }
}

void del_2()
{
    Pair a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    auto k = lst2.begin();
    while (k != lst2.end())
    {
        if (*k < b && *k > a)
            k = lst2.erase(k);
        else
            k++;
    }
}

void peak_2()
{
    list<Pair>::iterator k = lst2.begin();
    if (lst2.empty())
        return;
    Pair min = *k;
    Pair max = *k;
    while (k != lst2.end())
    {
        if (*k > max)
            max = *k;
        if (*k < min)
            min = *k;
        k++;
    }
    min = min + max;
    k = lst2.begin();
    while (k != lst2.end())
    {
        *k = *k + min;
        k++;
    }
}

void ex_2()
{
    srand(time(0));
    int size = 10;
    add_2(size);
    show_2(lst2);
    del_2();
    show_2(lst2);
    peak_2();
    show_2(lst2);
}
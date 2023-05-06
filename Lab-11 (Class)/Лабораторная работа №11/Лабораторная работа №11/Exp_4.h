#pragma once

#include<queue>

using namespace std;

double generate_random();

priority_queue <Pair> q, q1;

void add_4(int size)
{
    Pair b;
    for (int i = 0; i < size; i++)
    {
        Pair a(rand() % 10, rand() % 10 + generate_random());
        q.push(a);
        b = b + a;
    }
    b = b / size;
    q.push(b);
}

void show_4(const priority_queue<Pair>& obj)
{
    q1 = q;
    while (!q1.empty())
    {
        cout << q1.top() << ' ';
        q1.pop();
    }
    cout << endl;
}

void del_4()
{
    Pair a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    while (!q.empty())
    {
        auto d = q.top();
        if (d > b || d < a)
            q1.push(d);
        q.pop();
    }
    while (!q1.empty())
    {
        auto d = q1.top();
        q.push(d);
        q1.pop();
    }
}

void peak_4()
{
    if (q.empty())
        return;
    Pair min = q.top();
    Pair max = q.top();
    while (!q.empty())
    {
        auto d = q.top();
        q1.push(d);
        if (d > max)
            max = d;
        if (d < min)
            min = d;
        q.pop();
    }
    min = min + max;
    while (!q1.empty())
    {
        auto d = q1.top();
        d = d + min;
        q.push(d);
        q1.pop();
    }
}

void ex_4()
{
    int size = 8;
    srand(time(0));
    add_4(size);
    show_4(q);
    del_4();
    show_4(q);
    peak_4();
    show_4(q);
}
#pragma once
template <typename T>
class List1
{
        priority_queue <T> q, q1;
public:
    List1() {}
    ~List1() {}
    List1(int size)
    {
        T b;
        for (int i = 0; i < size; i++)
        {
            T a(rand() % 10, rand() % 10 + generate_random());
            q.push(a);
            b = b + a;
        }
        b = b / size;
        q.push(b);
    }
    void add_5()
    {
        T a(rand() % 10, rand() % 10 + generate_random());
        q.push(a);
    }
    void show_5()
    {
        q1 = q;
        while (!q1.empty())
        {
            cout << q1.top() << ' ';
            q1.pop();
        }
        cout << endl;
    }

    void del_5()
    {
        T a, b;
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

    void peak_5()
    {
        if (q.empty())
            return;
        T min = q.top();
        T max = q.top();
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
};

void ex_5()
{
    int size = 3;
    List1<Pair> q1(size);
    q1.add_5();
    q1.show_5();
    q1.del_5();
    q1.show_5();
    q1.peak_5();
    q1.show_5();
}
#pragma once

using namespace std;

template <class T>
class List
{
	list<T> data;
public:
    List() {}
    ~List() {}
    List(int size)
    {
        T b;
        for (int i = 0; i < size; i++)
        {
            T a;
            cin >> a;
            data.push_back(a);
            b = b + a;
        }
        b = b / size;
        data.push_back(b);
    }
    void show()
    {
        if (data.empty())
            cout << "List empty" << endl;
        else
        {
            for (auto it = data.begin(); it != data.end(); ++it)
                cout << *it << " ";
            cout << endl;
        }
    }
    void del()
    {
        T a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        auto k = data.begin();
        while (k != data.end())
        {
            if (*k < b && *k > a)
                k = data.erase(k);
            else
                k++;
        }
    }
    void peak()
    {
        auto k = data.begin();
        if (data.empty())
            return;
        T min = *k;
        T max = *k;
        while (k != data.end())
        {
            if (*k > max)
                max = *k;
            if (*k < min)
                min = *k;
            k++;
        }
        min = min + max;
        k = data.begin();
        while (k != data.end())
        {
            *k = *k + min;
            k++;
        }
    }
    void add()
    {
        T a;
        cin >> a;
        data.push_back(a);
    }
};

void ex_3()
{
    int size = 3;
    List<Pair> lst3(size);
    lst3.add();
    lst3.show();
    lst3.del();
    lst3.show();
    lst3.peak();
    lst3.show();
}

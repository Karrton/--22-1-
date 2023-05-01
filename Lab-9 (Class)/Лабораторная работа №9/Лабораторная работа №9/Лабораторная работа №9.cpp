#include <iostream>
#include "List.h"

int main()
{
    List<int> lst;
    int d(3);
    int s(4);
    int m(1);
    try
    {
        lst.push_back(d);
        lst.push_back(s);
        lst.push_back(s);
        lst.push_back(s);
    }
    catch (int a)
    {
        if (a == 2)
            std::cout << "Exceeded the maximum size" << std::endl;
    }
    try
    {
        std::cout << "List[0] * List[2] = " << lst[-5] * lst[1] << std::endl;
    }
    catch (int a)
    {
        if (a == 1)
            std::cout << "Index out of range" << std::endl;
    }
    return 0;
}

#include <iostream>
#include"Header.h"

int main()
{
    pair p;
    p.set_first(10);
    p.set_second(1.25);
    pair p2(1, 1.25);
    std::cin >> p2;
    std::cout << p2 << std::endl;
    p2 = p2-p;
    std::cout << p2 << std::endl;
    p2 = p2 - 12;
    p2 = p2 - 1.25;
    std::cout << p2 << std::endl;
}

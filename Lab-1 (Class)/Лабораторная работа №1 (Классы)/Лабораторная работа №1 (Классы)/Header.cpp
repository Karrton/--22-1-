#include"Header.h"
#include<iostream>
void billy::Init(double s, int n)
{
    if (n >= 0)
    {
        billy::first = s;
        billy::second = n;
    }
}
void billy::Read()
{
    std::cin >> billy::first >> billy::second;
}
void billy::Show() {
    std::cout << "First: " << billy::first << std::endl;
    std::cout << "Second: " << billy::second << std::endl;
}
double billy::Element(int j)
{
    double buff = 0;
    buff = billy::first * pow(billy::second, j - 1);
    return buff;
}

billy make_billy(double s, int n) 
{
    if (n >= 0) {
        billy b1;
        b1.Init(s, n);
        return b1;
    }
    else {
        std::cout << "Error: incorrect parameters" << std::endl;
        exit(1);
    }
}

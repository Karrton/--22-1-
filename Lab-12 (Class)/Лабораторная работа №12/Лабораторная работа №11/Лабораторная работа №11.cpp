#include <iostream>
#include <random>
#include"Exp_1.h"
#include"Exp_2.h"
#include"Exp_3.h"

double generate_random()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dis(0.0, 1.0);
    return round(dis(gen) * 10000) / 10000;
}

int main()
{
    ex_1();
    system("pause");
    system("cls");
    ex_2();
    system("pause");
    system("cls");
    ex_3();
    system("pause");
    system("cls");
}

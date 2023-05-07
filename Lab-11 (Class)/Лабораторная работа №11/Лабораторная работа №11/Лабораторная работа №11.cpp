#include <iostream>
#include<list>
#include<ctime>
#include"Exp_1.h"
#include"Exp_2.h"
#include"Exp_3.h"
#include"Exp_4.h"
#include"Exp_5.h"
using namespace std;

double generate_random()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dis(0.0, 1.0);
    return dis(gen);
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
    ex_4();
    system("pause");
    system("cls");
    ex_5();
    system("pause");
    system("cls");
}

#include <iostream>
#include "Header.h"

int main() 
{
    cash b("Petr", 5000, 10);
    b.show();
    cash b2 = b;
    b.set_name("Oleg");
    b.set_salary(30000);
    b.set_prize(20);
    b.show();
    b2.show();
    return 0;
}

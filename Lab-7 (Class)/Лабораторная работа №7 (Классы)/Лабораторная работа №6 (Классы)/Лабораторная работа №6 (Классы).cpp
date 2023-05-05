#include <iostream>
#include "List.h"
#include "Pair.h"

int main() {
    List<pair> lst;
    pair d(3, 2.34);
    pair s(4, 3.34);
    pair m(1, 6.34);
    lst.push_back(d);
    lst.push_back(s);
    lst.push_back(m);
    std::cout << "Size of range - " << lst.size() << std::endl;
    std::cout << "List[0] * List[1] = " << lst[0] * lst[1] << std::endl;
    List<pair>::Iterator a = lst.begin();
    std::cout << "a+3 = " << *(a + 3) << std::endl;
    int i = 0;
    for (List<pair>::Iterator it = lst.begin(); it != lst.end(); ++it)
        std::cout << "List[" << i++ << "] = " << *it << std::endl;
    return 0;
}

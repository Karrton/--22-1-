#include <iostream>
#include "List.h"

int main() {
    List<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(4);
    std::cout << "Size of range - " << lst.size() << std::endl;
    std::cout << "List[0] * List[1] = " << lst[0] * lst[1] << std::endl;
    List<int>::Iterator a = lst.begin();
    std::cout << "a+3 = " << *(a + 3) << std::endl;
    int i = 0;
    for (List<int>::Iterator it = lst.begin(); it != lst.end(); ++it) 
        std::cout << "List[" << i++ << "] = " << *it << std::endl;
    return 0;
}

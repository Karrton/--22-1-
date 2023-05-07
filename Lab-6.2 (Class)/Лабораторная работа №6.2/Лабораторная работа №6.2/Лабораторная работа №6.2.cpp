#include <iostream>
#include"Stack.h"

int main() {
    Stack<int> myStack;
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    std::cout << "Size of stack: " << myStack.size() << std::endl; // Output: Size of stack: 3
    std::cout << "Top element: " << myStack.top() << std::endl; // Output: Top element: 3
    myStack.pop();
    std::cout << "Size of stack after pop: " << myStack.size() << std::endl; // Output: Size of stack after pop: 2
    std::cout << "Top element after pop: " << myStack.top() << std::endl; // Output: Top element after pop: 2
    myStack.pop();
    myStack.pop();
    std::cout << "Is stack empty? " << myStack.empty() << std::endl; // Output: Is stack empty? 1 (true)
    return 0;
}

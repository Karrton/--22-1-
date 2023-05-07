#pragma once
#pragma once
#include <iostream>
#include <vector>
template<typename T>
class Stack {
private:
    std::vector<T> data;
public:
    void push(const T& item)
    {
        data.push_back(item);
    }
    void pop()
    {
        data.pop_back();
    }
    T& top()
    {
        return data.back();
    }
    bool empty() const
    {
        return data.empty();
    }
    size_t size() const
    {
        return data.size();
    }
};
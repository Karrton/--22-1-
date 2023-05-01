#include <iostream>
#include"Error.h"
const int MAX_SIZE = 3;

template <typename T>
class List
{
private:
    struct Node
    {
        T data;
        Node* next;
        Node(const T& data = T(), Node* next = nullptr) : data(data), next(next) {}
    };
public:
    class Iterator
    {
    private:
        Node* current;
    public:
        Iterator(Node* current = nullptr) : current(current) {}
        Iterator& operator++()
        {
            if (current != nullptr)
            {
                current = current->next;
            }
            return *this;
        }
        bool operator!=(const Iterator& other) const
        {
            return current != other.current;
        }
        T& operator*() {
            return current->data;
        }
        Iterator& operator+(int n)
        {
            for (int i = 0; i < n - 1; i++)
                current = current->next;
            return *this;
        }
    };
private:
    Node* head;
    Node* tail;
public:
    List() : head(nullptr), tail(nullptr) {}
    ~List()
    {
        while (head != nullptr)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    void push_back(const T& data)
    {
        int a = size();
        if (a >= MAX_SIZE)
            throw MaxSizeError();
        if (head == nullptr)
        {
            head = new Node(data);
            tail = head;
        }
        else
        {
            tail->next = new Node(data);
            tail = tail->next;
        }
    }
    int size()
    {
        Node* current = head;
        int i = 0;
        while (current != nullptr)
        {
            current = current->next;
            i++;
        }
        return i;
    }
    Iterator begin() const
    {
        return Iterator(head);
    }
    Iterator end() const
    {
        return Iterator(nullptr);
    }
    T& operator[](int index) const
    {
        if (index < 0)
            throw IndexError1();
        Node* current = head;
        int i = 0;
        while (current != nullptr && i < index)
        {
            current = current->next;
            i++;
        }
        if (current == nullptr)
            throw IndexError2();
        return current->data;
    }
    T operator*(Node& a) const
    {
        Node b = this;
        return b.data * a.data;
    }
};
#pragma once



template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;

    Node(const T &data)
        : data(data)
        , next(nullptr)
    {}
};

template <typename T>
class Stack
{
public:
    Node<T> *top;

    Stack()
        : top(nullptr)
    {}

    ~Stack()
    {
        while (!empty())
            pop();
    }

    void push(const T &data)
    {
        Node<T> *item = new Node<T>(data);
        item->next = top;
        top = item;
    }

    void pop()
    {
        Node<T> *next = top->next;
        delete top;
        top = next;
    }

    const T& peek() const
    {
        return top->data;
    }

    bool empty() const
    {
        return top == nullptr;
    }
};
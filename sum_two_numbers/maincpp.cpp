#include <LinkedList.h>
#include <iostream>
#include <cmath>


template<typename T>
void sum(const Node<T> *a, const Node<T> *b, LinkedList<T> &result, T &carry)
{
    if (a->next && b->next)
        sum(a->next, b->next, result, carry);

    T _sum = a->data + b->data + carry;
    carry = _sum / 10;
    _sum %= 10;

    result.appendToHead(_sum);
}

template<typename T>
void sum(const Node<T> *a, const Node<T> *b, LinkedList<T> &result)
{
    T carry = 0;
    sum(a, b, result, carry);
    if (carry > 0)
        result.appendToHead(carry);
}

template<typename T>
void sumRemaining(const Node<T> *head, const Node<T> *curr, LinkedList<T> &result, T &carry)
{
    if (head != curr)
    {
        sumRemaining(head->next, curr, result, carry);

        T _sum = head->data + carry;
        carry = _sum / 10;
        _sum %= 10;
    
        result.appendToHead(_sum);
    }
}

template<typename T>
LinkedList<T> sum(const LinkedList<T> &a, const LinkedList<T> &b)
{
    LinkedList<T> result;
    size_t a_size = a.size();
    size_t b_size = b.size();
    if (a_size == 0)
    {
        result.copyFrom(b);
    }
    else if (b_size == 0)
    {
        result.copyFrom(b);
    }
    else if (a_size == b_size)
    {
        sum(a.head, b.head, result);
    }
    else
    {
        const Node<T> *a_ptr = a.head;
        const Node<T> *b_ptr = b.head;
        size_t diff = std::abs(a_size - b_size);
        if (a_size < b_size)
            std::swap(a_ptr, b_ptr);
        
        const Node<T> *curr_ptr = a_ptr;
        for (; diff; --diff, curr_ptr = curr_ptr->next);

        int carry = 0;
        sum(curr_ptr, b_ptr, result, carry);

        sumRemaining(a_ptr, curr_ptr, result, carry);
        if (carry > 0)
            result.appendToHead(carry);
    }

    return result;
}

int main()
{
    LinkedList<int> a, b;
    a.appendToTail(9);
    a.appendToTail(9);
    a.appendToTail(9);
    b.appendToTail(1);

    LinkedList<int> result = sum(a, b);

    result.print(std::cout);
}
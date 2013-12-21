#include <LinkedList.h>
#include <iostream>


template<typename T>
void rotate(LinkedList<T> &list, int k)
{
    Node<T> *slow = list.head;
    if (!slow)
        return;

    for (int i = 0; i < (k - 1); ++i)
    {
        slow = slow->next;
        if (!slow)
            slow = list.head;
    }

    Node<T> *last = slow;

    while (last->next)
        last = last->next;

    if (slow == last)
        return;

    last->next = list.head;
    Node<T> *kth = slow->next;
    list.head = kth;
    slow->next = nullptr;
}

int main()
{
    LinkedList<char> list;
    list.appendToTail('A');
    list.appendToTail('B');
    list.appendToTail('C');
    list.appendToTail('D');
    list.appendToTail('E');

    rotate(list, 6);

    list.print(std::cout);
}
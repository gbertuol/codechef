#include <LinkedList.h>
#include <iostream>

typedef Node<int> Node_;
typedef LinkedList<int> LinkedList_;



Node_ *detectLoop(LinkedList_ &list)
{
    Node_ *slow = list.head;
    Node_ *fast = list.head;

    while (true)
    {
        if (!fast || !fast->next) // found the tail, no loop
            return NULL;

        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            break;
    }

    slow = list.head;
    
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

int main()
{
    LinkedList_ list;
    auto head = list.appendToHead(0);
    auto last = head;
    Node_ *three = NULL;
    for (int i = 1; i < 9; ++i)
    {
        last = list.insertAfter(i, last);
        if (i == 3)
            three = last;
    }
    last->next = three;

    Node_ *loop = detectLoop(list);

    return 0;
}
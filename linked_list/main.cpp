#include "LinkedList.h"
#include <iostream>




int main()
{
    LinkedList<int> list;
    list.appendToTail(1);
    list.appendToTail(2);
    list.appendToHead(0);
    list.print(std::cout);
    list.remove(list.head->next);
    list.print(std::cout);
    list.insertAfter(3, list.head->next);
    list.print(std::cout);
    list.insertAfter(4, list.head->next);
    list.print(std::cout);

    return 0;
}
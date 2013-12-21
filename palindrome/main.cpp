#include <LinkedList.h>
#include <vector>
#include <iostream>


bool _isPalindrome(int x, int &y)
{
    if (x < 0)
        return false;
    if (x == 0)
        return true;
    if (_isPalindrome(x / 10, y) && (x % 10 == y % 10))
    {
        y /= 10;
        return true;
    }
    else
    {
        return false;
    }
}

bool isPalindrome(int x)
{
    return _isPalindrome(x, x);
}

template <typename T>
bool isPalindrome(const LinkedList<T> &list)
{
    const Node<T> *slow = list.head;
    const Node<T> *fast = list.head;
    std::vector<const Node<T>*> stack;

    while (fast && fast->next)
    {
        stack.push_back(slow);
        slow = slow->next;
        fast = fast->next->next;
    }

    if (fast)
        slow = slow->next;

    while (slow)
    {
        auto node = stack.back();
        stack.pop_back();
        if (node->data != slow->data)
            return false;
        slow = slow->next;
    }

    return true;
}


int main()
{
    LinkedList<char> list;
    list.appendToTail('h');
    list.appendToTail('a');
    list.appendToTail('n');
    list.appendToTail('n');
    list.appendToTail('a');
    list.appendToTail('h');

    std::cout << isPalindrome(list) << std::endl;

    int x = 121;
    std::cout << isPalindrome(x) << std::endl;

    return 0;
}

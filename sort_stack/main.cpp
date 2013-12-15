#include <Stack.h>
#include <iostream>


template <typename T>
void sort(Stack<T> &stack, Stack<T> &sorted)
{
    sorted.push(stack.peek());
    stack.pop();
    
    while (!stack.empty())
    {
        T top_val = stack.peek();
        stack.pop();

        while (!sorted.empty() && sorted.peek() > top_val)
        {
            stack.push(sorted.peek());
            sorted.pop();
        }
        sorted.push(top_val);
    }
}

int main()
{
    Stack<int> stack, sorted;
    stack.push(10);
    stack.push(1);
    stack.push(8);

    sort(stack, sorted);

    while (!sorted.empty())
    {
        std::cout << sorted.peek() << std::endl;
        sorted.pop();
    }
}
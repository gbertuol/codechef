#include <Stack.h>
#include <iostream>


template <typename T>
class StackWithMin
{
public:
    Stack<T> data;
    Stack<T> mins;

    StackWithMin()
    {
        mins.push(std::numeric_limits<int>::max());
    }

    void push(const T &val)
    {
        if (val <= mins.peek())
            mins.push(val);
        data.push(val);
    }

    void pop()
    {
        if (data.peek() == mins.peek())
            mins.pop();
        data.pop();
    }

    const T& min() const
    {
        return mins.peek();
    }

    bool empty() const
    {
        return data.empty();
    }
};


int main()
{
    StackWithMin<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(0);
    stack.push(1);
    stack.push(-1);
    stack.push(-1);
    stack.push(2);

    while (!stack.empty())
    {
        std::cout << stack.min() << std::endl;
        stack.pop();
    }

}
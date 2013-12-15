#include <Stack.h>
#include <iostream>



template <typename T>
class QueueAsTwoStacks
{
public:
    Stack<T> newestOnTop;
    Stack<T> oldestOnTop;


    void add(const T &val)
    {
        if (oldestOnTop.empty())
            swap(newestOnTop, oldestOnTop);
        oldestOnTop.push(val);
    }

    T remove()
    {
        if (newestOnTop.empty())
            swap(oldestOnTop, newestOnTop);
        T val = newestOnTop.peek();
        newestOnTop.pop();
        return val;
    }

    bool empty() const
    {
        return newestOnTop.empty() && oldestOnTop.empty();
    }

protected:
    void swap(Stack<T> &from, Stack<T> &to)
    {
        while (!from.empty())
        {
            to.push(from.peek());
            from.pop();
        }
    }
};


int main()
{
    QueueAsTwoStacks<int> queue;

    for (int i = 0; i < 10; ++i)
        queue.add(i);

    std::cout << queue.remove() << std::endl;
    std::cout << queue.remove() << std::endl;

    queue.add(11);
    std::cout << queue.remove() << std::endl;
    queue.add(12);

    while (!queue.empty())
        std::cout << queue.remove() << std::endl;
}
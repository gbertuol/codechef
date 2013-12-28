#include <vector>
#include <iostream>
#include <iterator>

void pushToEnd(std::vector<int> &arr, int value)
{
    size_t nonValueCount = 0;

    for (size_t i = 0; i < arr.size(); ++i)
    {
        if (arr[i] != value)
        {
            arr[nonValueCount++] = arr[i];
        }
    }

    while (nonValueCount < arr.size())
        arr[nonValueCount++] = value;
}

int main()
{
    std::vector<int> arr = { 1, 0, 2, 0, 0, 3 };
    pushToEnd(arr, 2);

    std::copy(arr.begin(), arr.end(), std::ostream_iterator<int>(std::cout, " "));

    return 0;
}
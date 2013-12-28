#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>

int count(const std::vector<int> &arr, int diff)
{
    int count = 0;
    for (size_t i = 0; i < arr.size(); ++i)
    {
        for (size_t j = i + 1; j < arr.size(); ++j)
        {
            int currDiff = std::labs(arr[i] - arr[j]);
            if (currDiff == diff)
                count++;
        }
    }
    return count;
}

void removeDuplicates(std::vector<int> &arr)
{
    auto begin = arr.begin();
    auto end = arr.end();
    auto result = begin;
    while (++begin != end)
    {
        if (*begin != *result)
            *(++result) = *begin;
    }
    arr.erase(++result, end);
}

bool binarySearch(const std::vector<int> &arr, int start, int end, int target)
{
    if (end < start)
        return false;

    int mid = start + (end - start) / 2;
    if (target < arr[mid])
    {
        return binarySearch(arr, start, mid - 1, target);
    }
    else if (target > arr[mid])
    {
        return binarySearch(arr, mid + 1, end, target);
    }
    else
        return true;
}

int count2(std::vector<int> &arr, int diff)
{
    std::sort(arr.begin(), arr.end());
    removeDuplicates(arr);

    int n = arr.size();
    int count = 0;
    for (int i = 0; i < n; ++i)
    {
        if (binarySearch(arr, i + 1, n - 1, arr[i] + diff))
            count++;
    }

    return count;
}

int count3(std::vector<int> &arr, int diff)
{
    std::sort(arr.begin(), arr.end());
    removeDuplicates(arr);

    int i = 0;
    int j = 1;
    int end = arr.size();

    int count = 0;
    while (i < end && j < end)
    {
        int currDiff = arr[j] - arr[i];
        if (currDiff == diff)
        {
            count++;
            ++i;
            ++j;
        }
        else if (currDiff < diff)
        {
            ++j;
        }
        else
        {
            ++i;
        }
    }

    return count;
}

int main()
{
    std::vector<int> arr = { 8, 12, 16, 4, 0, 20, 7, 9, 89, 93 };
    //std::cout << count(arr, 3);
    std::cout << count3(arr, 4);

    //std::copy(arr.begin(), arr.end(), std::ostream_iterator<int>(std::cout, " "));
    return 0;
}
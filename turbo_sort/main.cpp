#include <iostream>
#include <cstdio>
#include <vector>

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
    std::freopen("input.txt", "r", stdin);
    std::freopen("output.txt", "w", stdout);
#endif

    int nr_of_lines = 0, number = 0;;
    std::vector<int> hash(10e6 + 1, 0);

    scanf("%d", &nr_of_lines);

    while (nr_of_lines--)
    {
        fscanf(stdin, "%d", &number);
        hash[number]++;
    }

    size_t nsize = hash.size();
    for (size_t k = 0; k < nsize; ++k)
    for (int i = 0; i < hash[k]; ++i)
        fprintf(stdout, "%d\n", k);

    return 0;
}


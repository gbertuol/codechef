
#include <iostream>
#include <cstdio>


int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
    std::freopen("input.txt", "r", stdin);
    std::freopen("output.txt", "w", stdout);
#endif

    long long unsigned int nr_of_lines = 0, input_nr = 0, nr_of_zeros = 0;

    scanf("%llu", &nr_of_lines);

    while (nr_of_lines != 0)
    {
        scanf("%llu", &input_nr);
        nr_of_lines--;
        
        nr_of_zeros = 0;
        do
        {
            input_nr /= 5;
            nr_of_zeros += input_nr;
        }
        while (input_nr > 0);

        fprintf(stdout, "%llu\n", nr_of_zeros);
    }
    return 0;
}
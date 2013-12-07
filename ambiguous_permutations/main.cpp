#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string.h>


int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
    std::freopen("input.txt", "r", stdin);
    std::freopen("output.txt", "w", stdout);
#endif

    unsigned int expr_len = 0;
    unsigned int expression[100000];

    fscanf(stdin, "%d", &expr_len);

    while (expr_len != 0)
    {
        bool isAmbiguous = true;

        for (unsigned int k = 0; k < expr_len; ++k)
            fscanf(stdin, "%d", &expression[k + 1]);

        for (unsigned int k = 1; k <= expr_len; ++k)
            if (expression[expression[k]] != k)
            {
                isAmbiguous = false;
                break;
            }
        
        if (isAmbiguous)
            fprintf(stdout, "ambiguous\n");
        else
            fprintf(stdout, "not ambiguous\n");

        fscanf(stdin, "%d", &expr_len);
    }

    return 0;
}


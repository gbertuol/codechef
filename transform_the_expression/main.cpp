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

    char expression[401];
    int nr_of_expr = 0;
    char stack[200];
    unsigned long top = 0;

    scanf("%d", &nr_of_expr);

    while (nr_of_expr--)
    {
        fscanf(stdin, "%s", expression);
        size_t expr_len = strlen(expression);

        for (size_t k = 0; k < expr_len; ++k)
        {
            char c = expression[k];
            switch (c)
            {
            case '(':
                break;
            case ')':
                fprintf(stdout, "%c", stack[top]);
                top--;
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                top++;
                stack[top] = c;
                break;
            default:
                fprintf(stdout, "%c", c);
                break;
            }
        }
        fprintf(stdout, "\n");
    }

    return 0;
}


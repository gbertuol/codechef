#include <iostream>
#include <cstdio>


int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
    std::freopen("input.txt", "r", stdin);
    std::freopen("output.txt", "w", stdout);
#endif

    int a[200];
    char buffer[5];
    int nr_of_lines = 0, m = 0, n = 0, temp = 0;

    scanf("%d", &nr_of_lines);

    while (nr_of_lines--)
    {
        scanf("%d", &n);
        m = 1;
        a[0] = 1;

        temp = 0.;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                int x = a[j] * i + temp;
                a[j] = x % 10;
                temp = x / 10;
            }

            while (temp > 0)
            {
                a[m] = temp % 10;
                temp = temp / 10;
                ++m;
            }
        }

        for (int i = m - 1; i >= 0; --i)
            fprintf(stdout, "%d", a[i]);
        fprintf(stdout, "\n");
    }
    return 0;
}
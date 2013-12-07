#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
    std::freopen("input.txt", "r", stdin);
    std::freopen("output.txt", "w", stdout);
#endif

    int nr_or_triangles = 0, nr_of_lines = 0;
    int triangle[101][101];
    int *line_ptr, *prev_line_ptr;
    int curr_val, prev_val;

    scanf("%d", &nr_or_triangles);

    while (nr_or_triangles--)
    {
        fscanf(stdin, "%d", &nr_of_lines);

        for (int line = 0; line < nr_of_lines; ++line)
        {
            int *line_ptr = triangle[line];
            for (int col = 0; col <= line; ++col, ++line_ptr)
                fscanf(stdin, "%d", line_ptr);
        }

        for (int line = nr_of_lines - 1; line > 0; --line)
        {
            prev_line_ptr = &triangle[line - 1][line - 1];
            curr_val = triangle[line][line];
            line_ptr = &triangle[line][line - 1];
            for (int col = line - 1; col >= 0; --col)
            {
                prev_val = *line_ptr--;
                int max = curr_val ^ ((curr_val ^ prev_val) & -(curr_val < prev_val));
                curr_val = prev_val;
                *prev_line_ptr-- += max;
            }
        }

        fprintf(stdout, "%d\n", triangle[0][0]);
    }

    return 0;
}


#include <iostream>
#include <cstdio>

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
    std::freopen("input.txt", "r", stdin);
    std::freopen("output.txt", "w", stdout);
#endif

    char word[128];
    int nr_of_lines = 0, holes = 0;;

    scanf("%d", &nr_of_lines);

    while (nr_of_lines--)
    {
        fscanf(stdin, "%s", &word);
    
        holes = 0;
        char *c = word;
        while (*c != '\0')
        {
            switch (*c)
            {
            case 'A':
            case 'D':
            case 'O':
            case 'P':
            case 'Q':
            case 'R':
                holes += 1;
                break;
            case 'B':
                holes += 2;
                break;
            default:
                break;
            }
            ++c;
        }
        
        fprintf(stdout, "%d\n", holes);
    }

    return 0;
}
#include <iostream>


// null terminated string
int encode(char *str)
{
    char *str_ptr = str;
    char *str_iterator = str;
    char last_char = *str_iterator;
    int counter = 0;

    while (*str_iterator)
    {
        char curr_char = *str_iterator++;
        if (curr_char != last_char)
        {
            *str_ptr++ = last_char;
            int nr_of_digits = sprintf(str_ptr, "%d", counter);
            str_ptr = str_ptr + nr_of_digits;
            counter = 1;
        }
        else
        {
            counter++;
        }
        last_char = curr_char;
    }
    *str_ptr++ = last_char;
    int nr_of_digits = sprintf(str_ptr, "%d", counter);
    str_ptr = str_ptr + nr_of_digits;

    return str_ptr - str;
}




int main()
{
    const char *buffer = "abbbbbddff";
    int length = strlen(buffer);
    char *str = (char *)malloc((length + 1) * sizeof(char));
    memcpy(str, buffer, length * sizeof(char));
    str[length] = '\0';

    length = encode(str);
    //str[length] = '\0';
    std::cout << str << std::endl;

    free(str);

    return 0;
}
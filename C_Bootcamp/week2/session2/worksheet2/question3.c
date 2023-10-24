#include <stdio.h>

int str_len(char *str)
{
    int count = 0;
    while (*(str+count) != '\0')
    {
        count++;
    }
    return count;
}

int main()
{
    char test[20] = "This is a test";
    printf("%d\n", str_len(test));
    return 0;
}
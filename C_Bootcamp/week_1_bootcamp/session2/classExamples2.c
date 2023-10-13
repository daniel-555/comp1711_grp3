#include <stdio.h>

int main()
{
    char hello[5] = "Hello";
    for (int i = 4; i >= 0; i--)
    {
        printf("%c\n", *(hello+i));
    }

    return 0;
}
#include <stdio.h>

int main()
{
    // Task 1
    for (int i = 0; i < 20; i++) 
    {
        if (i % 2 != 0)
        {
            printf("%d\n", i);
        }
    }

    // Task 2
    int i = 20;
    while (i >= 0)
    {
        if (i % 2 == 0)
        {
            printf("%d\n", i);
        }
        i--;
    }

    // Task 3
    for (int i = 1; i <= 10; i++)
    {
        printf("%d\n", i*i);
    }

    return 0;
}
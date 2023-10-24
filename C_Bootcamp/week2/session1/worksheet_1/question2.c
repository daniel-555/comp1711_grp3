#include <stdio.h>

int main()
{
    int num;
    scanf("%d", &num);

    if (num % 4 == 0 && num % 5 == 0)
    {
        printf("%d is divisible by both 4 and 5\n", num);
    }
    else
    {
        printf("%d is not divisible by both 4 and 5\n", num);
    }

    return 0;
}
#include <stdio.h>

int main()
{
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);

    if (number > 0)
    {
        printf("The number is greater than 0\n");
    } 
    else if (number < 0)
    {
        printf("The number is less than 0\n");
    }
    else
    {
        printf("The number is 0\n");
    }

    return 0;
}
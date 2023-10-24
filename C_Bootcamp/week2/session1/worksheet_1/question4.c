#include <stdio.h>

int main()
{
    int temp;

    printf("Enter a temperature: ");
    scanf("%d", &temp);

    if (-10 <= temp && temp <= 40)
    {
        printf("The temperature is in the desired range.\n");
    }
    else
    {
        printf("The temperature is out of the desired range.\n");
    }

    return 0;
}
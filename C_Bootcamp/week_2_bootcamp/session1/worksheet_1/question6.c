#include <stdio.h>

int main() 
{
    int num;

    while (1==1)
    {
        printf("Enter a number: ");
        scanf("%d", &num);

        // Loop runs forever until -1 is inputted
        if (num == -1) break;

        if (num >= 0 && num <= 100)
        {
            printf("The number between 0 and 100\n");
        }
        else 
        {
            printf("The number is not between 0 and 100\n");
        }
    } 

    return 0;
}
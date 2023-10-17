#include <stdio.h>

int main()
{
    int mark;

    printf("Please enter a mark: ");
    scanf("%d", &mark);

    if (mark < 0)
    {
        printf("Invalid mark\n");
    }
    else if (mark < 50)
    {
        printf("Fail\n");
    }
    else if (mark < 70)
    {
        printf("Pass\n");
    }
    else
    {
        printf("Distinction\n");
    }

    return 0;
}
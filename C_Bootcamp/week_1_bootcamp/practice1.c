#include <stdio.h>

int main()
{
    int length, width;

    printf("Input the rectangle's length and width separated by a space: ");
    scanf("%d%d", &length, &width);

    int area = length * width;

    printf("The area of the rectangle is: %d\n", area);

    return 0;
}
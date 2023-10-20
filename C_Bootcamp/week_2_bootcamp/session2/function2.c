#include <stdio.h>

float sum(float a, float b);

int main()
{
    float y = 2.12;
    float z = sum(5, y);

    printf("The sum of 5 and %.2f is %.2f\n", y, z);
}

float sum(float a, float b)
{
    return a + b;
}
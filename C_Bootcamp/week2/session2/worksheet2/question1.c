#include <stdio.h>
#include <math.h>

float circleArea(float radius)
{
    float area = M_PI * radius * radius;
    return area;
}


int main()
{
    float radius;
    printf("Please enter a radius: ");
    scanf("%f", &radius);

    printf("The area of a circle with radius %.2f is %.4f\n", radius, circleArea(radius));
    
    return 0;
}
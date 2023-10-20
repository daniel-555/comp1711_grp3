#include <stdio.h>
#include <math.h>

float sphereVolume(float radius)
{
    float volume = (4/3) * M_PI * radius * radius * radius;
    return volume;
}


int main()
{
    float radius;
    printf("Please enter a radius: ");
    scanf("%f", &radius);

    printf("The volume of a sphere with radius %.2f is %.4f\n", radius, sphereVolume(radius));
    
    return 0;
}
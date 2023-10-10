#include <stdio.h>
#include <limits.h>
#include <math.h>


// For Question 8
int factorial(int n)
{
    if (n == 1) return 1;
    return n * factorial(n-1);
}


int main()
{
    // Question 1
    // printf("Hello, World!");

    // Question 2
    // int num1, num2;
    // scanf("%d%d", &num1, &num2);
    // printf("%d", num1+num2);

    // Question 3
    // printf("Int: %d\n", INT_MAX);
    // printf("Long: %ld\n", LONG_MAX);
    // printf("Char: %d\n", CHAR_MAX);

    // Question 4
    // float radius;
    // printf("Radius: ");
    // scanf("%f", &radius);
    // printf("Area: %f", M_PI * (radius*radius));

    

    // Question 5
    // int num1, num2;
    // scanf("%d%d", &num1, &num2);
    // printf("num1 is %d and num2 is %d\n", num1, num2);
    // int temp = num1;
    // num1 = num2;
    // num2 = temp;

    // printf("num1 is now %d and num2 is %d", num1, num2);

    // Question 6
    // int number;
    // scanf("%d", &number);

    // if (number % 2 == 0)
    // {
    //     printf("The number is even");
    // } 
    // else
    // {
    //     printf("The number is odd");
    // }

    // Question 8
    // int number;
    // scanf("%d", &number);
    // printf("The factorial of %d is %d", number, factorial(number));

    // Question 9
    long speedOfLight = 299792458;
    int days;
    scanf("%d", &days);
    
    long seconds = days * 24 * 3600;
    long distance = seconds * speedOfLight;


    printf("In %d days light travels %ld metres", days, distance);

    printf("\n");
    return 0;
}
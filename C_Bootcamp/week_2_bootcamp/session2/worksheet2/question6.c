#include <stdio.h>

float arithmetic(float num1, float num2, char operation)
{
    switch (operation)
    {
        case '-': return num1-num2;
        case '*': return num1*num2;
        case '/': return num1/num2;
        default: printf("Invalid input for operator, defaulting to addition\n");
        case '+': return num1+num2;
    }
}

int main()
{
    float num1, num2;
    char operator;

    printf("Please enter 2 numbers followed by an operator (+,-,*,/)\n>>> ");
    scanf("%f %f %c", &num1, &num2, &operator);

    float result = arithmetic(num1, num2, operator);

    printf("The result of the calculation is %f\n", result);

    return 0;
}
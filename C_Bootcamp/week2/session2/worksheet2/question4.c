#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n)
{
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);

    bool numberIsPrime = isPrime(number);
    if (numberIsPrime)
    {
        printf("The number is prime\n");
    }
    else
    {
        printf("The number is not prime\n");
    }

    return 0;
}
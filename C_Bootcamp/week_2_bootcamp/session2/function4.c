#include <stdio.h>

float fahr_to_celsius (float f_temp)
{
    float c_temp;
    c_temp = (f_temp - 32)/1.8;
    return c_temp;
}

float fahr_to_kelvin (float f_temp)
{
    float k_temp;
    k_temp = fahr_to_celsius(f_temp) + 273.15;
    return k_temp;
}

int main()
{
    float fahrenheit;
    char option;

    printf("Enter a temperature to convert in Fahrenheit: ");
    scanf("%f", &fahrenheit);

    printf("\n");
    printf("Select A to convert to Celsius\nSelect B to convert to Kelvin\nSelect Q to quit\n>>> ");

    scanf(" %c", &option);

    switch (option)
    {
        case 'A': printf("Converted to degrees Celsius: %f\n", fahr_to_celsius(fahrenheit));
                  break;
        
        case 'B': printf("Converted to Kelvin: %f\n", fahr_to_kelvin(fahrenheit));
                  break;

        case 'Q': printf("Exited\n");
                  break;

        default: printf("Invalid choice\n");
    }

    return 0;
}
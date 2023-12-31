#include <stdio.h>
#include <stdlib.h>
#include "../utils.h"

int main()
{
    char filename[] = "squares.dat";
    FILE *file = open_file(filename, "r");

    int max_length = 100;
    char line_buffer[max_length];

    int sum = 0, n = 0;

    while(fgets(line_buffer, max_length, file) != NULL)
    {
        sum += atoi(line_buffer);
        n++;
    }

    float mean = sum / n;

    printf("The mean of the first %d squares is %.2f\n", n, mean);

    fclose(file);
    return 0;
}
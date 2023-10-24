#include <stdio.h>
#include <stdlib.h>
#include "../utils.h"

int main()
{
    char filename[] = "numbers.dat";
    FILE *file = open_file(filename, "r");

    int max_length = 100;
    char line_buffer[max_length];

    float sum = 0;
    int n = 0;

    while (fgets(line_buffer, max_length, file) != NULL)
    {
        sum += atof(line_buffer);
        n++;
    }
    fclose(file);
    file = open_file(filename, "a");

    float mean = sum / n;
    fprintf(file, "%f\n", mean);

    fclose(file);
    return 0;
}
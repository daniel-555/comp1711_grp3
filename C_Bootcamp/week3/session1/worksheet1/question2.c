#include <stdio.h>
#include <stdlib.h>
#include "../utils.h"

int main()
{
    char filename[] = "squares.dat";
    FILE *file = open_file(filename, "r");

    int count = 0;
    int max_length = 100;
    char line_buffer[max_length];
    
    while(fgets(file, ))

    fclose(file);
    return 0;
}
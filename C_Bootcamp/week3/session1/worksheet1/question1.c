#include <stdio.h>
#include "../utils.h"

int main() 
{
    char filename [] = "squares.dat";
    FILE *file = open_file(filename, "w");

    int n;
    printf("How many squares should be written to the file?: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        int square = i * i;
        fprintf(file, "%d\n", square);
    }

    fclose(file);
    return 0;
}
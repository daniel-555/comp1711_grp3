#include <stdio.h>

int main()
{
    // User picks a colour
    char colour;

    printf("1 - red\n2 - orange\n3 - yellow\n4 - green\n5 - blue\n");
    printf("(r,o,y,g,b): ");

    scanf("%c", &colour);

    switch (colour)
    {
        case 114: 
        printf("You picked red\n");
        break;

        case 111: 
        printf("You picked orange\n");
        break;
        
        case 121:
        printf("You picked yellow\n");
        break;

        case 103:
        printf("You picked green\n");
        break;

        case 98:
        printf("You picked blue\n");
        break;

        default:
        printf("That isn't an option\n");
    }

    return 0;
}

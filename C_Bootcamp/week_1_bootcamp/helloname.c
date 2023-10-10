#include <stdio.h>

int main()
{
    char name[15];
    
    printf("What is your name?: ");
    fgets(name, 15, stdin);
    printf("Hello %s", name);

    return 0;

}
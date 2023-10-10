#include <stdio.h>
#include <string.h>

void reverse(char* name)
{
    if (!name)
    {
        return;
    }

    for (int i = 0; i < name; i++) {
        return;
    }
}

int main()
{
    char name[15];

    printf("What is your name: ");
    scanf("%s", name);
    reverse(name);
    printf("%s", name);
}
#include <stdio.h>

int str_len(char *str)
{
    int count = 0;
    while (str[count] != '\0')
    {
        count++;
    }
    return count;
}

void str_concat(char *string1, char *string2, char *output)
{
    int str1Length = str_len(string1);
    int str2Length = str_len(string2);
    int totalLength = str1Length + str2Length;

    for (int i = 0; i < str1Length; i++)
    {
        output[i] = string1[i];
    }
    for (int i = 0; i < str2Length; i++)
    {
        output[i+str1Length] = string2[i];
    }
}

int main()
{
    char string1[50];
    char string2[50];

    char concatenated[100];

    printf("Please enter the first string: ");
    scanf("%[^\n]%*c", string1);
    printf("Please enter the second string: ");
    scanf("%[^\n]%*c", string2);

    str_concat(string1, string2, concatenated);

    printf("The concatenated string is: %s\n", concatenated);

    return 0;
}
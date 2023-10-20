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

char* str_concat(char *string1, char *string2)
{
    int str1Length = str_len(string1);
    int str2Length = str_len(string2);
    int totalLength = str1Length + str2Length;
    char output[totalLength];
}

int main()
{

}
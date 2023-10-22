#include <stdio.h>

void reverseArray(int *arr, int arrLength)
{
    int tempArr[arrLength];

    for (int i = 0; i < arrLength; i++)
    {
        tempArr[arrLength-(i+1)] = arr[i];
    }
    for (int i = 0; i < arrLength; i++)
    {
        arr[i] = tempArr[i];
    }
}

int main()
{
    int arrLength = 10;
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    reverseArray(array, arrLength);

    printf("The reversed array is: ");
    for (int i = 0; i < arrLength; i++)
    {
        printf("%i ", array[i]);
    }
    printf("\n");
}
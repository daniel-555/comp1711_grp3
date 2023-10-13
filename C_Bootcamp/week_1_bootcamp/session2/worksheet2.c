#include <stdio.h>

int main()
{
    // Exercise 1
    // int arr[5] = {1, 2, 3, 4, 5};
    // int sum = 0;
    // for (int i = 0; i < 5; i++)
    // {
    //    sum += arr[i]; 
    // }
    // printf("%d\n", sum);

    // Exercise 2
    // int arr[5] = {1, 2, 3, 4, 5};
    // int reversedArr[5];
    // for (int i = 0; i < 5; i++)
    // {
    //     reversedArr[4-i] = arr[i];
    // }
    // for (int i = 0; i < 5; i++)
    // {
    //     printf("%d\n", reversedArr[i]);
    // }

    // Exercise 3
    // int arr[5] = {1, 5, 2, 6, 4};
    // int max = arr[0];
    // for (int i = 1; i < 5; i++)
    // {
    //     if (arr[i] > max)
    //     {
    //         max = arr[i];
    //     }
    // }
    // printf("%d\n", max);

    // Exercise 4
    // int arr[5] = {1, 2, 3, 4, 5};
    // int temp = arr[0];
    // for (int i = 4; i >= 0; i--)
    // {
    //     arr[(i+1)%5] = arr[i];
    // }
    // arr[1] = temp;
    // for(int i = 0; i < 5; i++) 
    // {
    //     printf("%d\n", arr[i]);
    // }

    // Exercise 5
    // int arr[6] = {3, 3, 2, 1, 2, 5};
    // int found[6];

    // for (int i = 0; i < 6; i++)
    // {
    //     for (int j = i+1; j < 6; j++)
    //     {
    //         if (arr[i] == arr[j])
    //         {
                
    //             int isFound = 0;
    //             for (int k = 0; k < 6; k++)
    //             {
    //                 if (found[k] == arr[i])
    //                 {
    //                     isFound = 1;
    //                     break;
    //                 }
    //             }
    //             found[i] = arr[i];
    //             if (isFound == 0)
    //             {
    //                 printf("%d\n", arr[i]);
    //             }
    //         }
            
    //     }
    // }


    // Exercise 6
    int arr1[3] = {1, 2, 3};
    int arr2[3] = {4, 5, 6};

    int newArr[6];

    for (int i = 0; i < 3; i++)
    {
        newArr[i] = arr1[i];
    }
    for (int i = 3; i < 6; i++)
    {
        newArr[i] = arr2[i%3];
    }

    for (int i = 0; i < 6; i++)
    {
        printf("%d ", newArr[i]);
    }
    printf("\n");

    return 0;
}
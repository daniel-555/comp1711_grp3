#include <stdio.h>
#include <string.h>

#include "lib/FitnessDataStruct.h"

// Global variables
char *fileName = "FitnessData_2023.csv";
FITNESS_DATA fitnessData[1000];

char selectOption()
{
    printf("\nPlease select an option:\n");
    printf("\tA - Specify the file to be imported, the current loaded file is '%s'\n\t    (new file must be of '.csv' format)\n", fileName);
    printf("\tB - Display the file's total number of records\n");
    printf("\tC - Find the date and time of the timeslot with the fewest number ofsteps\n");
    printf("\tD - Find the date and time of the timeslot with the largest number of steps\n");
    printf("\tE - Find the mean step count of all the records in the file\n");
    printf("\tF - Find the longest continuous period where the step count is over 500\n");
    printf("\tQ - Quit the program\n");
    printf(">>> ");

    char selection;
    scanf(" %c", &selection);
    return selection;
}

int main() {
    // Open file initially
    FILE *file = openFile(fileName, "r");
    int numRecords = getNumRecords(file);
    parseFitnessData(file, numRecords, fitnessData);

    while (1 == 1)
    {
        char selection = selectOption();

        switch (selection)
        {
            case 'A':
            {
                char newFileName[25];
                printf("Input filename: ");
                scanf("%s", newFileName);
                if (fileIsValid(newFileName) == 1)
                {
                    fileName = newFileName;
                    fclose(file);
                    file = openFile(fileName, "r");
                    numRecords = getNumRecords(file);
                    parseFitnessData(file, numRecords, fitnessData);
                    printf("Opened file updated\n");
                }
                break;
            }

            case 'B':
                printf("Total records: %d\n", numRecords);
                break;

            case 'C':
            {
                int min = 0;
                int fewestSteps = fitnessData[0].steps;

                for (int i = 1; i < numRecords; i++)
                {
                    if (fitnessData[i].steps < fewestSteps)
                    {
                        fewestSteps = fitnessData[i].steps;
                        min = i;
                    }
                }
                printf("Fewest steps: %s %s\n", fitnessData[min].date, fitnessData[min].time);
                break;
            }
            case 'D':
            {
                int max = 0;
                int mostSteps = fitnessData[0].steps;

                for (int i = 1; i < numRecords; i++)
                {
                    if (fitnessData[i].steps > mostSteps)
                    {
                        mostSteps = fitnessData[i].steps;
                        max = i;
                    }
                }
                printf("Largest steps: %s %s\n", fitnessData[max].date, fitnessData[max].time);
                break;
            }
            case 'E':
            {
                int total = 0;
                float mean;
                for (int i = 0; i < numRecords; i++)
                {
                    total += fitnessData[i].steps;
                }
                mean = total / numRecords;
                printf("Mean step count: %.2f\n", mean);
                break;
            }
            case 'F':
            {
                int start = 0, end = 0;
                int currentStart = 0, currentEnd = 0, length = 0;

                for (int i = 0; i < numRecords; i++)
                {
                    if (fitnessData[i].steps > 500)
                    {
                        currentEnd = i;
                        if (length == 0) 
                        {
                            currentStart = i;
                        }
                        length++;
                    }
                    else
                    {
                        length = 0;
                    }
                    // Check that the current sequence is longer than the already stored sequence
                    // the '=' part makes sure that the current starts and ends are always swapped so they are the most up to date
                    if (currentEnd - currentStart >= end - start)
                    {
                        start = currentStart;
                        end = currentEnd;
                    }
                    
                }
                printf("Longest period start: %s %s\n", fitnessData[start].date, fitnessData[start].time);
                printf("Longest period end: %s %s \n", fitnessData[end].date, fitnessData[end].time);

                break;
            }
            case 'Q':
            {
                return 0;
            }
            default:
                printf("Invalid input\n");
            }
    }

    // Calculates the length of the array through pointer arithmetic

    return 0;
}
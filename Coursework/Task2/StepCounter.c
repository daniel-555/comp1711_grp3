#include <stdio.h>
#include <string.h>
#include <math.h>

#include "FitnessDataStruct.h"

// Global variables
char fileName[50];
FITNESS_DATA fitnessData[1000];
int numRecords = 0;

char selectOption()
{
    printf("\nMenu Options:\n");
    printf("A: Specify the filename to be imported\n");
    printf("B: Display the total number of records in the file\n");
    printf("C: Find the date and time of the timeslot with the fewest steps\n");
    printf("D: Find the date and time of the timeslot with the largest number of steps\n");
    printf("E: Find the mean step count of all the records in the file\n");
    printf("F: Find the longest continuous period where the step count is over 500\n");
    printf("Q: Quit the program\n");
    printf("Enter choice: ");

    char selection;
    scanf(" %c", &selection);
    return selection;
}

int main() {
    while (1 == 1)
    {
        char selection = selectOption();

        switch (selection)
        {
            case 'A':
            {
                printf("Input filename: ");
                scanf("%s", fileName);
                if (fileIsValid(fileName) == 1)
                {
                    FILE *file = openFile(fileName, "r");
                    getFitnessData(file, fitnessData, &numRecords);
                    printf("Opened file updated\n");
                    fclose(file);
                }
                else 
                {
                    return 1;
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
                float mean = 0;
                for (int i = 0; i < numRecords; i++)
                {
                    mean += fitnessData[i].steps;
                }
                mean /= numRecords;

                printf("Mean step count: %.0f\n", round(mean));
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
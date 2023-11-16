#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char date[11];
    char time[6];
    int steps;
} FitnessData;

// Global Variables
char fileName[50] = "FitnessData.csv";
FitnessData fitnessRecords[1000];
int numRecords;

// Function to tokenize a record
void tokeniseRecord(char *record, char delimiter, char *date, char *time, int *steps) {
    char *ptr = strtok(record, &delimiter);
    if (ptr != NULL) {
        strcpy(date, ptr);
        ptr = strtok(NULL, &delimiter);
        if (ptr != NULL) {
            strcpy(time, ptr);
            ptr = strtok(NULL, &delimiter);
            if (ptr != NULL) {
                *steps = atoi(ptr);
            }
        }
    }
}

void getFitnessData(FILE *file, FitnessData *output, int *numRecords)
{
    FitnessData currentRecord;

    int maxLength = 100;
    char lineBuffer[maxLength];

    int count = 0;
    while(fgets(lineBuffer, maxLength, file) != NULL)
    {
        char date[11], time[6], steps[11];
        tokeniseRecord(lineBuffer, ',', currentRecord.date, currentRecord.time, &currentRecord.steps);

        output[count] = currentRecord;
        count++;
    }
    *numRecords = count;
}

int compFunc(const void * a, const void * b)
{
    return ((FitnessData *)b)->steps - ((FitnessData *)a)->steps;
}

int main()
{
    printf("Enter filename: ");
    scanf("%s", fileName);

    FILE *file = fopen(fileName, "r");
    if (file == NULL)
    {
        perror("");
        return 1;
    }

    getFitnessData(file, fitnessRecords, &numRecords);

    fclose(file);

    qsort(fitnessRecords, numRecords, sizeof(FitnessData), compFunc);

    // for (int i = 0; i < numRecords; i++)
    // {
    //     printf("%d\n", fitnessRecords[i].steps);
    // }

    char *newFileName = strtok(fileName, ".");
    strcat(newFileName, ".tsv");

    // printf("%s\n", newFileName);

    file = fopen(newFileName, "w");

    for (int i = 0; i < numRecords; i++)
    {
        fprintf(file, "%s\t%s\t%d\n", fitnessRecords[i].date, fitnessRecords[i].time, fitnessRecords[i].steps);
    }

    fclose(file);
    // printf("%s, %s, %d\n", fitnessRecords[0].date, fitnessRecords[].time, fitnessRecords[0].steps);

    // void *a = fitnessRecords+1;
    // void *b = fitnessRecords;

    // // printf("%d %d\n", fitnessRecords[0].steps, fitnessRecords[1].steps);
    // printf("%d\n", compFunc(a, b));
    return 0;
}
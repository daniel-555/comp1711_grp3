#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char date[11];
    char time[6];
    int steps;
} FitnessData;

// Global Variables
char fileName[50];
FitnessData fitnessRecords[1000];
int numRecords;

// Function to tokenize a record
// Returns 0 if executed properly or 1 if date/time is missing
int tokeniseRecord(char *record, char delimiter, char *date, char *time, char *steps) {
    int i = 0;

    char *ptr = strtok(record, &delimiter);
    if (ptr != NULL) {
        // Check that the date is the valid length and has dashes at the expected places
        while (*(ptr+i) != '\0') i++;
        if (i != 10)
        {
            return 1;
        }
        if (ptr[4] != '-' || ptr[7] != '-')
        {
            return 1;
        }

        strcpy(date, ptr);
        ptr = strtok(NULL, &delimiter);
        if (ptr != NULL) {
            // Check that the time is the expected length and has a colon in the expected place
            i = 0;
            while (*(ptr + i) != '\0') i++;
            if (i != 5)
            {
                return 1;
            }
            if (ptr[2] != ':')
            {
                return 1;
            }

            strcpy(time, ptr);
            ptr = strtok(NULL, &delimiter);
            if (ptr != NULL) {
                strcpy(steps, ptr);
                return 0;
            }
        }
    }
    return 1;
}

// Parses fitness data into an array of structs
void getFitnessData(FILE *file, FitnessData *output, int *numRecords)
{
    FitnessData currentRecord;

    int maxLength = 100;
    char lineBuffer[maxLength];

    int count = 0;
    while(fgets(lineBuffer, maxLength, file) != NULL)
    {
        char date[11], time[6], steps[11];
        int recordValidFormat = tokeniseRecord(lineBuffer, ',', date, time, steps);

        if (recordValidFormat == 1)
        {
            printf("File is not in the expeted format\n");
            exit(1);
        }

        // Map the date time and steps to the currentRecord buffer
        strcpy(currentRecord.date, date);
        strcpy(currentRecord.time, time);
        currentRecord.steps = atoi(steps);

        // Add the currentRecord to the array for fitnessData
        output[count] = currentRecord;
        count++;
    }
    *numRecords = count;
}

// Comparator function for the quicksort algorithm
int compFunc(const void * a, const void * b)
{
    return ((FitnessData *)b)->steps - ((FitnessData *)a)->steps;
}

int main()
{
    // Get the file name and open the file
    printf("Enter filename: ");
    scanf("%s", fileName);

    FILE *file = fopen(fileName, "r");
    if (file == NULL)
    {
        perror("");
        return 1;
    }

    // Parse data from the file into the fitnessRecords array
    getFitnessData(file, fitnessRecords, &numRecords);

    fclose(file);

    // Sort the records by steps in descending order
    qsort(fitnessRecords, numRecords, sizeof(FitnessData), compFunc);

    // Generate the new filename with the ".tsv" extension and open it
    strcat(fileName, ".tsv");

    file = fopen(fileName, "w");

    // Write all of the sorted records to the new file in the new format
    for (int i = 0; i < numRecords; i++)
    {
        fprintf(file, "%s\t%s\t%d\n", fitnessRecords[i].date, fitnessRecords[i].time, fitnessRecords[i].steps);
    }
    fclose(file);

    printf("Data sorted and written to %s\n", fileName);

    return 0;
}
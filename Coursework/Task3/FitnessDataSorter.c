#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
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
// Returns true if executed properly or false if in the incorrect format
bool tokeniseRecord(char *record, char delimiter, char *date, char *time, char *steps) {

    // 10 chars for date, 5 chars for time, 2 commas, and at least one digit for steps
    const int expectedMinLength = 18;
    
    if (strlen(record) < expectedMinLength)
    {
        return false;
    }

    // Extract date, time and steps
    if (sscanf(record, "%10[^,],%5[^,],%9s", date, time, steps) != 3)
    {
        return false;
    }


    // Check if the date time and steps are of the expected lengths
    if (strlen(date) != 10 || strlen(time) != 5 || strlen(steps) == 0)
    {
        return false;
    }

    // Check that the date and time are in the expected format
    if (date[4] != '-' || date[7] != '-' || time[2] != ':')
    {
        return false;
    }

    // Check that steps is actually an integer
    for (int i = 0; steps[i] != '\0'; i++)
    {
        if (!isdigit(steps[i]))
        {
            return false;
        }
    }

    // The record has been successfully tokenised
    return true;
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

        if (!tokeniseRecord(lineBuffer, ',', date, time, steps))
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
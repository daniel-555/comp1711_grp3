#include "FitnessDataStruct.h"

FILE *openFile(char *fileName, char *mode)
{
    FILE *file = fopen(fileName, mode);
    if (file == NULL) 
    {
        perror("");
        exit(1);
    }
    return file;
}

int fileIsValid(char *fileName)
{
    // Locate the last dot in the filename and compare the substring after it with the specified requirements
    const char *dot = strrchr(fileName, '.');
    if (dot == fileName || !dot || strcmp(dot+1, "csv") != 0)
    {
        printf("The file name isn't in the expected .csv format\n");
        return 0;
    }

    // Check that the file exists
    FILE *file = fopen(fileName, "r");
    if (file == NULL)
    {
        printf("The file specified does not exist\n");
        return 0;
    }

    fclose(file);
    return 1;
}

void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);
}

void parseFitnessData(FILE *file, int numRecords, FITNESS_DATA *output)
{
    FITNESS_DATA currentRecord;

    int maxLength = 100;
    char lineBuffer[maxLength];

    for (int i = 0; i < numRecords; i++)
    {
        char date[11], time[6], steps[11];
        fgets(lineBuffer, maxLength, file);
        tokeniseRecord(lineBuffer, ",", date, time, steps);

        strcpy(currentRecord.date, date);
        strcpy(currentRecord.time, time);
        currentRecord.steps = atoi(steps);
        output[i] = currentRecord;
    }
}

int getNumRecords(FILE *file)
{
    int numRecords = 0;

    int maxLength = 100;
    char lineBuffer[maxLength];

    while(fgets(lineBuffer, maxLength, file) != NULL)
    {
        numRecords++;
    }

    // Reset the pointer to the 1st line of the file
    rewind(file);
    return numRecords;
}
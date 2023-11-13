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

void getFitnessData(FILE *file, FITNESS_DATA *output, int *numRecords)
{
    FITNESS_DATA currentRecord;

    int maxLength = 100;
    char lineBuffer[maxLength];

    int count = 0;
    while(fgets(lineBuffer, maxLength, file) != NULL)
    {
        char date[11], time[6], steps[11];
        tokeniseRecord(lineBuffer, ",", date, time, steps);

        strcpy(currentRecord.date, date);
        strcpy(currentRecord.time, time);
        currentRecord.steps = atoi(steps);
        output[count] = currentRecord;
        count++;
    }
    *numRecords = count;
}
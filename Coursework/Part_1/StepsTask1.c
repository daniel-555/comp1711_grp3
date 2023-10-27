#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Define any additional variables here
const char fileName[] = "FitnessData_2023.csv";

// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
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

// Complete the main function
int main() { 
    // Open file
    FILE *file = fopen(fileName, "r");
    if (file == NULL)
    {
        perror("");
        return 1;
    }

    int numRecords = 0;

    int maxLength = 100;
    char lineBuffer[maxLength];

    while(fgets(lineBuffer, maxLength, file) != NULL)
    {
        numRecords++;
    }

    printf("Number of records in file: %d\n", numRecords);
    // Reset the pointer to the 1st line of the file
    rewind(file);

    FITNESS_DATA fitnessData[numRecords];
    FITNESS_DATA currentRecord;

    for (int i = 0; i < numRecords; i++)
    {
        char date[11], time[6], steps[6];
        fgets(lineBuffer, maxLength, file);
        tokeniseRecord(lineBuffer, ",", date, time, steps);

        strcpy(currentRecord.date, date);
        strcpy(currentRecord.time, time);

        currentRecord.steps = atoi(steps);

        fitnessData[i] = currentRecord;

        // Print first 3 records
        if (i < 3)
        {
            printf("%s/%s/%d\n", date, time, atoi(steps));
        }
    }

    return 0;
}

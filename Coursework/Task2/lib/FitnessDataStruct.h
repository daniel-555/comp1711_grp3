#ifndef FITNESSDATASTRUCT_H
#define FITNESSDATASTRUCT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char date[11];
    char time[6];
    unsigned steps;
} FITNESS_DATA;

FILE *openFile(char *fileName, char *mode);

int fileIsValid(char *fileName);

void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps);

void getFitnessData(FILE *file, FITNESS_DATA *output, int *numRecords);

#endif
//
// Created by SimonD on 3/3/2020.
//

#ifndef ASD_ESERCITAZIONE_01_TESTHELPER_H
#define ASD_ESERCITAZIONE_01_TESTHELPER_H

#include "models.h"
#include <stdlib.h>
#include <stdio.h>
#define MAX_RAND 100

// func prototypes
int* getGeneratedArrayOfIntegers(inputType, int );
int* _generateSortedArrayOfIntegers(int);
int* _generateSortedArrayOfIntegersDesc(int);
int* _generateRandomArrayOfIntegers(int);
int* _generatePartiallySortedData(int);

RecipieAndSize getArrayOfRecipesFromUser();
void printIntegerArray(int*, int);
void printRecipesArray(Ricetta*, int);
void freeTheBuffer();

#endif //ASD_ESERCITAZIONE_01_TESTHELPER_Hs

//
// Created by SimonD on 5/31/2020.
//

#ifndef INC_65879_DEMURO_SIMONE_TESTHELPER_H
#define INC_65879_DEMURO_SIMONE_TESTHELPER_H

#include <stdio.h>
#include <time.h>
#include "../Models/models.h"
#include "../SortEngine/selectionSortIter.h"
#include "../TestGenerator/dataGenerator.h"

report sortBenchmark(void (*sortAlgorithm)(int*,int,int*,int*), int* data, int size);
const char* getAlgorithmNameByIndex(int algorithmIndex);
const char* getSortingTypeNameByIndex(int algorithmIndex);
void conditionallyPrint(int dataSize, int isPrintEnabled, int *data);
int getNumericAnswerFromUser(int maxOptionAvailable);
//File
void nextLineOnFile();
void openFile();
void closeFile();

#endif //INC_65879_DEMURO_SIMONE_TESTHELPER_H

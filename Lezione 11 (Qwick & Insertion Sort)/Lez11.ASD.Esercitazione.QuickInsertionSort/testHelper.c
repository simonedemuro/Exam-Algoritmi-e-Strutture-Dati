//
// Created by SimonD on 6/1/2020.
//

#include "testHelper.h"

int* _generateRandomArrayOfIntegers(int size){
    int* data = (int*) malloc(sizeof(int) * size);

    for (int i = 0; i < size; ++i)
        data[i] = rand() % MAX_RAND;

    return data;
}

void printIntegerArray(int* data, int size){
    int i = 0;
    for (i = 0; i < size; ++i) {
        printf("[%d] --> %d\n", i, data[i]);
    }
}
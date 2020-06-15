//
// Created by demu9 on 3/13/2020.
//


#include <stdlib.h>
#include "testDataGeneration.h"


int* generateSortedArrayOfInt(int size){
    int* data = (int*) malloc(sizeof(int) * size);
    int i, increment = 0;

    data[0] = rand() % 10;
    for (i = 1; i < size; ++i) {
        increment = rand() % 10;
        data[i] = data[i-1] + increment;
    }

    return data;
}
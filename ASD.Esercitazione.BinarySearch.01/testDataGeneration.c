//
// Created by demu9 on 3/13/2020.
//


#include <stdlib.h>
#include "testDataGeneration.h"

/**
 * This will work as a private method to generate an array of integers of the given length
 * with random data inside
 * @param size is the array to be generated size
 * @return an array of int of the given size with random data
 */
int* _generateRandomArrayOfIntegers(int size){
    int* data = (int*) malloc(sizeof(int) * size);
    int i = 0;

    for (i = 0; i < size; ++i) {
        data[i] = rand() % MAX_RAND;
    }

    return data;
}
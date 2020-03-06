//
// Created by SimonD on 3/3/2020.
//

#include "testHelper.h"


int* getGeneratedArrayOfIntegers(inputType type, int size){
    switch (type){
        case ORDINATO:
            return _generateSortedArrayOfIntegers(size);
        case QUASI_ORDINATO:
            return _generatePartiallySortedData(size);
        case INV_ORDINATO:
            return _generateSortedArrayOfIntegersDesc(size);
        case CASUALE:
            return _generateRandomArrayOfIntegers(size);
        default:
            printf("Error inside  press a key to terminate");
            getchar();
            exit(-1);
    }
    return (void*) -1;
}

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
        data[i] = rand();
    }

    return data;
}

/**
 * This will work as a private method to generate an array of integers of the given length
 * with sorted data ( 0 to <size> )
 * @param size is the array to be generated size
 * @return an array of int of the given size with sorted data
 */
int* _generateSortedArrayOfIntegers(int size){
    int* data = (int*) malloc(sizeof(int) * size);
    int i = 0;

    for (i = 0; i < size; ++i) {
        data[i] = i;
    }

    return data;
}

/**
 * This will work as a private method to generate an array of integers of the given length
 * with reverse sorted data ( <size> to 0 )
 * @param size is the array to be generated size
 * @return an array of int of the given size with inverse sorted data
 */
int* _generateSortedArrayOfIntegersDesc(int size){
    int* data = (int*) malloc(sizeof(int) * size);
    int i ;

    for (i = 0; i < size ; ++i) {
        data[i] = size - i;
    }

    return data;
}

int* _generatePartiallySortedData(int size){
    int* data = (int*) malloc(sizeof(int) * size);
    int halfIdx = size / 2;
    int i;

    // generating random data for half of the array into firstHalfRandom
    int* firstHalfRandom = _generateRandomArrayOfIntegers(halfIdx);
    // copying the first half of random data into the array to be returned
    for (i = 0; i < halfIdx; ++i) {
        data[i] = firstHalfRandom[i];
    }
    // generating the rest of the data sequentially
    for (i = halfIdx; i < size; ++i) {
        data[i] = i;
    }
    return data;
}

void printIntegerArray(int* data, int size){
    int i = 0;
    for (i = 0; i < size; ++i) {
        printf("[%d] --> %d\n", i, data[i]);
    }
}
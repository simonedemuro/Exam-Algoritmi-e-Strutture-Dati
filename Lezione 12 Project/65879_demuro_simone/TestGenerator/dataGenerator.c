//
// Created by SimonD on 5/31/2020.
//

#include "dataGenerator.h"

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

/**
 * This will work as a private method to generate an array of integers of the given length
 * with sorted data ( 0 to <size> )
 * @param size is the array to be generated size
 * @return an array of int of the given size with sorted data
 */
int* _generateSortedArrayOfIntegers(int size){
    int* data = (int*) malloc(sizeof(int) * size);
    int i, increment = 0;

    data[0] = rand() % 10;
    for (i = 1; i < size; ++i) {
        increment = rand() % 10;
        data[i] = data[i-1] + increment;
    }

    return data;
}

/**
 * Generate an array of integers of the given length
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

/**
 * Generating partially sorted data
 * @param size array to be generated size
 * @return an array of partially sorted data e.g-> 1,3,4,2,7,10
 */
int* _generatePartiallySortedData(int size){
    int* data = (int*) malloc(sizeof(int) * size);
    int i, increment = 0;
    _Bool isOutbounder = false;
    data[0] = rand() % 10;

    // PROBABILITY to have an outbounder
    // if a random is divisible by n put a non sorted element in the collection
    isOutbounder = rand() % 9 == 0;

    for (i = 1; i < size; ++i) {
        // (possibly) NON SORTED ELEMENT
        if(isOutbounder){
            data[i] = rand() % MAX_RAND;
        }
        // SORTED ELEMENT
        else{
            increment = rand() % 10;
            data[i] = data[i-1] + increment;
        }
    }

    return data;
}

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
}

/**
 * For debugging purposes prints an array of integers
 * @param data array to be printed
 * @param size number of elements in the array
 */
void printIntegerArray(int* data, int size){
    int i = 0;
    for (i = 0; i < size; ++i) {
        printf("[%d] --> %d\n", i, data[i]);
    }
}

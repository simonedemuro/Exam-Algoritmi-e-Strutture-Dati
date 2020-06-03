#include <stdio.h>
#include "testHelper.h"
#include "insertionSort.h"
#include "quickSort.h"

// Please change to feet the desired input size
#define N_ELEM 10
#define SWITCH_ALGORITHM_THRESHOLD 3

int main() {
    // TEST SETUP
    int* intArray = _generateRandomArrayOfIntegers(N_ELEM);
    printf("Before sorting:\n");
    printIntegerArray(intArray, N_ELEM);

    // SORTING: please uncomment the Algorithm to test
    insertionSort(intArray,N_ELEM);
//    quickSort(intArray, 0, N_ELEM);
//    quickInsertionSort(intArray, 0, N_ELEM-1,SWITCH_ALGORITHM_THRESHOLD);

    // ASSERT: the array looks sorted
    printf("\nAfret sorting:");
    printIntegerArray(intArray, N_ELEM);

    return 0;
}


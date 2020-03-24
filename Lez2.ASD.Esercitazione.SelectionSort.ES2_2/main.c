#include <stdio.h>
#include "models.h"
#include "selectionSort.h"
#include "testHelper.h"
#define SIZES_TO_BE_TESTED 6

int main() {
    // please set the data to be sorted size below:
    int dataSize[] =  {100, 1000, 10000, 100000, 200000, 500000};
    int* data = NULL;

    // This for makes the Selection Sort run for several different dimensions
    int i = 0;
    for (i = 0; i < SIZES_TO_BE_TESTED; ++i) {
        // Running and printing debug info for Selection Sort Recursive
        data= getGeneratedArrayOfIntegers(CASUALE, dataSize[i]);
        debugSelectionSort(RECURSIVE, data, dataSize[i]);

        // Running and printing debug info for Selection Sort Iterative
        data = getGeneratedArrayOfIntegers(CASUALE, dataSize[i]);
        debugSelectionSort(ITERATIVE, data, dataSize[i]);
        printf("+----------------------------------------------------\n");
    }


    return 0;
}
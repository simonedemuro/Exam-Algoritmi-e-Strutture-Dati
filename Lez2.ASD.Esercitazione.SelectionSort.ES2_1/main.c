#include <stdio.h>
#include "models.h"
#include "selectionSort.h"
#include "testHelper.h"

int main() {
    // please set the data to be sorted size below:
    int dataSize = 100000;
    int* data = NULL;

    data= getGeneratedArrayOfIntegers(CASUALE, dataSize);
    debugSelectionSort(RECURSIVE, data, dataSize);

    data = getGeneratedArrayOfIntegers(CASUALE, dataSize);
    debugSelectionSort(ITERATIVE, data, dataSize);

    return 0;
}
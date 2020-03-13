//
// Created by demu9 on 3/13/2020.
//

#include "selectionSort.h"

/**
 * Wrapper for selection sort, but metered
 * @param data
 * @param size
 */
void debugSelectionSort(int* data, int size){
    // Init performance measure
    clock_t start, stop;
    double elapsedSeconds;
    start = clock();

    // running actual sort
    selectionSort(data, size);

    // stop sort and print milliseconds
    stop = clock();
    elapsedSeconds = ((double) (stop - start)) / CLOCKS_PER_SEC;
    printf("Selection Sort for %d items took: %lf sec\n",size, elapsedSeconds);
}

void selectionSort(int* data, int size){
    int minIdx;
    for (int i = 0; i < size - 1; ++i) {
        minIdx = i;
        for (int j = i+1; j < size ; ++j) {
            if (data[j] < data[minIdx]){
                minIdx = j;
            }
        }
        swap(&data[minIdx], &data[i]);
    }
}

void swap(int* a, int*b )
{
    int tmp = *b;
    *b = *a;
    *a = tmp;
}

//
// Created by SimonD on 5/31/2020.
//

#include "selectionSortIter.h"

void swap(int* a, int*b)
{
    int tmp = *b;
    *b = *a;
    *a = tmp;
}

void selectionSort(int* data, int size, int* nCompare, int* nSwap){
    int minIdx = 0;
    *nCompare = *nSwap = 0;

    for (int i = 0; i < size - 1; ++i) {
        minIdx = i;
        for (int j = i+1; j < size ; ++j) {
            (*nCompare)++;
            if (data[j] < data[minIdx]){
                minIdx = j;
            }
        }
        swap(&data[minIdx], &data[i]);
        (*nSwap)++;
    }
}

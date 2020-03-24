//
// Created by SimonD on 3/24/2020.
//

#ifndef ASD_ESERCITAZIONE_SELECTIONSORT_02_SELECTIONSORT_H
#define ASD_ESERCITAZIONE_SELECTIONSORT_02_SELECTIONSORT_H
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "models.h"

void selectionSortRec(int* data, int size, int startAt);
int findMin(int* data, int minIdx, int startAt, int size);
void swap(int* a, int*b );
void debugSelectionSort(sortType type, int* data, int size);
void selectionSortIter(int* data, int size);

#endif //ASD_ESERCITAZIONE_SELECTIONSORT_02_SELECTIONSORT_H

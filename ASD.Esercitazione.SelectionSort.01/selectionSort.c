//
// Created by SimonD on 3/3/2020.
//

#include <time.h>
#include "selectionSort.h"
#include "models.h"
#include <stdio.h>

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

//algoritmo selectionSort(array A, int n)
//for i ← 0 to n-2 do
//min ← i
//for j ← i+1 to n-1 do
//if (A[j] < A[min]) then min ← j
//        scambia A[min] con A[i]
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

void selectionSortRecepies(Ricetta* data, int size){
    int minIdx;
    for (int i = 0; i < size - 1; ++i) {
        minIdx = i;
        for (int j = i+1; j < size ; ++j) {
            if ( compareRecepies(data[minIdx], data[j]) ){
                minIdx = j;
            }
        }
        swapRecepies(&data[minIdx], &data[i]);
    }
}

/** sorting by time and difficulty as tiebreaker
 * Return 0 r1 < r2
 *        1 otherwise
 */
int compareRecepies(Ricetta r1, Ricetta r2){
    if(r1.tempo < r2.tempo)
        return 0;
    if(r1.tempo == r2.tempo && r1.difficolta < r2.difficolta)
        return 0;
    return 1;
}

void swap(int* a, int*b )
{
    int tmp = *b;
    *b = *a;
    *a = tmp;
}

void swapRecepies(Ricetta* a, Ricetta* b )
{
    Ricetta tmp = *b;
    *b = *a;
    *a = tmp;
}



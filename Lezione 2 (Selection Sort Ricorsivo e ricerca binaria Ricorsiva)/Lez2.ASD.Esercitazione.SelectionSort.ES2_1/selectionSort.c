//
// Created by SimonD on 3/24/2020.
//


#include "selectionSort.h"
#include "models.h"

void debugSelectionSort(sortType type, int* data, int size){
    // Init performance measure
    clock_t start, stop;
    double elapsedSeconds;
    start = clock();

    // running actual sort
    if(type == RECURSIVE)
        selectionSortRec(data, size, 0);
    else if (type == ITERATIVE)
        selectionSortIter(data, size);


    // stop sort and print milliseconds
    stop = clock();
    elapsedSeconds = ((double) (stop - start)) / CLOCKS_PER_SEC;

    printf( type==RECURSIVE?"RECURSIVE - ":"ITERATIVE - " );
    printf("Selection Sort for %d items took: %lf sec\n",size, elapsedSeconds);
}

//algoritmo selectionSortRec(array A, int dimA, int start)
//if (start >= dimA-1) then
//return
//minIndex ← findmin(array A, start, start+1, dimA)
//scambia A[minIndex] con A[start]
//selectionSortRec(A, dimA, start+1)

void selectionSortRec(int* data, int size, int startAt){
    if(startAt >= size-1)
        return;
    int minIndex = findMin(data, startAt, startAt+1, size);
    swap(&data[minIndex], &data[startAt]);
    selectionSortRec(data, size, startAt+1);
}


//algoritmo findmin (array A, int minpos, int start, int dim) → intero
//if (start == dim) then
//return minpos
//if (A[start] < A[minpos]) then
//        minpos ← start
//return findmin(array, minpos, start+1, dim)

int findMin(int* data, int minIdx, int startAt, int size){
    if (startAt == size)
        return minIdx;
    if (data[startAt] < data[minIdx])
        minIdx = startAt;
    return findMin(data, minIdx, startAt+1, size);
}

void selectionSortIter(int* data, int size){
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

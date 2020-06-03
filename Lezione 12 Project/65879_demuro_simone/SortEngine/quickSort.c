//
// Created by SimonD on 5/31/2020.
//

#include "quickSort.h"

void qswap(int *vett, int i, int j) {
    int tmp = vett[j];
    vett[j] = vett[i];
    vett[i] = tmp;
}

int perno(int lista[], int primo, int ultimo, int* nCompare, int* nSwap) {
    int i = primo;
    int j = ultimo + 1;
    int pivot = lista[primo];
    while (i < j) {
        do {
            i = i + 1;
            (*nCompare)++;
        } while (lista[i] <= pivot && i <= ultimo);
        do {
            j = j - 1;
            (*nCompare)++;
        } while (lista[j] > pivot && j >= primo);
        if (i < j) {
            (*nSwap)++;
            qswap(lista, i, j);
        }
    }
    (*nSwap)++;
    qswap(lista, primo, j);
    return j;
}

void quickSort(int lista[], int u, int v, int* nCompare, int* nSwap) {
    int q = 0;
    if (u == v) { return; }
    q = perno(lista, u, v, nCompare, nSwap);
    if (u < q) {
        quickSort(lista, u, q-1, nCompare, nSwap);
    }
    if (q < v) {
        quickSort(lista, q + 1, v, nCompare, nSwap);
    }
}

/**
 * In order to keep the same signature of the other Sorting algorithm,
 * quickSortPublic wraps quickSort
 */
void quickSortPublic(int* data, int size, int* compare, int* swap){
    quickSort(data, 0, size-1, compare, swap);
}

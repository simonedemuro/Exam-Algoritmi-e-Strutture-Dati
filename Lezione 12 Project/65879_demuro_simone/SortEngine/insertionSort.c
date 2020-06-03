//
// Created by SimonD on 5/31/2020.
//

#include "insertionSort.h"


void insertionSort(int lista[], int dim, int* nCompare, int* nSwap) {
    int i = 0, j = 0;
    int prossimo = 0;
    for (i = 1; i < dim; i++) {
        prossimo = lista[i];
        for (j = i - 1; j > 0; j--) {
            (*nCompare)++;
            if (prossimo < lista[j]) {
                (*nSwap)++;
                lista[j + 1] = lista[j];
            } else {
                break;
            }
        }
        lista[j + 1] = prossimo;
    }
}

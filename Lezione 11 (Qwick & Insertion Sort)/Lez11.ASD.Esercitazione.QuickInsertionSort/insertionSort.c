//
// Created by SimonD on 6/1/2020.
//

#include "insertionSort.h"

void insertionSort(int lista[], int dim) {
    int i = 0, j = 0;
    int prossimo = 0;
    for (i = 1; i < dim; i++) {
        prossimo = lista[i];
        for (j = i - 1; j > 0; j--) {
            if (prossimo < lista[j]) {
                lista[j + 1] = lista[j];
            } else {
                break;
            }
        }
        lista[j + 1] = prossimo;
    }
}

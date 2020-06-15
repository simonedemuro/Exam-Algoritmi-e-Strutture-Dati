//
// Created by SimonD on 6/1/2020.
//

#include "quickSort.h"

void swap(int *vett, int i, int j) {
    int swap=0;
    swap=vett[j];
    vett[j] = vett[i];
    vett[i] = swap;
}

int perno(int lista[], int primo, int ultimo) {
    int i = primo;
    int j = ultimo + 1;
    int pivot = lista[primo];
    while (i < j) {
        do {
            i = i + 1;
        } while (lista[i] <= pivot && i <= ultimo);
        do {
            j = j - 1;
        } while (lista[j] > pivot && j >= primo);
        if (i < j) {
            swap(lista, i, j);
        }
    }
    swap(lista, primo, j);
    return j;
}

void quickSort(int lista[], int u, int v) {
    int q = 0;
    if (u == v) { return; }
    q = perno(lista, u, v);
    if (u < q) {
        quickSort(lista, u, q-1);
    }
    if (q < v) {
        quickSort(lista, q + 1, v);
    }
}


void insertionSortMod(int *data, int from, int to) {
    int i = 0, j = 0;
    int prossimo = 0;
    for (i = from; i < to; i++) {
        prossimo = data[i];
        for (j = i - 1; j > 0; j--) {
            if (prossimo < data[j]) {
                data[j + 1] = data[j];
            } else {
                break;
            }
        }
        data[j + 1] = prossimo;
    }
}


void quickInsertionSort(int data[], int fromIdx, int toIdx, int swithcAlgoritmThreshold) {
    int q = 0;
    //if (fromIdx == toIdx) { return; }

    // If I get beyond the threshold, continue sorting by Insertion Sort
    if (swithcAlgoritmThreshold >= toIdx - fromIdx ){
        insertionSortMod(data, fromIdx, toIdx);
        return;
    }

    // Handling normal QuickSort Algorithm
    q = perno(data, fromIdx, toIdx);
    if (fromIdx < q) {
        quickSort(data, fromIdx, q - 1);
    }
    if (q < toIdx) {
        quickSort(data, q + 1, toIdx);
    }
}

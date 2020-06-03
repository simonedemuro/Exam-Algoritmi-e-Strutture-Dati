//
// Created by SimonD on 5/31/2020.
//

#include "mergeSort.h"
#include <stdlib.h>

void merge(int lista[], int ordinata[], int i, int m, int n, int* compare, int* swap) {
    int j = m + 1; // indice per la seconda parte di lista
    int t = 0;
    int k = i; // indice per la lista ordinata
    int pos_iniziale = i; //posizione iniziale nella lista
    while (i <= m && j <= n){
        (*compare)++;
        (*swap)++;
        if (lista[i] <= lista[j]) {
            ordinata[k] = lista[i];
            i++;
            k++;
        } else {
            ordinata[k] = lista[j];
            j++;
            k++;
        }
    }

    if (i > m) {
        // ordinata[k],..., ordinata[n] ← lista[j],..., lista[n]
        if (j>n){j--;}
        for (t = j; t <= n; t++) {
            (*swap)++;
            ordinata[k + t - j] = lista[t];
        }
    } else {
        // ordinata[k],..., ordinata[n] ← lista[i],..., lista[m]
        for (t = i; t <= m; t++) {
            (*swap)++;
            ordinata[k + t - i] = lista[t];
        }
    }
    for (; pos_iniziale <= n; ++pos_iniziale) {
        (*swap)++;
        t = ordinata[pos_iniziale];
        lista[pos_iniziale] = t;
    }
}


void  mergeSort(int lista[], int ordinata[], int lower, int upper, int* compare, int* swap) {
    int medium = 0;
    if (lower >= upper) {
        return;
    }
    medium = (lower + upper) / 2;
    mergeSort(lista, ordinata, lower, medium, compare, swap);
    mergeSort(lista, ordinata, medium + 1, upper, compare, swap);
    merge(lista, ordinata, lower, medium, upper, compare, swap);
}

void mergeSortP(int lista[], int n, int* compare, int* swap){
    int* sortedList = malloc(sizeof(int)*n);
    mergeSort(lista, sortedList, 0, n-1, compare, swap);
    lista = sortedList;
}



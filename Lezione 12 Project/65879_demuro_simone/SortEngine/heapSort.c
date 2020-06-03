//
// Created by SimonD on 5/31/2020.
//

#include "heapSort.h"
#include "quickSort.h"

void adatta(int lista[], int radice, int n, int* compare, int* swap) {
    int temp = lista[radice];
    int figlio = 0;
    figlio = 2 * radice; // figlio sx
    while (figlio <= n) {
        (*compare)++;
        // trova il maggiore tra il figlio sx e figlio dx
        if (figlio < n && lista[figlio] < lista[figlio + 1]) {
            figlio = figlio + 1;
        }
        // confronta la radice e figlio max
        (*compare)++;
        if (temp > lista[figlio]) {
            break; // il padre di figlio sarà la posizione corretta
        } else {
            lista[figlio / 2] = lista[figlio]; // il figlio si sposta verso il padre
        // ripeti sul sottoalbero selezionato
            figlio = 2 * figlio;
        }
    }
    (*swap)++;
    lista[figlio / 2] = temp; // copia la radice nella posizione corretta
}

void heapsort(int lista[], int n, int* compare, int* swap) {
    int i = 0;
    // Si costruisce lo heap associato all'insieme da ordinare lista
    for (i = n / 2; i > 0; --i) {
        adatta(lista, i, n, compare, swap);
    }
    for (i = n - 1; i > 0; --i) {
        //si estrae, di volta in volta, il massimo lista[1] e lo si posiziona in fondo alla sequenza
        qswap(lista, 1, i + 1);
        // si opera nuovamente sullo heap ridotto di un elemento
        adatta(lista, 1, i, compare, swap);
    }
}



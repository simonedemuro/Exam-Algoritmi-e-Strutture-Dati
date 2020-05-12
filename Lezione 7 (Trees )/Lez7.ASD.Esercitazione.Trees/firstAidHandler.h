//
// Created by SimonD on 4/28/2020.
//

#ifndef LEZ7_ASD_ESERCITAZIONE_TREES_FIRSTAIDHANDLER_H
#define LEZ7_ASD_ESERCITAZIONE_TREES_FIRSTAIDHANDLER_H

#include "models.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/*funzione che chiede i dati relativi ad un nuovo paziente e lo restituisce (con il campo ordine calcolato automaticamente),
pronto per essere inserito nella coda con priorita' (heap) */
Paziente nuovoPaziente(ProntoSoccorso *ps);

int priorita(Paziente p1, Paziente p2);
_Bool insertHeap(Paziente* heap, Paziente patient, int* n);
Paziente deleteHeap(Paziente* heap, int* n);
void printHeap(Paziente* heap, int n);

#endif //LEZ7_ASD_ESERCITAZIONE_TREES_FIRSTAIDHANDLER_H

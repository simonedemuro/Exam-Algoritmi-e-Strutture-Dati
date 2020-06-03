//
// Created by SimonD on 5/19/2020.
//

#ifndef LEZ910ASD_ESERCITAZIONE_HASHTABLES_HASHTABLEIMPLEMENTATION_H
#define LEZ910ASD_ESERCITAZIONE_HASHTABLES_HASHTABLEIMPLEMENTATION_H

#include "models.h"

int hash_function(char targa[]);
Auto acquisisci_auto();
void inserisci_auto(Nodo* parcheggio[], Auto a);
void carica_auto_test(Nodo* parcheggio[]);
void stampa_parcheggio(Nodo* parcheggio[]);
void stampa_piano(Nodo* parcheggio[], int piano);
Nodo* ricerca_auto(Nodo* parcheggio[], char targa[]);
void elimina_auto(Nodo* parcheggio[], char targa[]);

#endif //LEZ910ASD_ESERCITAZIONE_HASHTABLES_HASHTABLEIMPLEMENTATION_H

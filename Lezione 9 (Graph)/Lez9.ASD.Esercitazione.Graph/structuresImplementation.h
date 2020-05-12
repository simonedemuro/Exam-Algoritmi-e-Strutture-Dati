//
// Created by SimonD on 4/14/2020.
//

#ifndef LEZ5_ASD_ESERCITAZIONE_STACKQUEUE_ES_1_2_3_STRUCTURESIMPLEMENTATION_H
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "models.h"

_Bool isEmptyQueue(Queue* q);
_Bool isFullQueue(Queue* q);
void pushQueue(Queue* q, int val);
int popQueue(Queue* q);

/* ==============================
 * Support Functions
 * ============================== */
void emptyIntArray(int data[], int numNodi);

/* ==============================
 * Funzioni gia' implementate
 * ============================== */
void carica_citta_test(Citta grafo[]);
void carica_grafo_test_orientato(Citta grafo[], int num_nodi);
void carica_grafo_test_non_orientato(Citta grafo[], int num_nodi);


/* ==============================
 * Funzioni da completare
 * ============================== */
void aggiungi_nodo(Citta grafo[], int *num_nodi);
void crea_arco(Citta grafo[], int id_coda, int id_testa, int num_nodi);
void stampa_lista_adiacenze(Citta grafo[], int num_nodi);

void DFS(Citta grafo[], int visited[], int start_id);
void BFS(Citta grafo[], int visited[], int start_id);

void cancella_arco_orientato(Citta grafo[], int id_coda, int id_testa, int num_nodi);
void cancella_arco_non_orientato(Citta grafo[], int id_coda, int id_testa, int num_nodi);

void componenti_connesse(Citta grafo[], int visited[], int num_nodi);


#define LEZ5_ASD_ESERCITAZIONE_STACKQUEUE_ES_1_2_3_STRUCTURESIMPLEMENTATION_H

#endif //LEZ5_ASD_ESERCITAZIONE_STACKQUEUE_ES_1_2_3_STRUCTURESIMPLEMENTATION_H

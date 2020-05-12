//
// Created by SimonD on 5/8/2020.
//

#ifndef LEZ8_ASD_ESERCITAZIONE_TREES_BTREEHANDLER_H
#define LEZ8_ASD_ESERCITAZIONE_TREES_BTREEHANDLER_H
#include "models.h"

/* -------------------------------
 Funzioni gia' implementate:
 ------------------------------- */
Birra acquisisci_birra();
void stampa_birra(Birra b);

Nodo* crea_nodo(Birra b);
Nodo* carica_test();


/* -------------------------------
 Funzioni da implementare:
 ------------------------------- */
Nodo* insert_nodo(Nodo* root, Nodo* new_node);
void inorder(Nodo* root);
void preorder(Nodo* root);
void postorder(Nodo* root);

int profondita(Nodo* root);
int max(int v1, int v2);

Nodo* ricerca(Nodo* root, char* nome_birra);

Nodo* abr_min(Nodo* root);
Nodo* abr_max(Nodo* root);

Nodo* abr_succ(Nodo* x);
Nodo* abr_pred(Nodo* x);

Nodo* delete_node(Nodo* root, Nodo* nodo);

#endif //LEZ8_ASD_ESERCITAZIONE_TREES_BTREEHANDLER_H

//
// Created by SimonD on 5/19/2020.
//

#ifndef LEZ910ASD_ESERCITAZIONE_HASHTABLES_MODELS_H
#define LEZ910ASD_ESERCITAZIONE_HASHTABLES_MODELS_H

#define MAX_TARGA 10
#define NUM_PIANI 7

typedef enum { CAR_INSERT, PRINT_FLOOR, PRINT_PARK, CAR_SEARCH, CAR_REMOVE, LOAD_DATA, EXIT }operation;

typedef struct
{
    char targa[MAX_TARGA];
    int ora;
    int min;
}Auto;

typedef struct nodo
{
    Auto info;
    struct nodo *link;
}Nodo;


#endif //LEZ910ASD_ESERCITAZIONE_HASHTABLES_MODELS_H

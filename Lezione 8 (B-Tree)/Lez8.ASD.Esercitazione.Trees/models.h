//
// Created by SimonD on 5/8/2020.
//

#ifndef LEZ8_ASD_ESERCITAZIONE_TREES_MODELS_H
#define LEZ8_ASD_ESERCITAZIONE_TREES_MODELS_H

#define DIM_NOME 50
#define NUM_TEST 15

typedef struct
{
    char nome[DIM_NOME];
    float gradi;
    int bottiglie;
} Birra;

typedef struct nodo
{
    Birra key;
    struct nodo *parent;
    struct nodo *left;
    struct nodo *right;
} Nodo;


#endif //LEZ8_ASD_ESERCITAZIONE_TREES_MODELS_H

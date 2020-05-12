//
// Created by SimonD on 3/24/2020.
//

#ifndef ASD_ESERCITAZIONE_SELECTIONSORT_02_MODELS_H
#define ASD_ESERCITAZIONE_SELECTIONSORT_02_MODELS_H
#define DIM_NOME 255
#define MAX_RAND 10000

typedef enum {ORDINATO, QUASI_ORDINATO, INV_ORDINATO, CASUALE} inputType;
typedef enum {RECURSIVE, ITERATIVE} sortType;

typedef struct
{
    char nome[DIM_NOME];
    double prezzo_notte;
    int recensione;
} Hotel;

typedef struct
{
    Hotel* recipie;
    int size;
} RecipieAndSize;


#endif //ASD_ESERCITAZIONE_SELECTIONSORT_02_MODELS_H

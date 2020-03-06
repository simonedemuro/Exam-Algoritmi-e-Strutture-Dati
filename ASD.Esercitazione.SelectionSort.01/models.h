//
// Created by SimonD on 3/3/2020.
//

#ifndef ASD_ESERCITAZIONE_01_MODELS_H
#define ASD_ESERCITAZIONE_01_MODELS_H
#define DIM_NOME 255

typedef enum {ORDINATO, QUASI_ORDINATO, INV_ORDINATO, CASUALE} inputType;

typedef struct
{
    char nome[DIM_NOME];
    double tempo;
    int difficolta;
} Ricetta;



#endif //ASD_ESERCITAZIONE_01_MODELS_H

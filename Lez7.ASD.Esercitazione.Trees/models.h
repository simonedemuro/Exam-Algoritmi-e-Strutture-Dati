//
// Created by SimonD on 4/28/2020.
//

#ifndef LEZ7_ASD_ESERCITAZIONE_TREES_MODELS_H
#define LEZ7_ASD_ESERCITAZIONE_TREES_MODELS_H


#define DIM_NOME 50
#define DIM_HEAP 50

//stuttura che rappresenta un Pronto soccorso
typedef struct
{
    int numeroB;
    int numeroG;
    int numeroV;
    int numeroR;
} ProntoSoccorso;

//enumerazione che rappresenta i codici del pronto soccorso
typedef enum {BIANCO, VERDE, GIALLO, ROSSO} Codice;

//struttura che rappresenta un Paziente
typedef struct
{
    char nome[DIM_NOME];
    Codice codice;
    int ordine;
}Paziente;

#endif //LEZ7_ASD_ESERCITAZIONE_TREES_MODELS_H

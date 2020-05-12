//
// Created by SimonD on 4/28/2020.
//

#include "firstAidHandler.h"

/*funzione che chiede i dati relativi ad un nuovo paziente e lo restituisce (con il campo ordine calcolato automaticamente),
pronto per essere inserito nella coda con priorita' (heap) */
Paziente nuovoPaziente(ProntoSoccorso *ps)
{
    Paziente p;

    printf("\nNome paziente -> ");
    scanf("%[^\n]s", p.nome);
    getchar();

    do
    {
        printf("\nCodice paziente (0 = bianco, 1 = verde, 2 = giallo, 3 = rosso)-> ");
        scanf("%u", &p.codice);
        getchar();

        if(p.codice < BIANCO || p.codice > ROSSO)
            printf("\nCodice non valido");
    }while(p.codice < BIANCO || p.codice > ROSSO);

    if(p.codice == BIANCO)
    {
        ps->numeroB++;
        p.ordine = ps->numeroB;
    }
    else if(p.codice == GIALLO)
    {
        ps->numeroG++;
        p.ordine = ps->numeroG;

    }
    else if (p.codice == VERDE)
    {
        ps->numeroV++;
        p.ordine = ps->numeroV;
    }
    else
    {
        ps->numeroR++;
        p.ordine = ps->numeroR;
    }

    return p;
}

// aka: Compare,
// returns  1 (p1>p2)
//          2 (p2>p1)
int priorita(Paziente p1, Paziente p2){
    // Same Color code --> return the lower order one
    if(p1.codice == p2.codice){
        if(p1.ordine < p2.ordine) // return the one arrived for first
            return 1;
        return 2;
    }
    // Different Color --> return the higher color
    if(p1.codice > p2.codice)
        return 1;
    return 2;
}

_Bool insertHeap(Paziente* heap, Paziente patient, int* n){
    int i;
    if (*n == DIM_HEAP-1){
        printf("Full Heap!");
        return false;
    }

    *n = *n+1;
    i = *n;
    while(i != 1 && priorita(patient, heap[i/2]) == 1){
        heap[i] = heap[i/2];
        i = i/2;
    }
    heap[i] = patient;
}

Paziente deleteHeap(Paziente* heap, int* n){
    Paziente item = heap[1];
    Paziente tmp = heap[*n];
    *n = *n-1;
    int father = 1;
    int son = 2;

    while (son <= *n){
        if (son < *n && priorita(heap[son], heap[son + 1]) == 2)
            son = son + 1;

        if (priorita(tmp, heap[son]) == 1)
            break;

        heap[father] = heap[son];
        father = son;
        son = 2 * son;
    }
    heap[father] = tmp;
    return item;
}

void printHeap(Paziente* heap, int n){
    char color[20];

    for (int i = 1; i < n+1; ++i) {

        switch (heap[i].codice){
            case ROSSO:
                strcpy(color,"Red");
                break;
            case GIALLO:
                strcpy(color,"Yellow");
                break;
            case VERDE:
                strcpy(color,"Green");
                break;
            case BIANCO:
                strcpy(color,"White");
                break;
            default:
                break;
        }

        printf("%s, cod: %s, priority: %d\n", heap[i].nome, color, heap[i].ordine);
    }
}
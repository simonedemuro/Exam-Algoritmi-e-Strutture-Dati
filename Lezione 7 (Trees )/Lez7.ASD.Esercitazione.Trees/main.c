#include <stdio.h>
#include <stdlib.h>
#include "models.h"
#include "firstAidHandler.h"

int main()
{
    char cmd='n'; // user command choice
    //inizializzazione pronto soccorso
    ProntoSoccorso ps;
    ps.numeroB = ps.numeroG = ps.numeroV = ps.numeroR = 0;

    //inizializzazione della Coda con priorita'
    Paziente codaPrio[DIM_HEAP];
    int dim_coda = 0;

    printf("Welcome to First Aid handler type:\n"
           "a -> to add a patient\n"
           "d -> process a patient (delete from tree)"
           "p -> to print the patients\n"
           "e -> to exit\n");

    while(cmd != 'e'){
        scanf("%c",&cmd);
        getchar();

        if(cmd == 'a'){
            Paziente patient = nuovoPaziente(&ps);
            insertHeap(codaPrio,patient, &dim_coda);
        }
        if(cmd == 'p'){
            printHeap(codaPrio, dim_coda);
        }
        if(cmd == 'd'){
            deleteHeap(codaPrio, &dim_coda);
        }
        printf("\ntype another command:\n");
    }

    return 0;
}

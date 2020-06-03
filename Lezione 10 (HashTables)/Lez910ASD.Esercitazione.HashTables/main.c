#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "models.h"
#include "hashTableImplementation.h"

void Menu(){
    printf("\nPlease type an option: ");
    printf("\n0 - Insert a car");
    printf("\n1 - Print a floor");
    printf("\n2 - Print the park (all floor)");
    printf("\n3 - Search a car by plate");
    printf("\n4 - Remove a car");
    printf("\n5 - Load test data");
    printf("\n6 - Exit");
    printf("\n ------>");

}

int main()
{
    Nodo* parcheggio[NUM_PIANI];
    int i = 0;

    for(i = 0; i < NUM_PIANI; i++)
        parcheggio[i] = NULL;

    //inserire qui le funzioni per i test
    int scelta;
    int piano;
    char targa[MAX_TARGA];
    Nodo *trovato;
    do {
        do {
            Menu();
            scanf("%d", &scelta);

            switch (scelta){
                case 0:
                    getchar();
                    inserisci_auto(parcheggio,acquisisci_auto());
                    break;
                case 1:
                    printf("\n inserire il piano da visitare --> ");
                    scanf("%d",&piano);
                    stampa_piano(parcheggio,piano);
                    break;
                case 2:
                    stampa_parcheggio(parcheggio);
                    break;
                case 3:
                    getchar();
                    printf("\n inserire la targa del' auto da ricercare ");
                    scanf("%[^\n]s",targa);
                    getchar();
                    trovato=ricerca_auto(parcheggio,targa);
                    if (trovato!=NULL){
                        printf("\n auto trovata al piano %d",hash_function(trovato->info.targa));
                    } else
                        printf("\n l'auto che sta cercando non e prresente nel gestionale");
                    break;
                case 4:
                    printf("\n inserire la targa dell auto che si vuole eliminare");
                    scanf("%[^\n]s",targa);
                    getchar();
                    elimina_auto(parcheggio,targa);
                    break;
                case 5:
                    carica_auto_test(parcheggio);
                    break;
                case 6:
                    printf("\n grazie per per aver usato il gestionale !");
                    break;
            }


        } while (scelta < 0 || scelta > 6);
    }while(scelta!=6);

    return 0;
}
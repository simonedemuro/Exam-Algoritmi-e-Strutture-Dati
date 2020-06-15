#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "models.h"
#include "hashTableImplementation.h"

void Menu(){
    printf("\n\nPlease type an option: ");
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
                case CAR_INSERT:
                    getchar();
                    inserisci_auto(parcheggio,acquisisci_auto());
                    break;
                case PRINT_FLOOR:
                    printf("\n type the floor number to visit --> ");
                    scanf("%d",&piano);
                    stampa_piano(parcheggio,piano);
                    break;
                case PRINT_PARK:
                    stampa_parcheggio(parcheggio);
                    break;
                case CAR_SEARCH:
                    getchar();
                    printf("\n type the car to search for");
                    scanf("%[^\n]s",targa);
                    getchar();
                    trovato=ricerca_auto(parcheggio,targa);
                    if (trovato!=NULL){
                        printf("\n car found at floor: %d",hash_function(trovato->info.targa));
                    } else
                        printf("\n the car is not parked here");
                    break;
                case CAR_REMOVE:
                    printf("\n type the car to be deleted's plate number");
                    scanf("%[^\n]s",targa);
                    getchar();
                    elimina_auto(parcheggio,targa);
                    break;
                case LOAD_DATA:
                    carica_auto_test(parcheggio);
                    break;
                case EXIT:
                    printf("\n EXIT !");
                    break;
            }


        } while (scelta < 0 || scelta > 6);
    }while(scelta!=6);

    return 0;
}
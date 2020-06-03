//
// Created by SimonD on 5/19/2020.
//

#include "hashTableImplementation.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hash_function(char targa[]){
    int i = 0, sum = 0;

    for (i = 0; i < MAX_TARGA; ++i) {
        sum += targa[i];
    }
    return sum % NUM_PIANI;
}

Auto acquisisci_auto(){
    Auto car;

    printf("Enter a Car:\n");
    printf("Car Plate: \n");
    scanf("%s", car.targa);
    getchar();
    printf("Enter hour:");
    scanf("%d", &car.ora);
    printf("Enter minute");
    scanf("%d", &car.min);

    return car;
}

void inserisci_auto(Nodo* parcheggio[], Auto a){
    Nodo * tmp;
    int idx = hash_function(a.targa);

    // Normal case, the car can be parked
    if (parcheggio[idx] == NULL){
        parcheggio[idx]=(Nodo * )malloc(sizeof(Nodo));
        parcheggio[idx]->info=a;
        parcheggio[idx]->link=NULL;
        return;
    }

    // Otherwise .. I park at the same floor
    // going trough the conflict list to place at the last element
    tmp = parcheggio[idx];
    while (tmp->link!=NULL)
        tmp=tmp->link;

    // insert in the list
    tmp->link  = (Nodo * )malloc(sizeof(Nodo));
    tmp=tmp->link;
    tmp->link= NULL;
    tmp->info= a;
}

void carica_auto_test(Nodo* parcheggio[]){
    Auto a0 = {"PI555TA", 12, 15};
    Auto a1 = {"CA220TO", 7, 59};
    Auto a2 = {"EG000AL", 19, 45};
    Auto a3 = {"GO000LE", 15, 20};
    Auto a4 = {"BA220TO", 10, 35};
    Auto a5 = {"AP111LE", 15, 20};
    Auto a6 = {"MI123FT", 18, 40};
    Auto a7 = {"NO985LE", 20, 30};
    Auto a8 = {"GI124CH", 11, 20};
    Auto a9 = {"LO199RE", 9, 30};
    Auto a10 = {"ZA156KF", 7, 10};

    inserisci_auto(parcheggio, a0);
    inserisci_auto(parcheggio, a1);
    inserisci_auto(parcheggio, a2);
    inserisci_auto(parcheggio, a3);
    inserisci_auto(parcheggio, a4);
    inserisci_auto(parcheggio, a5);
    inserisci_auto(parcheggio, a6);
    inserisci_auto(parcheggio, a7);
    inserisci_auto(parcheggio, a8);
    inserisci_auto(parcheggio, a9);
    inserisci_auto(parcheggio, a10);
}

void stampa_parcheggio(Nodo* parcheggio[]){
    int i = 0;
    for (i = 0; i < NUM_PIANI; ++i) {
        stampa_piano(parcheggio, i);
        printf("\n");
    }
}

void stampa_piano(Nodo* parcheggio[], int piano){
    Nodo* floorListNode = parcheggio[piano];
    if(floorListNode == NULL){
        printf("Empry Floor\n");
        return;
    }
    printf("Floor n. %d", piano);
    while(floorListNode != NULL){
        printf("\t %s", floorListNode->info.targa);
        floorListNode = floorListNode->link;
    }
}

Nodo* ricerca_auto(Nodo* parcheggio[], char targa[]){
    Nodo* tmp = parcheggio[hash_function(targa)];

    while (tmp != NULL && strcmp(targa, tmp->info.targa) != 0 ){
        tmp = tmp->link;
    }
    return tmp;
}

void elimina_auto(Nodo* parcheggio[], char targa[]){
    Nodo* carFloor = parcheggio[hash_function(targa)];
    Nodo* carToRem;
    Nodo* prevCar;

    // prevCar is the car before the one to be deleted
    prevCar = carToRem = carFloor;
    while(carToRem != NULL && strcmp(carToRem->info.targa,targa)!=0){
        prevCar = carToRem;
        carToRem = carToRem->link;
    }

    // Handling attempt to remove non existing Keys
    if(carToRem == NULL || strcmp(carToRem->info.targa,targa)!=0){
        printf("Sir you parked somewhere else or someone stolen your car\n");
        return;
    }

    // The car I want to remove has other cars in front of him
    if(carToRem->link != NULL){
        prevCar->link = carToRem->link;
        free(carToRem);
        return;
    }

    // The car I want to remove has no car in front
    prevCar->link = NULL;
    free(carToRem);
}
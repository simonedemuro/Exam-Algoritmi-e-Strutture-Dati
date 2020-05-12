//
// Created by SimonD on 4/21/2020.
//

#ifndef LEZ6_ASD_ESERCITAZIONE_LINKEDLIST_ES_NETFLIX_MODELS_H
#define LEZ6_ASD_ESERCITAZIONE_LINKEDLIST_ES_NETFLIX_MODELS_H

//MACROS
#define DIM_TITLE 50
#define DIM_GENRE 50
#define DIM_NAME 50


//struttura che rappresenta una SERIE TV
struct tvs
{
    char title[DIM_TITLE];
    char genre[DIM_GENRE];
    int num_episodes;
    struct tvs* prev;
    struct tvs* next;
};

typedef struct tvs TVS;

//struttura che rappresenta una PLAYLIST
struct playlist
{
    char name[DIM_NAME];
    TVS* top;
};

typedef struct playlist PlayList;

#endif //LEZ6_ASD_ESERCITAZIONE_LINKEDLIST_ES_NETFLIX_MODELS_H

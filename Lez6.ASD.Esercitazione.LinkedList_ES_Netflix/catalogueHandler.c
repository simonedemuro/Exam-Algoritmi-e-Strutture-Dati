//
// Created by SimonD on 4/21/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "catalogueHandler.h"

/* ---------------------------------------------
* funzioni da NON modificare
* --------------------------------------------*/
TVS* acquireTVSeries()
{
    TVS* new_s = (TVS*)malloc(sizeof(TVS));
    printf("\nInsert title -> ");
    scanf("%[^\n]s", new_s->title);
    getchar();

    printf("Insert genre -> ");
    scanf("%[^\n]s", new_s->genre);
    getchar();

    printf("Insert number of episodes -> ");
    scanf("%d", &(new_s->num_episodes));
    getchar();

    new_s->prev = NULL;
    new_s->next = NULL;

    return new_s;
}

void printTVSeries(TVS* t)
{
    printf("TITLE    :\t %s \n", t->title);
    printf("GENRE    :\t %s \n", t->genre);
    printf("EPISODES :\t %d \n\n", t->num_episodes);
}

/* ---------------------------------------------
* funzioni STUDENTE
* --------------------------------------------*/

_Bool isPlaylistEmpty(PlayList* pl){
    return pl->top==NULL?true:false;
}

_Bool isLastElementOfPlaylist(TVS* pl){
    return pl==NULL?true:false;
}

//inserisce una serie tv (creata con la funzione acquire) nella lista in maniera ordinata
void insertTVSeries(PlayList* pl, TVS* t){
    /*handling empty playlist*/
    if(isPlaylistEmpty(pl)){
        pl->top = t;
        return; // using an empty return to avoid an else statement that would increase nesting level
    }

    /*linear sorted insert */
    TVS* tmpPrev = NULL;
    TVS* tmpNext = pl->top;

    while (tmpNext != NULL && strcmp(tmpNext->title, t->title) <= 0/*tmpTitle <= titleToInsert*/){
        tmpPrev = tmpNext;
        tmpNext = tmpNext->next;
    }

    /*now we have the position, inserting the title in that position */
    // end of playlist, insert in queue
    if(isLastElementOfPlaylist(tmpNext)){
        t->prev = tmpPrev;
        tmpPrev->next = t;
    }
    // first element of playlist, insert on top
    else if (tmpNext == pl->top){
        t->next = pl->top;
        pl->top = t;
    }
    // normal case insert in between
    else{
        tmpPrev->next = t;
        tmpNext->prev = t;
        t->prev = tmpPrev;
        t->next = tmpNext;
    }
}

//cerca una serie tv nella lista (tramite il titolo) e restituisce il suo puntatore
TVS* findTVSeries(PlayList* pl, char title[]){
    for (TVS* current = pl->top; current != NULL ; current = current->next) {
        if (current->title == title)
            return current;
    }
    return NULL;
}

//modifica una serie tv gia’ presente (trovata tramite la funzione find) e la riposiziona nella posizione corretta
void modifyTVSeries(PlayList* pl, TVS* t){
    TVS* titleToBeModified = acquireTVSeries();
    deleteTVSeries(pl, t);
    insertTVSeries(pl, titleToBeModified);
}

//elimina una serie tv già presente (trovata tramite la funzione find) e dealloca l’elemento
void deleteTVSeries(PlayList* pl, TVS* t){

    // the playlist is empty
    if(isPlaylistEmpty(pl)){
        printf("empty playlist");
        return;
    }

    // the title doesn't exist
    if(t == NULL){
        printf("title not found");
        return;
    }

    /* Actually deleting the title */
    // the element to be deleted is the FIRST
    if (t->prev == NULL){
        pl->top = t->next;
    }
    // the element is not the first
    else{
        t->prev = t->next;
    }
    // if the element is NOT the LAST
    if(t->next != NULL){
        t->next->prev = t->prev;
    }
}

//restituisce il puntatore alla serie tv successiva rispetto a quella
// passata come puntatore se presente, altrimenti restituisce NULL
TVS* nextTVSeries(TVS* t){
    return t->next;
}

//restituisce il puntatore alla serie tv precedente rispetto a quella
// passata come puntatore se presente, altrimenti restituisce NULL
TVS* prevTVSeries(TVS* t){
    return t->prev;
}

//stampa l’intera playlist di serie tv (usando la funzione di stampa singola)
void printPlayList(PlayList* pl){
    if (isPlaylistEmpty(pl))
        printf("empty Playlist");

    // starting from the playlist's top
    TVS* curr = pl->top;
    // until there are elements
    while (!isLastElementOfPlaylist(curr)){
        printTVSeries(curr);        // print the current tv series
        curr = nextTVSeries(curr); // navigate to the next one
    }
}

// this function provide a way to navigate the playlist
void playlistScroll(PlayList* pl){
    // user provided command to navigate e-> exit, p -> previous, n -> next
    char cmd = 'i';
    TVS* tmpShow;

    if(isPlaylistEmpty(pl)){
        printf("empty Playlist");
        return;
    }
    TVS* currentShow = pl->top;
    printf("welcome to the navigation playlist, type:\n"
           "e -> exit\np -> previous\nn -> next\n");

    // until the user decides to quit by pressing e
    while (cmd != 'e'){
        printf("Current Show:\n");
        printTVSeries(currentShow);
        printf("type a command: ");

        scanf("%c",&cmd);
        getchar();
        if (cmd == 'p'){
            tmpShow = prevTVSeries(currentShow);
            if (tmpShow == NULL)
                printf("\nthere are no previous elements to be shown");
            else
                currentShow = tmpShow;
        }
        else if (cmd == 'n'){
            tmpShow = nextTVSeries(currentShow);
            if (tmpShow == NULL)
                printf("\nthere are no further elements to be shown");
            else
                currentShow = tmpShow;
        }
    }
}
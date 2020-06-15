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

int getNumericAnswerFromUser(int maxOptionAvailable){
    int userAnswer = -1;
    _Bool invalidInputEntered;

    // Asks for an option until it gets entered correctly
    do {
        scanf("%d", &userAnswer);
        getchar();

        // checks if the value is between 1 and the maximum option available for this command
        invalidInputEntered = userAnswer < 0 || userAnswer > maxOptionAvailable;
        if(invalidInputEntered){
            printf("please enter a valid input\n");
        }
    } while(invalidInputEntered);
    //than returns a certainly valid input
    return userAnswer;
}

/**
 *  merges playlistA and playlistB into playlistResult
 */
void  mergePlayList(PlayList* playlistA, PlayList* playlistB, PlayList* playlistResult){
    TVS *tmpA_prev, *tmpA_next ;
    TVS* tmpB_tvs, *tmpB_nexttvs;
    _Bool inizio=1;

    if (playlistA->top == NULL){
        playlistResult->top=playlistB->top;
    }
    else if (playlistB->top == NULL){
        playlistResult->top=playlistA->top;
    }
    else {
        // search for the position to insert
        tmpA_prev = NULL;
        tmpA_next = playlistA->top;
        tmpB_tvs=playlistB->top;
        tmpB_nexttvs=tmpB_tvs->next;

        // iterating over playlistB
        while(tmpB_tvs != NULL && tmpA_next != NULL) {
            printf("\nin lavorazione\n");
            printTVSeries(tmpB_tvs);
            printf("-------\n");

            // put B nodes inside A
            while (tmpA_next != NULL && strcmp(tmpA_next->title, tmpB_tvs->title) <= 0) {
                tmpA_prev = tmpA_next;
                tmpA_next = tmpA_next->next;
            }

            // here we have the node after wich join the next (tmpB)
            if (tmpA_next == NULL) {
                tmpA_prev->next = tmpB_tvs;
                tmpB_tvs->prev = tmpA_prev;
            } else if (tmpA_next == playlistA->top && inizio) {
                playlistA->top = tmpB_tvs;
                tmpB_tvs->prev = NULL;
                playlistA->top->next = tmpA_next;
                tmpA_next->prev = playlistA->top;
                inizio=0;
            } else {
                tmpA_prev->next = tmpB_tvs;
                tmpB_tvs->prev = tmpA_prev;
                tmpB_tvs->next = tmpA_next;
                tmpA_next->prev = tmpB_tvs;
            }
            tmpA_prev=tmpB_tvs;
            tmpB_tvs=tmpB_nexttvs;

            // handling last element of the collection
            if (tmpB_nexttvs != NULL) {
                tmpB_nexttvs = tmpB_tvs->next;
            }
            printPlayList(playlistA);
            fflush(NULL);
        }
    }
    playlistResult->top=playlistA->top;
    playlistA->top=NULL;
    playlistB->top=NULL;
}
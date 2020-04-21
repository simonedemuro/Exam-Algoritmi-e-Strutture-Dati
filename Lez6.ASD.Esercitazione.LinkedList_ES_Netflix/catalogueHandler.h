//
// Created by SimonD on 4/21/2020.
//

#ifndef LEZ6_ASD_ESERCITAZIONE_LINKEDLIST_ES_NETFLIX_CATALOGUEHANDLER_H
#define LEZ6_ASD_ESERCITAZIONE_LINKEDLIST_ES_NETFLIX_CATALOGUEHANDLER_H
// including required files
#include "models.h"

//funzioni (gia' definite) per l'acquisizione e per la stampa di una serie tv
TVS* acquireTVSeries(); //acquisisce i dati di UNA serie tv chiedendoli all'utente
void printTVSeries(TVS* t); //stampa i dati relativi ad UNA serie tv (passata tramite puntatore)

//prototipi funzioni STUDENTE

//inserisce una serie tv (creata con la funzione acquire) nella lista in maniera ordinata
void insertTVSeries(PlayList* pl, TVS* t);

//cerca una serie tv nella lista (tramite il titolo) e restituisce il suo puntatore
TVS* findTVSeries(PlayList* pl, char title[]);

//modifica una serie tv gia’ presente (trovata tramite la funzione find) e la riposiziona nella posizione corretta
void modifyTVSeries(PlayList* pl, TVS* t);

//elimina una serie tv già presente (trovata tramite la funzione find) e dealloca l’elemento
void deleteTVSeries(PlayList* pl, TVS* t);

//stampa l’intera playlist di serie tv (usando la funzione di stampa singola)
void printPlayList(PlayList* pl);

//restituisce il puntatore alla serie tv successiva rispetto a quella
// passata come puntatore se presente, altrimenti restituisce NULL
TVS* nextTVSeries(TVS* t);

//restituisce il puntatore alla serie tv precedente rispetto a quella
// passata come puntatore se presente, altrimenti restituisce NULL
TVS* prevTVSeries(TVS* t);

//fonde le liste plA e plB in un’unica lista plC (anch’essa passata come parametro). NESSUN nuovo
// nodo deve essere allocato
void mergePlayList(PlayList* plA, PlayList* plB, PlayList* plC);

// this function provide a way to navigate the playlist
void playlistScroll(PlayList* pl);


#endif //LEZ6_ASD_ESERCITAZIONE_LINKEDLIST_ES_NETFLIX_CATALOGUEHANDLER_H

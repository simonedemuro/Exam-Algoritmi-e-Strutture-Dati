#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "models.h"
#include "structuresImplementation.h"

int main()
{
    Citta grafo[MAX_VERTICI];
    int num_nodi;
    int *visited = (int*)calloc(NUM_NODI_TEST, sizeof(int));

    //Inserire qui le chiamate per testare le varie funzioni e il menu
    num_nodi = 11;
    carica_citta_test(grafo);
    carica_grafo_test_orientato(grafo, num_nodi);

    printf("\n\n !!DFS!!\n");
    fflush(NULL);

    emptyIntArray(visited, num_nodi);
    DFS(grafo,visited, 0);

    printf("\n\n !!BFS!!\n");
    fflush(NULL);

    emptyIntArray(visited, num_nodi);
    BFS(grafo,visited, 0);

    printf("\n\n !!Componenti connesse!!\n");
    fflush(NULL);

    emptyIntArray(visited, num_nodi);
    componenti_connesse(grafo, visited, num_nodi);

    printf("\n\n !!cancella arco orientato o non!!\n");
    fflush(NULL);

//cancella_arco_orientato(grafo, 8, 9, num_nodi);
    cancella_arco_non_orientato(grafo,8,9, num_nodi);
    emptyIntArray(visited, num_nodi);
    DFS(grafo, visited, 8);

    printf("\n\n !!effetti cancellazione arco !!\n");
    fflush(NULL);

    emptyIntArray(visited, num_nodi);
    DFS(grafo, visited, 9);
    aggiungi_nodo(grafo,&num_nodi);
    crea_arco(grafo, 11, 8, num_nodi);

    emptyIntArray(visited,num_nodi);
    componenti_connesse(grafo, visited,num_nodi);
}

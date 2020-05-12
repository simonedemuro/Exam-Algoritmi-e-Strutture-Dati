//
// Created by SimonD on 4/14/2020.
//

//Esercizio 5_1: Coda

#include "structuresImplementation.h"
#include <string.h>
#define DIM_CODA 50
// Region for Queue

_Bool isEmptyQueue(Queue* q){
    if (q->cont == 0 || (q->front == NULL && q->back == NULL) )
        return true;
    return false;
}

_Bool isFullQueue(Queue* q){
    if (q->cont == DIM_CODA)
        return true;
    return false;
}

Queue* initQueue(){
    Queue* q = malloc(sizeof(Queue));

    q->front = NULL;
    q->back = NULL;
    q->cont = 0;
    return q;
}
void pushQueue(Queue* q, int val){
    if(isFullQueue(q)){
        printf("Overflow");
        return;
    }

    Node* newNode = (Node*) malloc(sizeof(Node)*1);
    newNode->vertex_id = val;
    newNode->link = NULL;

    if (isEmptyQueue(q)){
        q->front = newNode;
        q->back = newNode;
    }
    else{
        q->back->link = newNode;
        q->back = newNode;
    }
    q->cont++;
}

int popQueue(Queue* q){
    if (isEmptyQueue(q)){
        printf("UnderFlow");
        return -1;
    }

    Node* tmp = q->front;
    int val = tmp->vertex_id;

    if(q->cont==1){
        q->front = NULL;
        q->back = NULL;
    }
    else{
        q->front = q->front->link;
    }
    q->cont--;
    free(tmp);
    return val;
}

void carica_citta_test(Citta grafo[])
{
    //Cagliari
    strcpy(grafo[0].nome, "Cagliari");
    strcpy(grafo[0].nazione, "Italia");
    grafo[0].abitanti = 300000;
    grafo[0].lista_adj = NULL;

    //Zurigo
    strcpy(grafo[1].nome, "Zurigo");
    strcpy(grafo[1].nazione, "Svizzera");
    grafo[1].abitanti = 400000;
    grafo[1].lista_adj = NULL;

    //Lione
    strcpy(grafo[2].nome, "Lione");
    strcpy(grafo[2].nazione, "Francia");
    grafo[2].abitanti = 500000;
    grafo[2].lista_adj = NULL;

    //Genova
    strcpy(grafo[3].nome, "Genova");
    strcpy(grafo[3].nazione, "Italia");
    grafo[3].abitanti = 800000;
    grafo[3].lista_adj = NULL;

    //Roma
    strcpy(grafo[4].nome, "Roma");
    strcpy(grafo[4].nazione, "Italia");
    grafo[4].abitanti = 4000000;
    grafo[4].lista_adj = NULL;

    //New York
    strcpy(grafo[5].nome, "New York");
    strcpy(grafo[5].nazione, "USA");
    grafo[5].abitanti = 8500000;
    grafo[5].lista_adj = NULL;

    //Bilbao
    strcpy(grafo[6].nome, "Bilbao");
    strcpy(grafo[6].nazione, "Spagna");
    grafo[6].abitanti = 350000;
    grafo[6].lista_adj = NULL;

    //Berlino
    strcpy(grafo[7].nome, "Berlino");
    strcpy(grafo[7].nazione, "Germania");
    grafo[7].abitanti = 3500000;
    grafo[7].lista_adj = NULL;

    //Londra
    strcpy(grafo[8].nome, "Londra");
    strcpy(grafo[8].nazione, "Gran Bretagna");
    grafo[8].abitanti = 8700000;
    grafo[8].lista_adj = NULL;

    //Miami
    strcpy(grafo[9].nome, "Miami");
    strcpy(grafo[9].nazione, "USA");
    grafo[9].abitanti = 450000;
    grafo[9].lista_adj = NULL;

    //Tokyo
    strcpy(grafo[10].nome, "Tokyo");
    strcpy(grafo[10].nazione, "Giappone");
    grafo[10].abitanti = 13700000;
    grafo[10].lista_adj = NULL;
}

void carica_grafo_test_orientato(Citta grafo[], int num_nodi)
{
    carica_citta_test(grafo);

    //Creazione archi
    crea_arco(grafo, 0, 1, num_nodi);
    crea_arco(grafo, 0, 4, num_nodi);

    crea_arco(grafo, 1, 0, num_nodi);
    crea_arco(grafo, 1, 2, num_nodi);

    crea_arco(grafo, 2, 1, num_nodi);
    crea_arco(grafo, 2, 3, num_nodi);

    crea_arco(grafo, 4, 0, num_nodi);
    crea_arco(grafo, 4, 1, num_nodi);
    crea_arco(grafo, 4, 5, num_nodi);
    crea_arco(grafo, 4, 6, num_nodi);

    crea_arco(grafo, 5, 1, num_nodi);

    crea_arco(grafo, 6, 7, num_nodi);

    crea_arco(grafo, 8, 9, num_nodi);

    crea_arco(grafo, 9, 8, num_nodi);
    crea_arco(grafo, 9, 10, num_nodi);
}

void carica_grafo_test_non_orientato(Citta grafo [], int num_nodi)
{
    carica_citta_test(grafo);

    //Creazione archi
    crea_arco(grafo, 0, 1, num_nodi);
    crea_arco(grafo, 1, 0, num_nodi);

    crea_arco(grafo, 0, 4, num_nodi);
    crea_arco(grafo, 4, 0, num_nodi);

    crea_arco(grafo, 1, 2, num_nodi);
    crea_arco(grafo, 2, 1, num_nodi);

    crea_arco(grafo, 2, 3, num_nodi);
    crea_arco(grafo, 3, 2, num_nodi);

    crea_arco(grafo, 4, 1, num_nodi);
    crea_arco(grafo, 1, 4, num_nodi);

    crea_arco(grafo, 4, 5, num_nodi);
    crea_arco(grafo, 5, 4, num_nodi);

    crea_arco(grafo, 4, 6, num_nodi);
    crea_arco(grafo, 6, 4, num_nodi);

    crea_arco(grafo, 5, 1, num_nodi);
    crea_arco(grafo, 1, 5, num_nodi);

    crea_arco(grafo, 6, 7, num_nodi);
    crea_arco(grafo, 7, 6, num_nodi);

    crea_arco(grafo, 8, 9, num_nodi);
    crea_arco(grafo, 9, 8, num_nodi);

    crea_arco(grafo, 9, 10, num_nodi);
    crea_arco(grafo, 10, 9, num_nodi);
}

void aggiungi_nodo(Citta grafo[], int *num_nodi)
{
    // inserire qui il codice della funzione...
    Citta city;
    
    printf("Type City Name:\n");
    scanf("%s", city.nome);
    int c;
    while ((c = getchar()) != '\n' && c != EOF){}
    
    printf("Type number of inhabitans:\n");
    scanf("%i", &city.abitanti);

    printf("Type Nationality (char): \n");
    scanf("%s", city.nazione);
    while ((c = getchar()) != '\n' && c != EOF){}

    city.lista_adj = NULL;
    grafo[*num_nodi] = city;
    (*num_nodi)++;
}

Node* createNode(int vertexId){
    Node* n = malloc(sizeof(Node));
    n->vertex_id = vertexId;
    n->link = NULL;
}

void crea_arco(Citta grafo[], int id_coda, int id_testa, int num_nodi)
{
    Node* tmp = grafo[id_coda].lista_adj;
    Node* newArch = createNode(id_testa);

    if(id_testa > num_nodi || id_coda > num_nodi){
        printf("Error inside crea_arco, invalid input");
        return;
    }

    if (tmp == NULL){
        grafo[id_coda].lista_adj =  newArch;
        return;
    }

    while(tmp->link != NULL && tmp->link->vertex_id < id_testa){
        tmp = tmp->link;
    }

    newArch->link = tmp->link;
    tmp->link = newArch;
}

void stampa_adiacenze_nodo(Node* elem){
    while (elem != NULL){
        printf("\t%d --> ", elem->vertex_id);
        elem = elem->link;
    }
}

void stampa_lista_adiacenze(Citta grafo[], int num_nodi)
{
    int i = 0;
    for (i = 0; i < num_nodi; ++i) {
        stampa_adiacenze_nodo(grafo[i].lista_adj);
    }
}

void emptyIntArray(int data[], int numNodi){
    int i = 0;
    for (i = 0; i < numNodi; ++i) {
        data[i] = 0;
    }
}


void stampaCitta(Citta grafo[], int cittaID){
    printf("\n\t-------------------");
    printf("\n\t Name: %s",grafo[cittaID].nome);
    printf("\n\t n. Inhabitants: %d",grafo[cittaID].abitanti);
    printf("\n\t Adjacent : %d --> ",cittaID);
    stampa_adiacenze_nodo(grafo[cittaID].lista_adj);
    printf("\n\t Nationality: %s",grafo[cittaID].nazione);
}

void DFS(Citta grafo[], int visited[], int start_id)
{
    int id_next = 0;
    if (visited[start_id] != 1) {
        stampaCitta(grafo, start_id);
        visited[start_id] = 1;
    }

    Node *tmp = grafo[start_id].lista_adj;

    while (tmp != NULL) {
        id_next = tmp->vertex_id;

        if (visited[id_next] != 1) {
            DFS(grafo, visited, id_next);
        }
        tmp = tmp->link;
    }
}

void BFS(Citta grafo[], int visited[], int start_id) {
    int id_next = 0, i = 0;
    Node *tmp = NULL;

    if (visited[start_id] != 1) {
        stampaCitta(grafo, start_id);
        visited[start_id] = 1;
    }

    Queue* queue;
    queue = initQueue();

    pushQueue(queue, start_id);
    while (!isEmptyQueue(queue)) {
        i = popQueue(queue);
        tmp = grafo[i].lista_adj;
        while (tmp != NULL) {
            if (visited[tmp->vertex_id] != 1) {
                pushQueue(queue, tmp->vertex_id);
                stampaCitta(grafo, tmp->vertex_id);
                visited[tmp->vertex_id] = 1;
                tmp = tmp->link;
            } else{
                tmp = tmp->link;
            }
        }
    }
}


void cancella_arco_orientato(Citta grafo[], int id_coda, int id_testa, int num_nodi)
{
    if(id_testa > num_nodi || id_coda > num_nodi){
        printf("Error inside crea_arco, invalid input");
        return;
    }

    if (grafo[id_coda].lista_adj == NULL)
        return;

    Node* tmp = grafo[id_coda].lista_adj;
    // the first arch is the one we want to delete
    if(tmp->vertex_id == id_testa){
        // .. and is also the last
        if(tmp->link == NULL){
            free(tmp);
            grafo[id_coda].lista_adj = NULL;
        }
        else
        {
            tmp = tmp->link;
            free(grafo[id_coda].lista_adj);
            grafo[id_coda].lista_adj = tmp;
        }
        return;
    }
    Node *prevNode= NULL;
    // The arch I want to delete is in the middle, I iterate over it
    while(tmp->link != NULL && tmp->link->vertex_id < id_testa){
        tmp = tmp->link;
    }
    prevNode = tmp;
    tmp=tmp->link;
    if(tmp->link == NULL){
        free(tmp);
        prevNode->link = NULL;
    }
    else
    {
        tmp = tmp->link;
        free(prevNode->link);
        prevNode->link = tmp;
    }
}

void cancella_arco_non_orientato(Citta grafo[], int id_coda, int id_testa, int num_nodi) {
    cancella_arco_orientato(grafo,id_coda,id_testa,num_nodi);
    cancella_arco_orientato(grafo,id_testa,id_coda,num_nodi);
}

void componenti_connesse(Citta grafo[], int visited[], int num_nodi)
{
    int i = 0;
    while ( i < num_nodi) {
        printf("\nElaborating %d \n", i);
        emptyIntArray(visited, num_nodi);
        DFS(grafo, visited, i);
        while (i < num_nodi && visited[i] == 1){
            i++;
        }
    }
}
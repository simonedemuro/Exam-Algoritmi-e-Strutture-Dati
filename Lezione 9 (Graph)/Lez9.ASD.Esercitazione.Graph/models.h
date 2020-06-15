//
// Created by SimonD on 5/12/2020.
//

#ifndef LEZ9_ASD_ESERCITAZIONE_GRAPH_MODELS_H
#define LEZ9_ASD_ESERCITAZIONE_GRAPH_MODELS_H

#define MAX_VERTICI 20
#define DIM 50
#define NUM_NODI_TEST 11


typedef enum {LOAD_TEST_DATA, DFS_VISIT, BFS_VISIT, CONNECTED_COMPONENTS, DELETE_ARCH}inputType;

typedef struct node
{
    int vertex_id;
    struct node* link;
}Node;

typedef struct
{
    char nome[DIM];
    int  abitanti;
    char nazione[DIM];
    Node* lista_adj;
}Citta;

typedef struct
{
    Node* front;
    Node* back;
    int cont;
}Queue;

#endif //LEZ9_ASD_ESERCITAZIONE_GRAPH_MODELS_H

//
// Created by SimonD on 4/14/2020.
//

#ifndef LEZ5_ASD_ESERCITAZIONE_STACKQUEUE_ES_1_2_3_MODELS_H

#define DIM_CODA 10 // modificare a piacimento
#define DIM_STACK 10 // modificare a piacimento
#define DIM_STRING 50

typedef struct
{
    char articolo[DIM_STRING];
    double prezzo;
    char destinatario[DIM_STRING];
}Ordine;

struct node
{
    Ordine data;
    struct node* link;
};

typedef struct node Node;

typedef struct
{
    Node* front;
    Node* back;
    int cont;
}Queue;

typedef struct
{
    Node* top;
    int cont;
}Stack;

typedef enum {
//    "0. Insert new order in queue\n"
    ADD_ORDER_TO_QUEUE,
//    "1. Remove an order from queue\n"
    REMOVE_ORDER_FROM_QUEUE,
//    "2. Insert an order in the shipping stack\n"
    ADD_ORDER_TO_SHIPMENT_STACK,
//    "3. Remove order from stack because has been shipped\n"
    REMOVE_ORDER_FROM_SHIPMENT_STACK,
//    "4. Process first order automatically\n"
    PROCESS_FIRST_ORDER_AUTOMATICALLY,
//    "5. Print Order's queue\n"
    PRINT_QUEUE,
//    "6. Print Shipping's stack");
    PRINT_STACK,
    EXIT
}menuItem;

#define LEZ5_ASD_ESERCITAZIONE_STACKQUEUE_ES_1_2_3_MODELS_H

#endif //LEZ5_ASD_ESERCITAZIONE_STACKQUEUE_ES_1_2_3_MODELS_H

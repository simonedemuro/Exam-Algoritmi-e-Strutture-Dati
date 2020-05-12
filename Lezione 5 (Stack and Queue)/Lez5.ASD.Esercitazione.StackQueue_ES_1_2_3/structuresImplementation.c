//
// Created by SimonD on 4/14/2020.
//

//Esercizio 5_1: Coda

#include "structuresImplementation.h"

// Region for Queue

_Bool isEmptyQueue(Queue* q){
    if (q->cont == 0)
        return true;
    return false;
}

_Bool isFullQueue(Queue* q){
    if (q->cont == DIM_CODA)
        return true;
    return false;
}

void pushQueue(Queue* q, Ordine val){
    if(isFullQueue(q)){
        printf("Overflow");
        return;
    }

    Node* newNode = (Node*) malloc(sizeof(Node)*1);
    newNode->data = val;
    newNode->link = NULL;

    if (isEmptyQueue(q)){
        q->front = newNode;
        q->back = newNode;
    }
    else{
        q->back->link = newNode;
        q->back = newNode;
//        newNode->link = q->back;
//        q->back = newNode;
    }
    q->cont++;
}

Ordine popQueue(Queue* q){
    if (isEmptyQueue(q)){
        printf("UnderFlow");
        return (Ordine){"error",-1,"Error"};
    }

    Node* tmp = q->front;
    Ordine val = tmp->data;

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

// region for Stack

_Bool isEmptyStack(Stack* s){
    if (s->cont == 0)
        return true;
    return false;
}

_Bool isFullStack(Stack* s){
    if (s->cont == DIM_STACK)
        return true;
    return false;
}

void pushStack(Stack* s, Ordine val){
    if (isFullStack(s)){
        printf("Overflow");
        return;
    }

    Node* newNode = (Node*) malloc(sizeof(Ordine));
    newNode->data = val;
    newNode->link = NULL;

    if(isEmptyStack(s)){
        s->top = newNode;
    }
    else{
        newNode->link = s->top;
        s->top = newNode;
    }
    s->cont++;
}

Ordine popStack(Stack* s){
    Ordine val;
    if(isEmptyStack(s)){
        printf("Underflow");
        val = (Ordine){"Error", -1, "Error"};
        return val;
    }

    Node* tmp = s->top;
    val = s->top->data;

    s->top = s->top->link;
    s->cont--;
    free(tmp);

    return val;
}
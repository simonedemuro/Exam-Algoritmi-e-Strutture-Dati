//
// Created by SimonD on 4/14/2020.
//

#ifndef LEZ5_ASD_ESERCITAZIONE_STACKQUEUE_ES_1_2_3_STRUCTURESIMPLEMENTATION_H
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "models.h"

_Bool isEmptyQueue(Queue* q);
_Bool isFullQueue(Queue* q);
void pushQueue(Queue* q, Ordine val);
Ordine popQueue(Queue* q);

_Bool isEmptyStack(Stack* s);
_Bool isFullStack(Stack* s);
void pushStack(Stack* s, Ordine val);
Ordine popStack(Stack* s);

#define LEZ5_ASD_ESERCITAZIONE_STACKQUEUE_ES_1_2_3_STRUCTURESIMPLEMENTATION_H

#endif //LEZ5_ASD_ESERCITAZIONE_STACKQUEUE_ES_1_2_3_STRUCTURESIMPLEMENTATION_H

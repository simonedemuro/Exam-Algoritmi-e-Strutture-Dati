//
// Created by SimonD on 4/14/2020.
//

#ifndef LEZ5_ASD_ESERCITAZIONE_STACKQUEUE_ES_1_2_3_MENUHANDLER_H
#include <stdio.h>
#include "models.h"
#include "structuresImplementation.h"

void printMainMenu();
int getNumericAnswerFromUser(int maxOptionAvailable);
void processUserAction(Queue* orderQueue, Stack* stackQueue);
Ordine getOrderFromUser();
void printOrder(Ordine order);

void printStack(Stack* s);
void printQueue(Queue* q);

#define LEZ5_ASD_ESERCITAZIONE_STACKQUEUE_ES_1_2_3_MENUHANDLER_H

#endif //LEZ5_ASD_ESERCITAZIONE_STACKQUEUE_ES_1_2_3_MENUHANDLER_H

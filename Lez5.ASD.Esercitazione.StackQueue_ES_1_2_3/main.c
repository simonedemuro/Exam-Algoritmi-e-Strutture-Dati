#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "models.h"
#include "structuresImplementation.h"
#include "menuHandler.h"
#define THE_USER_PRESS_EXIT true

//prototipi funzioni per la gestione della Coda
//...

//prototipi funzioni per la gestione dello Stack
//...

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
int main()
{
    //dichiarazione e inizializzazione della Coda
    Queue queue;
    queue.front = NULL;
    queue.back = NULL;
    queue.cont = 0;


    //dichiarazione e inizializzazione dello Stack
    Stack stack;
    stack.top = NULL;
    stack.cont = 0;

    //istruzioni e chiamate per i test...
    while (THE_USER_PRESS_EXIT) {
        printMainMenu();
        processUserAction(&queue, &stack);
    }

    return 0;
}
#pragma clang diagnostic pop
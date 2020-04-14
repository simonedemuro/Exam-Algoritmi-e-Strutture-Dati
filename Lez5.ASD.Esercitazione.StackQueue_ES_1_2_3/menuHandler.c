//
// Created by SimonD on 4/14/2020.
//

#include "menuHandler.h"

void printMainMenu(){
    printf("type the number corrisponding to the action you want to perform:\n"
           "0. Insert new order in queue\n"
           "1. Remove an order from queue\n"
           "2. Insert an order in the shipping stack\n"
           "3. Remove order from stack because has been shipped\n"
           "4. Process first order automatically\n"
           "5. Print Order's queue\n"
           "6. Print Shipping's stack\n"
           "7. Exit\n");
}

void processUserAction(Queue* orderQueue, Stack* orderStack){
    menuItem selectedOption = (menuItem) getNumericAnswerFromUser(7);
    Ordine tmpOrder;

    switch (selectedOption){
        case ADD_ORDER_TO_QUEUE:
            tmpOrder = getOrderFromUser();
            pushQueue(orderQueue, tmpOrder);
            break;
        case REMOVE_ORDER_FROM_QUEUE:
            if(isEmptyQueue(orderQueue))
                printf("The queue is already empty\n");
            else{
                printf("Removed ");
                tmpOrder = popQueue(orderQueue);
                printOrder(tmpOrder);
            }
            break;
        case ADD_ORDER_TO_SHIPMENT_STACK:
            tmpOrder = getOrderFromUser();
            pushStack(orderStack, tmpOrder);
            break;
        case REMOVE_ORDER_FROM_SHIPMENT_STACK:
            if(isEmptyStack(orderStack))
                printf("The stack is already empty\n");
            else {
                printf("Removed ");
                tmpOrder = popStack(orderStack);
                printOrder(tmpOrder);
            }
            break;
        case PROCESS_FIRST_ORDER_AUTOMATICALLY:
            tmpOrder = popQueue(orderQueue);
            pushStack(orderStack, tmpOrder);
            break;
        case PRINT_QUEUE:
            printQueue(orderQueue);
            break;
        case PRINT_STACK:
            printStack(orderStack);
            break;
        case EXIT:
            exit(0); // success exit

        default:
            printf("Error selecting an opion");
            break;
    }
}

/**
 * This function provides a fast and higly reusable way to get the the input from the user.
 * This function is used as a standard way to ask for a numeric input in the whole project
 * @param maxOptionAvailable represents the Maximum included enumeration number selectable by the user
 * @return returns a valid enumeration from the user input (between 0 and maxOptionAvailable)
 */
int getNumericAnswerFromUser(int maxOptionAvailable){
    int userAnswer = -1;
    _Bool invalidInputEntered;

    // Asks for an option until it gets entered correctly
    do {
        printf("=> ");
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

Ordine getOrderFromUser(){
    Ordine newOrder;
    printf("\nwelcome to the insert order wizard, please type the requested info:\n");

    printf("type order name:\n");
    scanf("%[^\n]", newOrder.articolo);
    getchar();

    printf("type the order price:\n");
    scanf("%lf", &newOrder.prezzo);
    getchar();

    printf("type the order receiver:\n");
    scanf("%[^\n]", newOrder.destinatario);
    getchar();

    return newOrder;
}

void printOrder(Ordine order){
    printf("PRINTING ORDER:\n"
           "Article : %s\n"
           "Price: %lf\n"
           "Receiver: %s\n",order.articolo,order.prezzo,order.destinatario);
}

void printStack(Stack* s){
    Ordine tmpOrder;
    while (!isEmptyStack(s)){
        tmpOrder = popStack(s);
        printOrder(tmpOrder);
    }
}

void printQueue(Queue* q){
    Ordine tmpOrder;
    while (!isEmptyQueue(q)){
        tmpOrder = popQueue(q);
        printOrder(tmpOrder);
    }
}
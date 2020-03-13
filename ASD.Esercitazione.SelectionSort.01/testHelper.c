//
// Created by SimonD on 3/3/2020.
//

#include "testHelper.h"


int* getGeneratedArrayOfIntegers(inputType type, int size){
    switch (type){
        case ORDINATO:
            return _generateSortedArrayOfIntegers(size);
        case QUASI_ORDINATO:
            return _generatePartiallySortedData(size);
        case INV_ORDINATO:
            return _generateSortedArrayOfIntegersDesc(size);
        case CASUALE:
            return _generateRandomArrayOfIntegers(size);
        default:
            printf("Error inside  press a key to terminate");
            getchar();
            exit(-1);
    }
}

RecipieAndSize getArrayOfRecipesFromUser(){
    int size;
    Ricetta* arrayRecipes;
    printf("Type the number of recipes you want to enter: ");
    scanf("%d", &size);
    arrayRecipes = (Ricetta*) malloc(size * sizeof(Ricetta));
    RecipieAndSize result;

    for (int i = 0; i < size; ++i) {
        printf("Type the recipes %d/%d", i+1, size);
        printf("\nName: ");
        getchar();
        scanf("%[^\n]", arrayRecipes[i].nome);
        printf("Time: ");
        getchar();
        scanf("%lf", &arrayRecipes[i].tempo);
        printf("Difficulty: ");
        scanf("%d", &arrayRecipes[i].difficolta);
    }
    result.recipie = arrayRecipes;
    result.size = size;
    return result;
}

/**
 * Usage: put this function after scanf so that the next one will have a clean stream
 * in particular the invisible enemies.. the "\n"
 */
void freeTheBuffer(){
    while ( getchar() != '\n' );
}

/**
 * This will work as a private method to generate an array of integers of the given length
 * with random data inside
 * @param size is the array to be generated size
 * @return an array of int of the given size with random data
 */
int* _generateRandomArrayOfIntegers(int size){
    int* data = (int*) malloc(sizeof(int) * size);
    int i = 0;

    for (i = 0; i < size; ++i) {
        data[i] = rand() % MAX_RAND;
    }

    return data;
}

/**
 * This will work as a private method to generate an array of integers of the given length
 * with sorted data ( 0 to <size> )
 * @param size is the array to be generated size
 * @return an array of int of the given size with sorted data
 */
int* _generateSortedArrayOfIntegers(int size){
    int* data = (int*) malloc(sizeof(int) * size);
    int i = 0;

    for (i = 0; i < size; ++i) {
        data[i] = i;
    }

    return data;
}

/**
 * This will work as a private method to generate an array of integers of the given length
 * with reverse sorted data ( <size> to 0 )
 * @param size is the array to be generated size
 * @return an array of int of the given size with inverse sorted data
 */
int* _generateSortedArrayOfIntegersDesc(int size){
    int* data = (int*) malloc(sizeof(int) * size);
    int i ;

    for (i = 0; i < size ; ++i) {
        data[i] = size - i;
    }

    return data;
}

int* _generatePartiallySortedData(int size){
    int* data = (int*) malloc(sizeof(int) * size);
    int halfIdx = size / 2;
    int i;

    // generating random data for half of the array into firstHalfRandom
    int* firstHalfRandom = _generateRandomArrayOfIntegers(halfIdx);
    // copying the first half of random data into the array to be returned
    for (i = 0; i < halfIdx; ++i) {
        data[i] = firstHalfRandom[i];
    }
    // generating the rest of the data sequentially
    for (i = halfIdx; i < size; ++i) {
        data[i] = i;
    }
    return data;
}

void printIntegerArray(int* data, int size){
    int i = 0;
    for (i = 0; i < size; ++i) {
        printf("[%d] --> %d\n", i, data[i]);
    }
}

void printRecipesArray(Ricetta* data, int size){
    int i = 0;
    for (i = 0; i < size; ++i) {
        printf("name:       %s\n", data[i].nome);
        printf("time:       %lf\n",data[i].tempo);
        printf("difficulty: %d\n\n", data[i].difficolta);
    }
}
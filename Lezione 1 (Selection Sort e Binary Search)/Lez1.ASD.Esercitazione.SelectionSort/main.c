#include <stdio.h>
#include "testHelper.h"
#include "selectionSort.h"
#include <time.h>
#define N_ITEMS 100

void recipesSortingRoutine();

void intSortRoutine();

/*
* use getGeneratedArrayOfIntegers(inputType, size) to generate test data
* use selectionSort to sort the data
* use printIntegerArray if you want a facility to print the array in console
*/


int main() {
    srand(time(NULL));

    // MENU
    printf("Type 0 to run selection sort on array of recipes\n"
           "Type 1 to run selection sort on array of integers");
    int userSelection = getNumericAnswerFromUser(1);

    // RUN THE SELECTED TEST TO BE RUN
    if(userSelection == 0){
        recipesSortingRoutine();
    } else{
        intSortRoutine();
    }

    return 0;
}

/* EXERCISE WITH INTEGERS */
void intSortRoutine() {
    int* dataTest = getGeneratedArrayOfIntegers(CASUALE, N_ITEMS);
    printIntegerArray(dataTest, N_ITEMS);
    debugSelectionSort(dataTest, N_ITEMS);
    printIntegerArray(dataTest, N_ITEMS);
}

/* RECIPES EXERCISE */
void recipesSortingRoutine() {
    // Get an array of recipes from the user
    RecipieAndSize recepies =  getArrayOfRecipesFromUser();

    // Sorting array of recipes  with a modified selection sort
    selectionSortRecepies(recepies.recipie, recepies.size);

    // Printing result
    printf("Printing sorted array of recipes\n\n");
    printRecipesArray(recepies.recipie, recepies.size);
}


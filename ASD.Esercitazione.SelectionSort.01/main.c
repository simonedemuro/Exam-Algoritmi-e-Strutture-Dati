#include <stdio.h>
#include "testHelper.h"
#include "selectionSort.h"
#include <time.h>
#define N_ITEMS 10000

/**
 * use getGeneratedArrayOfIntegers(inputType, size) to generate test data
 * use selectionSort to sort the data
 * use printIntegerArray if you want a facility to print the array in console
 * @return
 */
int main() {
    srand(time(NULL));

    RecipieAndSize recepies =  getArrayOfRecipesFromUser();
    selectionSortRecepies(recepies.recipie, recepies.size);
    printRecipesArray(recepies.recipie, recepies.size);

    //int* dataTest = getGeneratedArrayOfIntegers(CASUALE, N_ITEMS);
    //printIntegerArray(dataTest, N_ITEMS);
    //debugSelectionSort(dataTest, N_ITEMS);
    //printIntegerArray(dataTest, N_ITEMS);

    return 0;
}


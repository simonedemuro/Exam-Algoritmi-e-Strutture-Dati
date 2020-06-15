#include <stdio.h>
#include <time.h>
#include "Models/models.h"
#include "SortEngine/selectionSortIter.h"
#include "SortEngine/insertionSort.h"
#include "SortEngine/quickSort.h"
#include "SortEngine/heapSort.h"
#include "SortEngine/mergeSort.h"
#include "TestGenerator/dataGenerator.h"
#include "TestGenerator/testHelper.h"

#define N_SORT_ALGORITHM 5
#define N_SIZES_TO_BE_TESTED 7
#define N_TYPE_OF_INPUT 4

void runBenchmark();
void manualTestRoutine();

int main() {
    // Setup Menu:
    mainMenuUserChoice userOperation;
    printf(APPLICATION_LOGO);
    
    // Run Wizard
    do {
        printf(MAIN_MENU);
        userOperation = getNumericAnswerFromUser(2);
        
        if (userOperation == AUTOMATIC_REPO)
            runBenchmark();
        else if (userOperation == MANUAL_TEST)
            manualTestRoutine();
    } while (userOperation != QUIT_APPLICATION);
    
    return 0;
}

/**
 * This Function Will automatically produce a report in the console showing the number of comparison, number of swaps
 * and time elapsed for the computation.
 * sortingAlgorithms is a list of delegates (pointer to function) used to automatically run sorting functions
 */
void runBenchmark(){
    /*   TEST SETUP   */
    // Array of Sizes to be tested:
    int size[N_SIZES_TO_BE_TESTED] = {500,1000,2000,5000,10000,20000,50000};

    // ARRAY OF pointers to SORTING FUNCTIONS
    void (*sortingAlgorithms[N_SORT_ALGORITHM])(int*,int,int*,int*) = {
            selectionSort,
            insertionSort,
            mergeSortP,
            heapsort,
            quickSortPublic
    };


    openFile();
    // FOR EACH type of input {ORDINATO, QUASI_ORDINATO, INV_ORDINATO, CASUALE}
    for (inputType inputType = 0; inputType < N_TYPE_OF_INPUT; ++inputType) {
        // FOR EACH Sort Algorithm perform 	{1000, 2000, 5000, 10000, 20000, 50000} elements test
        for (int algorithmN = 0; algorithmN < N_SORT_ALGORITHM; ++algorithmN) {
            // FOR EACH size to be tested..
            nextLineOnFile();
            for (int inputSize = 0; inputSize < N_SIZES_TO_BE_TESTED; ++inputSize) {
//                printf("\n%s \n input size: %d \t type: %s\n",
//                        getAlgorithmNameByIndex(algorithmN), size[inputSize], getSortingTypeNameByIndex(inputType));
                int* intArray = getGeneratedArrayOfIntegers(inputType, size[inputSize]); // Generate test data:
                sortBenchmark(sortingAlgorithms[algorithmN], intArray, size[inputSize]); // Sort Data
            }
        }
        nextLineOnFile();
        nextLineOnFile();
        nextLineOnFile();
        nextLineOnFile();
    }
    closeFile();
}

/**
 * This Routine will fit the tester's need to test individually the desired algorithm
 * with custom settings by following the Wizard.
 */
void manualTestRoutine(){
    // SETUP user choices:
    int algorithmNum, dataSize, isPrintEnabled;
    inputType sortingType;

    // ARRAY OF pointers to SORTING FUNCTIONS
    void (*sortingAlgorithms[N_SORT_ALGORITHM])(int*,int,int*,int*) = {
            selectionSort,
            insertionSort,
            quickSortPublic,
            heapsort,
            mergeSortP
    };

    printf(MANUAL_TEST_MENU);
    algorithmNum = getNumericAnswerFromUser(4);
    printf("Type the input size:\n");
    scanf("%d", &dataSize);
    getchar();
    printf(MOCK_TYPE_MESSAGE);
    sortingType = getNumericAnswerFromUser(3);

    printf("Do you want to print the data before and after the sort? (1 -> yes/ other -> no)");
    scanf("%d", &isPrintEnabled);
    getchar();

    int* data = getGeneratedArrayOfIntegers(sortingType, dataSize);

    conditionallyPrint(dataSize, isPrintEnabled, data);
    // ACTUAL SORTING HERE
    sortBenchmark(sortingAlgorithms[algorithmNum], data, dataSize);
    conditionallyPrint(dataSize, isPrintEnabled, data);
}
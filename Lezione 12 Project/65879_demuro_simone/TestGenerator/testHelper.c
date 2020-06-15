//
// Created by SimonD on 5/31/2020.
//

#include "testHelper.h"

void freeTheBuffer();

FILE* fp = NULL;
void openFile(){
    fp = fopen("tests.txt","w");
}

void printOnFile(double time, int swap, int comparison){
    if (fp != NULL) {
        fprintf(fp, "%d\t%d\t%lf\t", comparison, swap, time);
    }
}

void nextLineOnFile(){
    fprintf(fp, "\n");
}

void closeFile(){
    fclose(fp);
}

report sortBenchmark(void (*sortAlgorithm)(int*,int,int*,int*), int* data, int size){
    // Init performance measure
    clock_t start, stop;
    double elapsedSeconds;
    int nCompare = 0;
    int nSwap = 0;
    start = clock();

    // CALLING THE ACTUAL SORTING ALGORITHM
    sortAlgorithm(data,size, &nCompare, &nSwap);

    // stop sort and print milliseconds
    stop = clock();
    elapsedSeconds = ((double) (stop - start)) / CLOCKS_PER_SEC;

    printOnFile(elapsedSeconds, nSwap, nCompare);
}

const char* getAlgorithmNameByIndex(int algorithmIndex){
    char *name;
    switch (algorithmIndex){
        case 0:
            name = "SelectionSort";
            break;
        case 1:
            name = "insertionSort";
            break;
        case 2:
            name = "quickSort";
            break;
        case 3:
            name = "heapSort";
            break;
        case 4:
            name = "mergeSort";
            break;
        default:
            name = "Error inside getAlgorithmNameByIndex";
            break;
    }
    return name;
}

const char* getSortingTypeNameByIndex(int algorithmIndex){
    char *name;
    switch (algorithmIndex){
        case ORDINATO:
            name = "Sorted";
            break;
        case QUASI_ORDINATO:
            name = "AlmostSorted";
            break;
        case INV_ORDINATO:
            name = "ReverseSorted";
            break;
        case CASUALE:
            name = "Random";
            break;
        default:
            name = "Error inside getAlgorithmNameByIndex";
            break;
    }
    return name;
}

void conditionallyPrint(int dataSize, int isPrintEnabled, int *data) {
    if(isPrintEnabled == 1)
        printIntegerArray(data, dataSize);
}

/**
 *  ask for a numeric input and prompt again in case of invalid input
 * @param maxOptionAvailable represents the Maximum included enumeration number selectable by the user
 * @return returns a valid enumeration from the user input (between 0 and maxOptionAvailable)
 */
int getNumericAnswerFromUser(int maxOptionAvailable){
    int userAnswer = -1;
    _Bool invalidInputEntered;

    // Asks for an option until it gets entered correctly
    do {
        scanf("%d", &userAnswer);
        freeTheBuffer();

        // checks if the value is between 1 and the maximum option available for this command
        invalidInputEntered = userAnswer < 0 || userAnswer > maxOptionAvailable;
        if(invalidInputEntered){
            printf("please enter a valid input\n");
        }
    } while(invalidInputEntered);
    //than returns a certainly valid input
    return userAnswer;
}

/**
 * Usage: put this function after scanf so that the next one will have a clean stream
 * in particular the invisible enemies.. the "\n"
 */
void freeTheBuffer(){
    while ( getchar() != '\n' );
}

//void (*selectionSort1)(int*,int,int*,int*) = selectionSort;
//void (*insertionSort1)(int*,int,int*,int*) = insertionSort;
//void (*quickSort1)(int*,int,int*,int*) = quickSortPublic;
//void (*heapSort1)(int*,int,int*,int*) = heapsort;
//void (*mergeSort1)(int*,int,int*,int*) = mergeSortP;
//sortBenchmark(mergeSort1, data, size);

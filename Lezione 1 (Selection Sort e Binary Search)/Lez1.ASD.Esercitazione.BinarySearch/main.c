#include <stdio.h>
#include "testDataGeneration.h"
#include "searchAlgorithms.h"

typedef enum { LINEAR, BINARY_REC, BINARY_ITAER }typeOfSearch;

int main() {
    // INIT:
    int inputSize, numberToSearchFor;
    typeOfSearch searchTypeToBePerformed;
    int* dataToBeSorted;

    // MENU:
    printf("DICHOTOMIC SEARCH tester\n"
           "Type the input size you want generate: \n");
    scanf("%d",&inputSize);
    printf("Type the number to search for: \n");
    scanf("%d",&numberToSearchFor);
    printf("type the type of search you want to perform:\n"
           "0 -> linear\n"
           "1 -> dichotomic search recursive\n"
           "2 -> dichotomic search iterative\n");
    scanf("%d",&searchTypeToBePerformed);

    // GENERATING TEST DATA & PERFORMING SEARCH
    dataToBeSorted = generateSortedArrayOfInt(inputSize);
    if (searchTypeToBePerformed == LINEAR){
        debugLinearSearch(dataToBeSorted, numberToSearchFor, inputSize);
    } else if(searchTypeToBePerformed == BINARY_ITAER){
        debugBinaryIterativeSearch(dataToBeSorted, numberToSearchFor, inputSize);
    } else if (searchTypeToBePerformed == BINARY_REC){
        debugBinaryRecursiveSearch(dataToBeSorted, numberToSearchFor, inputSize);
    }

    return 0;
}
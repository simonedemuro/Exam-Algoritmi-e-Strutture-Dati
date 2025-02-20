//
// Created by demu9 on 3/13/2020.
//
#include <time.h>
#include "searchAlgorithms.h"
#include "selectionSort.h"

int linearSearch(int* arrayData, int numToSearchFor, int arraySize){
    int index = 0;
    while(index < arraySize && arrayData[index] <= numToSearchFor){
        if(arrayData[index] == numToSearchFor)
            return index;
        index++;
    }
    return -1; // item not found
}

int recursiveBinarySearch(int* arrayData, int numToSearchFor, int first, int last){
    if (first > last)
        return -1;
    int half = (first+last)/2;

    if(arrayData[half] == numToSearchFor)
        return half;
    else if(arrayData[half] < numToSearchFor)
        return recursiveBinarySearch(arrayData, numToSearchFor, half+1, last);
    return recursiveBinarySearch(arrayData, numToSearchFor, first, half-1);
}

int binaryIterativeSearch(int* arrayData, int numToSearchFor, int arraySize){
    int firstIdx = 0;
    int lastIdx = arraySize - 1;
    int halfIdx;

    while (firstIdx <= lastIdx){
        halfIdx = (firstIdx + lastIdx)/2;
        if(numToSearchFor < arrayData[halfIdx])
            lastIdx = halfIdx - 1;
        else if (numToSearchFor == arrayData[halfIdx])
            return halfIdx;
        else
            firstIdx = halfIdx + 1;
    }
    return -1;
}

void debugBinaryRecursiveSearch(int* arrayData, int numToSearchFor, int arraySize){
    // Init performance measure
    clock_t start, stop;
    double elapsedSeconds;
    start = clock();

    // running actual sort
    recursiveBinarySearch(arrayData, numToSearchFor, 0, arraySize);

    // stop sort and print milliseconds
    stop = clock();
    elapsedSeconds = ((double) (stop - start)) / CLOCKS_PER_SEC;
    printf("Binary Search Iterative for %d items took: %lf sec\n",arraySize, elapsedSeconds);
}

void debugBinaryIterativeSearch(int* arrayData, int numToSearchFor, int arraySize){
    // Init performance measure
    clock_t start, stop;
    double elapsedSeconds;
    start = clock();

    // running actual sort
    binaryIterativeSearch(arrayData, numToSearchFor, arraySize);

    // stop sort and print milliseconds
    stop = clock();
    elapsedSeconds = ((double) (stop - start)) / CLOCKS_PER_SEC;
    printf("Binary Search Iterative for %d items took: %lf sec\n",arraySize, elapsedSeconds);
}

void debugLinearSearch(int* arrayData, int numToSearchFor, int arraySize){
    // Init performance measure
    clock_t start, stop;
    double elapsedSeconds;
    start = clock();

    // running actual sort
    linearSearch(arrayData, numToSearchFor, arraySize);

    // stop sort and print milliseconds
    stop = clock();
    elapsedSeconds = ((double) (stop - start)) / CLOCKS_PER_SEC;
    printf("Linear Search for %d items took: %lf sec\n",arraySize, elapsedSeconds);
}
//
// Created by SimonD on 3/24/2020.
//

#include "BinarySearch.h"
#include "models.h"
#include <string.h>

int binaryIterativeSearch(Hotel* arrayData, char* hotelName, int arraySize){
    int firstIdx = 0;
    int lastIdx = arraySize - 1;
    int halfIdx;

    while (firstIdx <= lastIdx){
        halfIdx = (firstIdx + lastIdx)/2;
        if(strcmp(hotelName, arrayData[halfIdx].nome) < 0)
            lastIdx = halfIdx - 1;
        else if ( strcmp(hotelName,arrayData[halfIdx].nome) == 0)
            return halfIdx;
        else
            firstIdx = halfIdx + 1;
    }
    return -1;
}
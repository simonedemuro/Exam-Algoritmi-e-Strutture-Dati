#include <stdio.h>
#include "models.h"
#include "BinarySearch.h"

/*
 * THIS PROJECT DOES NOT HAVE A MENU, PLEASE TEST THE CODE BY CHANGING THE PARAMETERS IN THE CODE AND
 * BY RUNNING THE APPLICATION AGAIN.
 * */

int main() {
    int foundIndex = 0;

    // List of Mock data
    Hotel hotels[] = {
            {"Abamar",                        40, 4},
            {"Altura",                        50, 5},
            {"Centrale",                      10, 3},
            {"Flamingo",                      30, 4},
            {"Sant Efis",                     20, 2},
            {"Tanka Village",                 40, 3},
    };

    // performing a simple search CHANGE HERE THE HOTEL NAME
    foundIndex = binaryIterativeSearch(hotels,"Centrale", 6);

    if(foundIndex != -1)
        printf("hotel found at index: %d", foundIndex);
    else
        printf("Hotel not fond");

    return 0;
}
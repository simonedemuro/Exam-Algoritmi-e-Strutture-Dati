#include <stdio.h>
#include "testHelper.h"
#include <time.h>

int main() {
    srand(time(NULL));
    printf("Hello, World!\n");

    int* sortedIntArray = getGeneratedArrayOfIntegers(QUASI_ORDINATO, 100);
    printIntegerArray(sortedIntArray, 100);

    return 0;
}

//void swap(int* a, int*b )
//{
//    int tmp = *b;
//    *b = *a;
//    *a = tmp;
//}
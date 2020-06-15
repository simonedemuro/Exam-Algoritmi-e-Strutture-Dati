#include <stdio.h>
#include "models.h"
#include "selectionSort.h"
#include "testHelper.h"

/* THE FOLLOWING CODE LETS YOU COMPARE THE PERFORMANCES OF BOTH SELECTION SORT ITERATIVE AND RECURSIVE
 * THE MENU FOR THIS APPLICATION IS NOT PROVIDED PLEASE CHANGE THE SETTINGS IN THE CODE BELOW AND RUN.
 * */

int main() {
    // please set the data to be sorted size below:
    int dataSize = 100;
    int* data = NULL;

    // RECURSIVE
    data= getGeneratedArrayOfIntegers(CASUALE, dataSize);
    debugSelectionSort(RECURSIVE, data, dataSize);

    // ITERATIVE
    data = getGeneratedArrayOfIntegers(CASUALE, dataSize);
    debugSelectionSort(ITERATIVE, data, dataSize);

    return 0;
}
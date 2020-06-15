#include <stdio.h>
#include "searchKMP.h"

/* I FELT MORE INTUITIVE TRY THE FOLLOWING FUNCTIONS FROM CODE THAN FROM A MENU
 * IN ORDER TO TEST THE PROJECT FILL THE VARIABLES IN THE INIT SECTION AND RUN
 * THE APPLICATION.
 * */

int main() {
    // INIT:
    char text[] = "ACAGAGT";
    char pattern[] = "GT";

    // KMP SEARCH:
    int index = KMPindexOf("ACAGAGT", "GT");
    printf("the index of %s inside %s is %d\n", pattern, text ,index);

    // CYCLIC ROTATIONS:
    printf("abcde vs deabc : %s\n", isCyclic("abcde","deabc")?"true":"false");
    printf("eabcd vs eabcz : %s\n", isCyclic("eabcd","eabcz")?"true":"false");

    return 0;
}
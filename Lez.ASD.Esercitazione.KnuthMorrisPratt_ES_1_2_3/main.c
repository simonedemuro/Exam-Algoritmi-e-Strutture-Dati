#include <stdio.h>
#include "searchKMP.h"

int main() {
    int test = KMPindexOf("ACAGAGT","GT");
    printf("the index of GT inside ACAGAGT is %d\n", test);

    printf("abcde vs deabc : %s\n", isCyclic("abcde","deabc")?"true":"false");
    printf("eabcd vs eabcz : %s\n", isCyclic("eabcd","eabcz")?"true":"false");

    return 0;
}
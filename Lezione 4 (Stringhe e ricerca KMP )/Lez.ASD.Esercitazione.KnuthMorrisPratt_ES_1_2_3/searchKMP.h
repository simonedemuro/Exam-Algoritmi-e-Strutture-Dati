//
// Created by SimonD on 4/7/2020.
//

#ifndef LEZ_ASD_ESERCITAZIONE_KNUTHMORRISPRATT_ES_1_2_3_SEARCHKMP_H
#define LEZ_ASD_ESERCITAZIONE_KNUTHMORRISPRATT_ES_1_2_3_SEARCHKMP_H

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int* insuccesso(char* pat);
int KMPindexOf(char* str, char* path);
_Bool isCyclic(char* str1, char* str2);

#endif //LEZ_ASD_ESERCITAZIONE_KNUTHMORRISPRATT_ES_1_2_3_SEARCHKMP_H

//
// Created by SimonD on 4/7/2020.
//

#include "searchKMP.h"

int* insuccesso(char* pat){
    int n;
    int j;
    int i;
    n = (int)strlen(pat);
    int* insuccesso = (int*) malloc(n* sizeof(int));

    insuccesso[0] = -1; // first element cannot be prefix and suffix at the same time

    for (j = 1; j < n; ++j) {
        i = insuccesso[j-1];
        while(pat[j] != pat[i+1] && i>0){
            i = insuccesso[i];
        }
        if (pat[j] == pat[i+1])
            insuccesso[j] = i+1;
        else
            insuccesso[j] = -1;
    }
    return insuccesso;
}

int KMPindexOf(char* str, char* path){
    int* insucc = insuccesso(path);
    int i=0;
    int j=0;
    int lenStr = (int)strlen(str);
    int lenPat = (int)strlen(path);
    
    while(i < lenStr && j < lenPat){
        if(str[i] == path[j]){
            i = i+1;
            j = j+1;
        }
        else if (j == 0){
            i = i+1;
        }
        else{
            j = insucc[j-1]+1;
        }
    }
    if (j == lenPat){
        return i - lenPat;
    }
    return -1;
}

_Bool isCyclic(char* str1, char* str2){
    int* insucc = insuccesso(str2);
    int i=0;
    int j=0;
    int lenStr = (int)strlen(str1);
    int lenPat = (int)strlen(str2);

    if (lenStr != lenPat)
        return false;

    while(i < (lenStr*2) && j < lenPat){
        if(str1[i%lenStr] == str2[j]){
            i = i+1;
            j = j+1;
        }
        else if (j == 0){
            i = i+1;
        }
        else{
            j = insucc[j-1]+1;
        }
    }
    if (j == lenPat){
        return true;
    }
    return false;
}
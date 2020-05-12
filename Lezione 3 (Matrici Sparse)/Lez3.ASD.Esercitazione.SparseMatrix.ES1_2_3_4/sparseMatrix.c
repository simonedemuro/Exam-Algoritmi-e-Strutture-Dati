//
// Created by SimonD on 3/31/2020.
//

#include "sparseMatrix.h"
#include "models.h"
#include <stdlib.h>
#include <stdio.h>

// initializing the matrix with a given number of rows x columns
sparseMatrix* initSparseMatrix(int rows, int cols){
    sparseMatrix* matrix = (sparseMatrix*) malloc(1* sizeof(sparseMatrix));
    /* setting the header */
    matrix[0].row = rows;
    matrix[0].col = cols;
    matrix[0].val = 0;
    return matrix;
}

sparseMatrix* addItemToSparseMatrix(sparseMatrix* matrix, sparseMatrix item){
    matrix[0].val += 1;  // since I'm adding an item, increasing the header's non null counter
    matrix = (sparseMatrix*) realloc( matrix,  (matrix[0].val+1) * sizeof(sparseMatrix) ); // increasing in size accordingly

    // Now that I created the space to store the new item I can insert it:
    int currentIndex = matrix[0].val; // size-1 is current index (this variable is only for make the code readable)
    matrix[currentIndex].row = item.row;
    matrix[currentIndex].col = item.col;
    matrix[currentIndex].val = item.val;

    // returning the pointer
    return matrix;
}

void printSparseMatrix(sparseMatrix* matrix){
    int rows, cols;
    int r,c;
    int reachedElement=1; // is the element that as been reached since the loop started
    rows = matrix[0].row;
    cols = matrix[0].col;

    for (r = 0; r < rows; ++r) {
        for (c = 0; c < cols; ++c) {
            // if the <r,c> tuple is in the matrix, prints its value and search for the next (by increasing reachedElement)
            if (r == matrix[reachedElement].row && c == matrix[reachedElement].col){
                printf("%d\t", matrix[reachedElement].val);
                reachedElement++;
            } else{
                printf("%d\t", 0);
            }
        }
        printf("\n");
    }
}

sparseMatrix* searchElementSparseMatrix(sparseMatrix* matrix, int itemToSearchFor){
    int i, size;
    size = matrix[0].val;

    for (i = 1; i < size; ++i) {    // Note: Start from 1 to avoid Matrix header.
        if(matrix[i].val == itemToSearchFor)
            return &matrix[i];
    }
    return NULL; // if the element was not found return null
}

/*
algoritmo trasp_rapida(array di triple a, array di triple b)
num_col ← a[0].col
num_val ← a[0].valore
b[0].riga ← num_col
b[0].col ← a[0].riga
b[0].valore ← num_val
alloca dinamicamente il vettore termini_riga
alloca dinamicamente il vettore pos_iniziale
if (num_val > 0) then
// creazione termini_riga
for i ← 0 to num_col-1 do termini_riga[i] ← 0
for i ← 1 to num_val do termini_riga[a[i].col] ← termini_riga[a[i].col] + 1
//creazione pos_iniziale
pos_iniziale[0] ← 1
for i ← 1 to num_col-1 do pos_iniziale[i] ← pos_iniziale[i-1] + termini_riga[i-1]
//trasposizione
for i ← 1 to num_val do
cur_pos ← pos_iniziale[a[i].col]
pos_iniziale[a[i].col] ← pos_iniziale[a[i].col] + 1
b[cur_pos].riga ← a[i].col
b[cur_pos].col ← a[i].riga
b[cur_pos].valore ← a[i].valore
 */
void fastTranspose(sparseMatrix* inputMatrix, sparseMatrix* resultMatrix){
    int numCol = inputMatrix[0].col;
    int numVal = inputMatrix[0].val;
    int i, currentIdx;

    resultMatrix[0].row = numCol;
    resultMatrix[0].col = inputMatrix[0].row;
    resultMatrix[0].val = numVal;

    int* rowTerms = (int*) malloc(numCol * sizeof(int));
    int* startPos = (int*) malloc(numCol * sizeof(int));

    if(numVal > 0){
        // creazione termini_riga
        for (i = 0; i < numCol; ++i) {
            rowTerms[i] = 0;
        }
        for (i = 1; i <= numVal; ++i) {
            rowTerms[inputMatrix[i].col] = rowTerms[inputMatrix[i].col] + 1;
        }
    }
    //creazione pos_iniziale
    startPos[0]= 1;
    for (i = 1; i < numCol; ++i) {
        startPos[i] = startPos[i-1] + rowTerms[i-1];
    }

    //trasposizione
    for (i = 1; i <= numVal ; ++i) {
        currentIdx = startPos[inputMatrix[i].col];
        startPos[inputMatrix[i].col] = startPos[inputMatrix[i].col] + 1;
        resultMatrix[currentIdx].row = inputMatrix[i].col;
        resultMatrix[currentIdx].col = inputMatrix[i].row;
        resultMatrix[currentIdx].val = inputMatrix[i].val;
    }

}
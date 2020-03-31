//
// Created by SimonD on 3/31/2020.
//

#include "models.h"

#ifndef LEZ3_ASD_ESERCITAZIONE_SPARSEMATRIX_ES1_2_3_4_SPARSEMATRIX_H
#define LEZ3_ASD_ESERCITAZIONE_SPARSEMATRIX_ES1_2_3_4_SPARSEMATRIX_H

// initializing the matrix with a given number of rows x columns
sparseMatrix* initSparseMatrix(int rows, int cols);
sparseMatrix* addItemToSparseMatrix(sparseMatrix* matrix, sparseMatrix item);
void printSparseMatrix(sparseMatrix* matrix);
sparseMatrix* searchElementSparseMatrix(sparseMatrix* matrix, int itemToSearchFor);
void fastTranspose(sparseMatrix* inputMatrix, sparseMatrix* resultMatrix);

#endif //LEZ3_ASD_ESERCITAZIONE_SPARSEMATRIX_ES1_2_3_4_SPARSEMATRIX_H

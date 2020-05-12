#include <stdio.h>
#include <stdlib.h>
#include "sparseMatrix.h"

#define NUMC 15
#define NUMR 10

int numUsedIntegerClassic;  //variabile da usare per contare il numero di interi nella matrice tradizionale
int numUsedIntegerSparse;   //variabile da usare per contare il numero di interi nella matrice sparsa

void fill_classic_matrix(int matrix[][NUMC], int numr, int numc);
void print_classic_matrix(int matrix[][NUMC], int numr, int numc);
void search_element_in_classic_matrix(int matrix[][NUMC], int numr, int numc, int numric);

int main() {
    int matrix[NUMR][NUMC] = {{0}};
    int numric = 71;     // assegnare a numric il numero da cercare.

    // INIZIO TEST MATRICE CLASSICA
    fill_classic_matrix(matrix, NUMR, NUMC);
    printf("\n");
    print_classic_matrix(matrix, NUMR, NUMC);
    search_element_in_classic_matrix(matrix, NUMR, NUMC, numric);
    // FINE TEST MATRICE CLASSICA

    /*
    INIZIO TEST MATRICE SPARSA
    Implementare:*/
    //- creazione matrice sparsa, chiedendo le triple in input (per testare il corretto funzionamento: inserite gli stessi valori della matrice classica, vedi slide)

    sparseMatrix* spMatrix = initSparseMatrix(10, 15);
    spMatrix = addItemToSparseMatrix(spMatrix, (sparseMatrix) {1, 0, 71});
    spMatrix = addItemToSparseMatrix(spMatrix, (sparseMatrix) {2, 14,  99});
    spMatrix = addItemToSparseMatrix(spMatrix, (sparseMatrix) {3, 11,  53});
    spMatrix = addItemToSparseMatrix(spMatrix, (sparseMatrix) {4, 7, 95});
    spMatrix = addItemToSparseMatrix(spMatrix, (sparseMatrix) {6, 14,  39});
    spMatrix = addItemToSparseMatrix(spMatrix, (sparseMatrix) {8, 1, 27});
    spMatrix = addItemToSparseMatrix(spMatrix, (sparseMatrix) {9, 14,  14});

    //    - stampa matrice sparsa
    printf("\nprinting input sparse matrix:\n");
    printSparseMatrix(spMatrix);

    //    - ricerca di un elemento all'interno della matrice sparsa
    sparseMatrix* searchedElement = searchElementSparseMatrix(spMatrix, 99);
    printf("\nelement found at row: %d col: %d, value= %d"
            ,searchedElement->row,searchedElement->col,searchedElement->val);

    //    - trasposizione rapida della matrice sparsa.
    sparseMatrix* transposedMatrix = (sparseMatrix*) malloc( 8 * sizeof(sparseMatrix));
    fastTranspose(spMatrix, transposedMatrix);

    printf("\nprinting transposed matrix:\n");
    printSparseMatrix(transposedMatrix);

    /*FINE TEST MATRICE SPARSA
    */

    return 0;
}

// Funzione che riempie (con i valori dell'esempio presenti nelle slide della lezione 3) la matrice classica passata in ingresso
void fill_classic_matrix(int matrix[][NUMC], int numr, int numc)
{
    matrix[1][0] = 71;
    matrix[2][14] = 99;
    matrix[3][11] = 53;
    matrix[4][7] = 95;
    matrix[6][14] = 39;
    matrix[8][1] = 27;
    matrix[9][14] = 14;
}

// Funzione che stampa a video una matrice classica
void print_classic_matrix(int matrix[][NUMC], int numr, int numc)
{
    int i, j = 0;
    for(i=0; i<numr; i++)
    {
        for(j=0; j<numc; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

}

// Funzione che implementa la ricerca di un elemento (numric) in una matrice classica
void search_element_in_classic_matrix(int matrix[][NUMC], int numr, int numc, int numric)
{
    int i, j = 0;
    for(i=0; i<numr; i++)
    {
        for(j=0; j<numc; j++)
        {
            if(matrix[i][j] == numric)
            {
                printf("Elemento %d trovato in posizione (%d, %d).\n", numric, i, j);
                return;
            }
        }
    }
    printf("Elemento non trovato.\n");
}
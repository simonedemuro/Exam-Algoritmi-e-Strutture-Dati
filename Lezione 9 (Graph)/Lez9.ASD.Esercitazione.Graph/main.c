#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "models.h"
#include "structuresImplementation.h"


int main()
{
    // TEST SETUP:
    Citta grafo[MAX_VERTICI];
    int num_nodi=0;
    int *visited = (int*)calloc(NUM_NODI_TEST, sizeof(int));
    int selectedOption;

    do {
        //Inserire qui le chiamate per testare le varie funzioni e il menu
        printf("\n\nType the operation to perform\n"
               "0     - load test data\n"
               "1     - DFS Visit\n"
               "2     - BFS Visit\n"
               "3     - print connected components\n"
               "4     - delete arch\n"
               "other - exit\n");
        scanf("%d", &selectedOption);

        switch (selectedOption) {
            case LOAD_TEST_DATA:
                num_nodi = 11;
                carica_citta_test(grafo);
                carica_grafo_test_orientato(grafo, num_nodi);
                break;
            case DFS_VISIT:
                printf("\n\n DFS \n");
                fflush(NULL);

                emptyIntArray(visited, num_nodi);
                DFS(grafo, visited, 0);

                break;
            case BFS_VISIT:
                printf("\n\n BFS \n");
                fflush(NULL);

                emptyIntArray(visited, num_nodi);
                BFS(grafo, visited, 0);
                break;
            case CONNECTED_COMPONENTS:
                printf("\n\n Connected components \n");
                fflush(NULL);

                emptyIntArray(visited, num_nodi);
                componenti_connesse(grafo, visited, num_nodi);
                break;
            case DELETE_ARCH:
                printf("\n\n deleting 8->9 arch \n");
                fflush(NULL);

                cancella_arco_non_orientato(grafo, 8, 9, num_nodi);
                emptyIntArray(visited, num_nodi);
                break;
            default:
                break;
        }
    } while (selectedOption >= 0 && selectedOption <= 4);
}

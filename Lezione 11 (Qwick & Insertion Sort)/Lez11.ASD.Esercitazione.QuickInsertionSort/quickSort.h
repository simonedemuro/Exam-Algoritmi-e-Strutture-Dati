//
// Created by SimonD on 6/1/2020.
//

#ifndef LEZ11_ASD_ESERCITAZIONE_QUICKINSERTIONSORT_QUICKSORT_H
#define LEZ11_ASD_ESERCITAZIONE_QUICKINSERTIONSORT_QUICKSORT_H


void quickSort(int lista[], int u, int v);
void quickInsertionSort(int data[], int fromIdx, int toIdx, int swithcAlgoritmThreshold);

// Since perno and swap are not used by thirds they better stay private:
//int perno(int lista[], int primo, int ultimo);
//void swap(int *vett, int i, int j);
//void insertionSortMod(int *data, int from, int to);


#endif //LEZ11_ASD_ESERCITAZIONE_QUICKINSERTIONSORT_QUICKSORT_H

cmake_minimum_required(VERSION 3.15)
project(65879_demuro_simone C)

set(CMAKE_C_STANDARD 99)

add_executable(65879_demuro_simone main.c SortEngine/selectionSortIter.c SortEngine/selectionSortIter.h SortEngine/insertionSort.c SortEngine/insertionSort.h SortEngine/quickSort.c SortEngine/quickSort.h SortEngine/heapSort.c SortEngine/heapSort.h SortEngine/mergeSort.c SortEngine/mergeSort.h TestGenerator/dataGenerator.c TestGenerator/dataGenerator.h Models/models.h TestGenerator/testHelper.c TestGenerator/testHelper.h)
cmake_minimum_required(VERSION 3.15)
project(ASD_Esercitazione_BinarySearch_01 C)

set(CMAKE_C_STANDARD 99)

add_executable(ASD_Esercitazione_BinarySearch_01 main.c selectionSort.c selectionSort.h testDataGeneration.c testDataGeneration.h searchAlgorithms.c searchAlgorithms.h)
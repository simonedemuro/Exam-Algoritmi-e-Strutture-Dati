cmake_minimum_required(VERSION 3.15)
project(ASD_Esercitazione_SelectionSort_02 C)

set(CMAKE_C_STANDARD 99)

add_executable(ASD_Esercitazione_SelectionSort_02 main.c testHelper.c testHelper.h models.h selectionSort.c selectionSort.h)
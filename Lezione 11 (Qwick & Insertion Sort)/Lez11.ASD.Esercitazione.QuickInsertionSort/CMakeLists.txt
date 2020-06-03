cmake_minimum_required(VERSION 3.15)
project(Lez11_ASD_Esercitazione_QuickInsertionSort C)

set(CMAKE_C_STANDARD 99)

add_executable(Lez11_ASD_Esercitazione_QuickInsertionSort main.c insertionSort.c insertionSort.h quickSort.c quickSort.h testHelper.c testHelper.h)
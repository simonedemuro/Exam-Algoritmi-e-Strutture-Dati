cmake_minimum_required(VERSION 3.15)
project(ASD_Esercitazione_01 C)

set(CMAKE_C_STANDARD 90)

add_executable(ASD_Esercitazione_01 main.c models.h selectionSort.c selectionSort.h testHelper.c testHelper.h)
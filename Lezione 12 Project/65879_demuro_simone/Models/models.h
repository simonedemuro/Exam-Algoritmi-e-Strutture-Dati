//
// Created by SimonD on 5/31/2020.
//

#ifndef INC_65879_DEMURO_SIMONE_MODELS_H
#define INC_65879_DEMURO_SIMONE_MODELS_H

// MACROS:
#define MAX_RAND 10000

// ENUMS:
typedef enum {ORDINATO, QUASI_ORDINATO, INV_ORDINATO, CASUALE} inputType;
typedef enum {AUTOMATIC_REPO, MANUAL_TEST, QUIT_APPLICATION} mainMenuUserChoice;

// STRUCTS:
typedef struct {
    int nCompare;
    int milliseconds;
    int* sortedData;
}report;

// STATICS:
#define APPLICATION_LOGO "                   _             _____            _   \n"\
           "     /\\           | |           / ____|          | |  \n"\
           "    /  \\   ___  __| |  ______  | (___   ___  _ __| |_ \n"\
           "   / /\\ \\ / __|/ _` | |______|  \\___ \\ / _ \\| '__| __|\n"\
           "  / ____ \\\\__ \\ (_| |           ____) | (_) | |  | |_ \n"\
           " /_/    \\_\\___/\\__,_|          |_____/ \\___/|_|   \\__|\n"\
           "                                                      \n"\
           "                           Benchmark Sorting Algorithms\n"

#define MAIN_MENU "\n\nType an option:                 \n"\
           "0 - Run Automatic Report (5 algorithm * 4 sorting schemes * 7 dimensions = 140 test.)\n"\
           "1 - Run Manual Testing Routine \n"\
           "2 - exit\n"

#define MANUAL_TEST_MENU "Type the algorithm you want to test:\n"\
           "0. SelectionSort                    \n"\
           "1. insertionSort                    \n"\
           "2. quickSort                        \n"\
           "3. heapSort                         \n"\
           "4. mergeSort                        \n"

#define MOCK_TYPE_MESSAGE "Type the type of mock data you want to be generated for your test:\n"\
           "0. Already Sorted\n"\
           "1. Partially Sorted\n"\
           "2. Reversely Sorted\n"\
           "3. Random\n"

#endif //INC_65879_DEMURO_SIMONE_MODELS_H

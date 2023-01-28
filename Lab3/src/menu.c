#include <stdio.h>

#include "include/menu.h"
#include "include/input.h"
#include "include/utils.h"

int initMenuDialog(Array* array) {
    int ret;
    do {
        printMenuOptions();
        ret = parseUserInput(array);
    } while (ret == CONTINUE);
    exitMenuDialog(ret);
    return ret;
}

static void exitMenuDialog(int code) {
    switch (code) {
        case EXIT:
            clearOutput();
            printf("Goodbye...\n");
            break;
        case CONTINUE:
        case FAILURE:
            printError("\nError during program execution, exiting...");
            break;
        default:
            break;
    }
}

static void printMenuOptions() {
    clearOutput();
    printf("Menu options:\n");
    printf("\n");
    printf("┌───────────────────────────────────┐\n");
    printf("│ 1. Initialize new array           │\n");
    printf("├───────────────────────────────────┤\n");
    printf("│ 2. Append value to array by index │\n");
    printf("├───────────────────────────────────┤\n");
    printf("│ 3. Delete value in array by index │\n");
    printf("├───────────────────────────────────┤\n");
    printf("│ 4. Find arithmetic progression    │\n");
    printf("├───────────────────────────────────┤\n");
    printf("│ 5. Print current array            │\n");
    printf("├───────────────────────────────────┤\n");
    printf("│ 6. Exit program                   │\n");
    printf("└───────────────────────────────────┘\n");
    printf("\n");
    printf("Type your option from 1 to 6, then press ENTER: ");
}

static int parseUserInput(Array* array) {
    int input = 0;
    getInt(&input);

    switch (input) {
        case 1:
            return fillArray(array);
        case 2:
            return addElement(array);
        case 3:
            return removeElement(array);
        case 4:
            return findProgression(array);
        case 5:
            return printArray(array);
        case 6:
            clearOutput();
            return EXIT;
        default:
            onBadInput();
            return parseUserInput(array);
    }
}
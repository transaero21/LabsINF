#include <stdio.h>
#include <stdlib.h>

#include "include/arrays.h"
#include "include/input.h"
#include "include/utils.h"

int fillArray(Array* array) {
    int arrSize = 0;

    clearOutput();
    printf("Enter required size of the array (size > 0): ");
    while (1) {
        getInt(&arrSize);
        if (arrSize > 0) break;
        printError("Array size cannot be less than or equal zero, try again: ");
    }

    array->ptr = malloc(arrSize * sizeof(int));
    if (!array->ptr) {
        printError("Failed to allocate memory for array!\n");
        return FAILURE;
    }

    array->size = arrSize;
    for (int i = 0; i < array->size; i++) {
        printf("Enter [%d] value: ", i);
        getInt(&array->ptr[i]);
    }

    pressEnterToContinue();
    return CONTINUE;
}

int printArray(Array* array) {
    clearOutput();
    printArrayNoDialog(array);

    pressEnterToContinue();
    return CONTINUE;
}

static void printArrayNoDialog(Array* array) {
    if (!array->ptr || array->size < 1) {
        printError("Array is empty or not initialized yet!\n");
    } else {
        printf("Array is { ");
        for (int i = 0; i < array->size; i++) {
            printf("[%d]: %d", i, array->ptr[i]);
            if (i != array->size - 1) {
                printf(", ");
            } else {
                printf(" }\n");
            }
        }
        printf("Array size is %d\n", array->size);
    }
}

int addElement(Array* array) {
    int index = 0, value = 0;

    clearOutput();
    printf("Enter required index of the array (0 <= index): ");
    while (1) {
        getInt(&index);
        if (index > -1) break;
        printError("Array size cannot be less than zero, try again: ");
    }

    printf("Enter [%d] value: ", index);
    getInt(&value);

    if (addElementByIndex(array, index, value) == FAILURE) {
        printError("Failed to add value by index, something went wrong!\n");
        return FAILURE;
    }

    pressEnterToContinue();
    return CONTINUE;
}

static int addElementByIndex(Array* array, int index, int value) {
    if (index < 0) {
        return FAILURE;
    }

    int newSize = (index > array->size ? index : array->size) + 1;
    array->ptr = realloc(array->ptr, (newSize) * sizeof(int));
    if (!array->ptr) {
        printError("Failed to allocate memory for array!\n");
        return FAILURE;
    }

    for (int i = newSize - 1; i >= array->size; i--) {
        array->ptr[i] = 0;
    }
    array->size = newSize;

    for (int i = array->size - 1; i > index; i--) {
        array->ptr[i] = array->ptr[i - 1];
    }
    array->ptr[index] = value;

    return CONTINUE;
}

int removeElement(Array* array) {
    int index = 0;

    clearOutput();
    if (!array->ptr || array->size < 1) {
        printError("Array is empty or not initialized yet!\n");
    } else {
        printf("Enter required index of the array (0 <= index <= %d): ", array->size - 1);
        while (1) {
            getInt(&index);
            if (index >= 0 && index <= array->size - 1) break;
            printError("Index is out of bounds, try again: ");
        }

        if (removeElementByIndex(array, index) == FAILURE) {
            return FAILURE;
        }
    }

    pressEnterToContinue();
    return CONTINUE;
}

static int removeElementByIndex(Array* array, int index) {
    if (index < 0 && index > array->size) {
        return FAILURE;
    }

    for (int i = index + 1; i < array->size; i++) {
        array->ptr[i - 1] = array->ptr[i];
    }

    array->ptr = realloc(array->ptr, (array->size - 1) * sizeof(int));
    if (!array->ptr) {
        printError("Failed to allocate memory for array!\n");
        return FAILURE;
    }
    array->size--;

    return CONTINUE;
}

int findProgression(Array* array) {
    Array newArray = { .ptr = NULL, .size = 0};
    int prev, now, val, input;

    clearOutput();
    if (!array->ptr || array->size < 1) {
        printError("Array is empty or not initialized yet!\n");
    } else {
        for (int i = 0; i < array->size; i++) {
            if (array->ptr[i] / 100 == 0) continue;

            val = array->ptr[i] < 0 ? array->ptr[i] * -1 : array->ptr[i];
            now = getLastDiff(val);
            while (val >= 100) {
                prev = now;
                val /= 10;
                now = getLastDiff(val);
                if (prev != now) break;
            }

            if (prev == now) {
                addElementByIndex(&newArray, newArray.size, array->ptr[i]);
                removeElementByIndex(array, i);
                i--;
            }
        }

        printSuccess("The array was split into two new\n");
        printf("1. Without progression: \n");
        printArrayNoDialog(array);
        printf("\n");
        printf("2. With progression: \n");
        printArrayNoDialog(&newArray);
        printf("\n");

        printf("Which one do you want to choose (1, 2): ");
        while (1) {
            getInt(&input);
            if (input == 1 || input == 2) break;
            onBadInput();
        }
        switch (input) {
            case 1:
                free(newArray.ptr);
                printSuccess("Array without progression selected!\n");
                break;
            case 2:
                free(array->ptr);
                array->ptr = newArray.ptr;
                array->size = newArray.size;
                printSuccess("Array with progression selected!\n");
                break;
            default:
                break;
        }
    }

    pressEnterToContinue();
    return CONTINUE;
}

static int getLastDiff(int val) {
    if (val < 0) val *= -1;
    if (val < 10) return 0;
    return val / 10 % 10 - val % 10;
}
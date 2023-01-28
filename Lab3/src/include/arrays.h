#ifndef INCLUDE_ARRAYS_H
#define INCLUDE_ARRAYS_H

typedef struct Array {
    int* ptr;
    int size;
} Array;

int fillArray(Array*);
int printArray(Array*);
int addElement(Array*);
int removeElement(Array*);
int findProgression(Array*);

static void printArrayNoDialog(Array*);
static int addElementByIndex(Array*, int, int);
static int removeElementByIndex(Array*, int);
static int getLastDiff(int);

#endif //INCLUDE_ARRAYS_H

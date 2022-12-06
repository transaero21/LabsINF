#include <stdio.h>
#include <stdlib.h>

#include "include/common.h"

float promoteRow(float* x, float* y, float z, int i) {
    float k = -z / ((i * 2) * (i * 2 + 1));
    *x *= 9 * k;
    *y *= k;
    return *x - *y;
}

void printError(const char* msg) {
    printf("\033[1;31m");
    printf("%s", msg);
    printf("\033[0m");
}

void getFloat(float *f) {
    while(!scanf("%f", f)) {
        onBadInput();
    }
}

void getInt(int *i) {
    while(!scanf("%d", i)) {
        onBadInput();
    }
}

void onBadInput() {
    scanf("%*[^\n]");
    printf("That is NOT a valid input, try again:\n");
}

void clearOutput() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}






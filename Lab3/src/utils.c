#include <stdio.h>
#include <stdlib.h>

#include "include/utils.h"

void pressEnterToContinue() {
    printSuccess("\nPress ENTER to continue...");
    getchar();
    scanf("%*[^\n]");
}

void printError(const char* msg) {
    printf("\033[1;31m");
    printf("%s", msg);
    printf("\033[0m");
}

void printSuccess(const char* msg) {
    printf("\033[0;32m");
    printf("%s", msg);
    printf("\033[0m");
}

void clearOutput() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
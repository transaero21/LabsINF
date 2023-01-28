#include <stdio.h>
#include <stdlib.h>

#include "include/output.h"

void printDelimiterMsg() {
    printSuccessMsg("***********************************\n");
}

void printExitMsg() {
    printSuccessMsg("Goodbye...\n\n");
}

void printSuccessMsg(const char *msg) {
    printf("\033[0;32m");
    printf("%s", msg);
    printf("\033[0m");
}

void printErrorMsg(const char *msg) {
    printf("\033[0;31m");
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
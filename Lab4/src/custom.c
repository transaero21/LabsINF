#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "include/output.h"
#include "include/input.h"
#include "include/parse.h"
#include "include/utils.h"

int main() {
    char *string;

    clearOutput();
    while (1) {
        clock_t time = clock();
        printf(INPUT_MSG);
        string = getString();
        if (!string) break;
        shiftString(string, getStringLength(string));
        time = clock() - time;
        printf("Result: %s\n", string);
        printf("Time perform shift: %Lf\n", (long double) time / CLOCKS_PER_SEC);
        free(string);
        printDelimiterMsg();
    }
    printExitMsg();

    return 0;
}
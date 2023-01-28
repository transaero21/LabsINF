#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <readline/readline.h>

#include "include/output.h"
#include "include/parse.h"

int main() {
    char *string;

    clearOutput();
    while (1) {
        clock_t time = clock();
        string = readline(INPUT_MSG);
        if (!string) break;
        shiftString(string, (int) strlen(string));
        time = clock() - time;
        printf("Result: %s\n", string);
        printf("Time perform shift: %Lf\n", (long double) time / CLOCKS_PER_SEC);
        free(string);
        printDelimiterMsg();
    }
    printExitMsg();

    return 0;
}

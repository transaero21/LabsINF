#include <stdio.h>
#include <time.h>

#include "include/parse.h"
#include "include/output.h"

void shiftString(char *string, int length) {
    int shift, start = 0;

    printf("Enter required shift value: ");
    while (!scanf("%d", &shift)) {
        printErrorMsg("This is invalid input, try again: ");
        scanf("%*[^\n]");
    }
    scanf("%*c");

    for (int i = 0; i < length; i++) {
        if (string[i] == ' ' || i == length - 1) {
            int end = (string[i] == ' ' ? -1 : 0) + i;
            shiftSingleWord(string, start, end, shift);
            if (end != i) start = i + 1;
        }
    }
}

static void shiftSingleWord(char *string, int start, int end, int shift) {
    int length = end - start + 1;
    if (length != 0) {
        shift = shift * (shift < 0 ? -1 : 1) % length;
        int until = !shift ? 0 : length % shift || shift == 1 ? 1 : length / shift;
        for (int j = 0; j < until; j++) {
            int to = end - j;
            char tmp = string[to];
            do {
                to -= shift;
                if (to < start) to += end - start + 1;
                swapValues(&string[to], &tmp);
            } while (to != end - j);
        }
    }
}

static void swapValues(char *x, char *y) {
    char tmp = *x;
    *x = *y;
    *y = tmp;
}

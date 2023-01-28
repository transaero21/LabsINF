#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "include/utils.h"

void printErrorMsg(const char *msg, ...) {
    va_list args;
    va_start(args, msg);

    printf("\033[1;31m");
    printMsg(msg, args);
    printf("\033[0m");
}

void printSuccessMsg(const char *msg, ...) {
    va_list args;
    va_start(args, msg);

    printf("\033[1;32m");
    printMsg(msg, args);
    printf("\033[0m");
}

void printMsg(const char *msg, va_list args) {
    while (*msg != '\0') {
        if (*msg != '%') {
            putchar(*msg);
        } else {
            msg++;
            if (*msg != '\0') {
                switch (*msg) {
                    case 's':
                        printf("%s", va_arg(args, char*));
                        break;
                    case 'c':
                        printf("%c", va_arg(args, int));
                        break;
                    case 'd':
                        printf("%d", va_arg(args, int));
                    default:
                        break;
                }
            }
        }
        msg++;
    }
}

void freeCharPtr(int count, ...) {
    va_list args;
    va_start(args, count);

    for (int i = 0; i < count; i++) {
        free(va_arg(args, char*));
    }
}

int getLength(char *str) {
    int count = 0;
    if (str) {
        while (str[count] != '\0') count++;
    }
    return count;
}

void appendString(char *src, int srcSize, const char *dest) {
    int end = 0, j = -1;
    for (int i = 0; i < srcSize; i++) {
        if (src[i] == '\0') {
            end = i;
            break;
        }
    }
    do {
        j++;
        src[end + j] = dest[j];
    } while (dest[j] != '\0');
}

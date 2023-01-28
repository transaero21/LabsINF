#include <stdarg.h>
#include <stdio.h>

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

void printDelimiterMsg() {
    printSuccessMsg("***********************************\n");
}

void printExitMsg() {
    printSuccessMsg("\nGoodbye...\n\n");
}

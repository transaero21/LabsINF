#ifndef INCLUDE_UTILS_H
#define INCLUDE_UTILS_H

enum RETURN {
    EXIT = 0,
    CONTINUE = 1,
    FAILURE = 2
};

void pressEnterToContinue();
void printError(const char*);
void printSuccess(const char*);
void clearOutput();

#endif //INCLUDE_UTILS_H

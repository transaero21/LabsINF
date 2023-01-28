#ifndef INCLUDE_ARGS_H
#define INCLUDE_ARGS_H

enum Algorithm {
    QSORT = 0,
    ODD_EVEN_SORT = 1,
    DOUBLE_SELECTION_SORT = 2
};

enum Field {
    NAME = 0,
    GROUP = 1,
    SCORE = 2
};

enum Direction {
    INCREASE = 0,
    DECREASE = 1
};

int parseArgs(int argc, char *argv[], int *a, int *f, int *d);
void printArgsHelp();

#endif //INCLUDE_ARGS_H

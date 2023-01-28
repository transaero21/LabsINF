#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <time.h>

#include "include/args.h"
#include "include/objects.h"
#include "include/randomizer.h"
#include "include/sorter.h"

void printFileArgsHelp();
int parseTimingArgs(int argc, char *argv[], RandParams *params);

int main(int argc, char *argv[]) {
    int algorithm = QSORT, field = NAME, direction = INCREASE;

    int ret = parseArgs(argc, argv, &algorithm, &field, &direction);
    if (ret == -1) {
        ret = 0;
        printFileArgsHelp();
    } else if (!ret) {
        RandParams params = {.tries = 0, .size = 0};
        ret = parseTimingArgs(argc, argv, &params);
        if (!ret) {
            srand(time(NULL));
            size_t fullTime = 0;
            for (int i = 0; i < params.tries; i++) {
                Students students = getRandomStudents(params.size);
                fullTime += sortStudents(&students, algorithm, field, direction);
                freeStudents(&students);
            }
            printf("Average time to sort array of %d elements: %Lf\n", params.size,
                   (long double) fullTime / CLOCKS_PER_SEC / params.tries);
        }
    }

    return ret;
}

void printFileArgsHelp() {
    printf("Usage: timing [arguments] [input] [output]\n");
    printArgsHelp();
}

int parseTimingArgs(int argc, char *argv[], RandParams *params) {
    int ret = 1, args;

    args = argc - optind;
    if (args > 2) {
        printf("Too many arguments, need two!\n");
    } else if (args < 2) {
        printf("Not enough arguments, need two!\n");
    } else {
        sscanf(argv[optind], "%d", &params->tries);
        sscanf(argv[optind + 1], "%d", &params->size);
        if (params->tries && params->size) ret = 0;
    }
    if (ret) printFileArgsHelp();

    return ret;
}
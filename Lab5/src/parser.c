#include <stdio.h>
#include <string.h>
#include <getopt.h>

#include "include/args.h"
#include "include/files.h"
#include "include/sorter.h"
#include "include/utils.h"

void printFileArgsHelp();
int parseFileArgs(int argc, char *argv[], Files *files);

int main(int argc, char *argv[]) {
    int algorithm = QSORT, field = NAME, direction = INCREASE;

    int ret = parseArgs(argc, argv, &algorithm, &field, &direction);
    if (ret == -1) {
        ret = 0;
        printFileArgsHelp();
    } else if (!ret) {
        Files files = {.pathIn = NULL, .pathOut = NULL};
        ret = parseFileArgs(argc, argv, &files);
        if (!ret) {
            FILE *fIn = openFile(files.pathIn, "r");
            if (fIn) {
                Students students = {.ptr = NULL, .size = 0};
                scanFile(fIn, &students);
                if (students.size) {
                    printSuccessMsg("Successfully scanned %d lines!\n", students.size);
                    sortStudents(&students, algorithm, field, direction);
                    FILE *fOut= openFile(files.pathOut, "w");
                    if (fOut) {
                        writeFile(fOut, &students);
                        if (!ferror(fOut)) {
                            printSuccessMsg("Successfully written %d lines!\n",
                                            students.size);
                        }
                        freeStudents(&students);
                    }
                    fclose(fOut);
                }
            }
            fclose(fIn);
        }
        freeCharPtr(2, files.pathIn, files.pathOut);
    }

    return ret;
}

void printFileArgsHelp() {
    printf("Usage: parser [arguments] [input] [output]\n");
    printArgsHelp();
}

int parseFileArgs(int argc, char *argv[], Files *files) {
    int ret = 1, args;

    args = argc - optind;
    if (args > 2) {
        printf("Too many arguments, need two!\n");
    } else if (args < 2) {
        printf("Not enough arguments, need two!\n");
    } else {
        files->pathIn = strdup(argv[optind]);
        files->pathOut = strdup(argv[optind + 1]);
        if (files->pathOut && files->pathIn) ret = 0;
    }
    if (ret) printFileArgsHelp();

    return ret;
}

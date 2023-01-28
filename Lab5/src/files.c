#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <math.h>

#include "include/files.h"
#include "include/utils.h"

FILE *openFile(char *path, char *mode) {
    FILE *f = fopen(path, mode);
    if (!f) {
        printErrorMsg("Failed to open file: %s\n", strerror(errno));
    }
    return f;
}

void scanFile(FILE *f, Students *students) {
    int ret;
    do {
        Student student = { .name = NULL };
        do {
            char *buf = malloc((128 + 1) * sizeof(char));
            ret = fscanf(f, "%128[^,]", buf);
            if (ret < 0) {
                if (student.name) {
                    printErrorMsg("File format incorrect, use csv format!\n");
                } else ret = 0;
            } else if (ret > 0) {
                size_t oldSize = getLength(student.name);
                size_t newSize = oldSize + getLength(buf) + 1;
                student.name = realloc(student.name, newSize * sizeof(char));
                appendString(student.name, oldSize, buf);
            } else {
                if (student.name) ret = 1;
                ret += fscanf(f, ", %d, %f\n", &student.group, &student.score);
                if (ret == 3) {
                    appendStudents(students, student);
                } else {
                    if (!feof(f)) {
                        printErrorMsg("File format incorrect, use csv format!\n");
                    } else if (ferror(f)) {
                        printErrorMsg("Error occurred while reading file!\n");
                    } else if (!student.name) {
                        printErrorMsg("Student name cannot be empty, aborting!\n");
                    } else {
                        printErrorMsg("Unknown error occurred, aborting!\n");
                    }
                    ret = -1;
                }
            }
            free(buf);
        } while (ret == 1);
        if (ret == -1) freeStudents(students);
    } while (ret == 3);
}

void writeFile(FILE *f, Students *students) {
    for (int i = 0; i < students->size; i++) {
        Student student = students->ptr[i];
        fprintf(f, "%s, %d, %f\n", student.name, student.group, fabsf(student.score));
        if (ferror(f)) {
            printErrorMsg("Error occurred while writing to file!\n");
            break;
        }
    }
}

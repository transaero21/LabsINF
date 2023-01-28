#include <stdlib.h>
#include <string.h>
#include <printf.h>

#include "include/randomizer.h"

Students getRandomStudents(int size) {
    Students students = { .size = 0, .ptr = NULL};
    for (int i = 0; i < size; i++) {
        appendStudents(&students, getRandomStudent());
    }
    return students;
}

Student getRandomStudent() {
    Student student = {
            .name = getRandomName(),
            .group = getRandomInt(100, 1000),
            .score = getRandomFloat(10.0f)
    };
    return student;
}

int getRandomInt(int from, int to) {
    return from + rand() % (to - from + 1);
}

float getRandomFloat(float to) {
    return ((float) rand() / (float) (RAND_MAX)) * to;
}

char *getRandomName() {
    char *ret = calloc(1, sizeof(char));
    for (int i = 0; i < 3; i++) {
        char *str = getRandomString(getRandomInt(6, 12), i == 2 ? 0 : 1);
        ret = realloc(ret, strlen(ret) + strlen(str) + 1);
        strcat(ret, str);
        free(str);
    }
    return ret;
}

char *getRandomString(int size, int afterSpace) {
    char *ret = malloc((size + afterSpace + 1) * sizeof(char));
    ret[0] = (char) getRandomInt(65, 90);
    for (int i = 1; i < size; i++) {
        ret[i] = (char) getRandomInt(97, 122);
    }
    for (int i = size; i < size + afterSpace; ++i) {
        ret[i] = ' ';
    }
    ret[size + afterSpace] = '\0';
    return ret;
}
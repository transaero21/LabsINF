#include <stdlib.h>

#include "include/objects.h"

void appendStudents(Students *students, Student student) {
    if (!students) return;
    students->size++;
    students->ptr = realloc(students->ptr, sizeof(Student) * students->size);
    students->ptr[students->size - 1] = student;
}

void freeStudents(Students *students) {
    if (!students) return;
    for (int i = 0; i < students->size; i++) {
        free(students->ptr[i].name);
    }
    free(students->ptr);
    students->size = 0;
}
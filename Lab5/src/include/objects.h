#ifndef INCLUDE_OBJECTS_H
#define INCLUDE_OBJECTS_H

typedef struct Student {
    char *name;
    int group;
    float score;
} Student;

typedef struct Students {
    Student *ptr;
    int size;
} Students;

typedef struct Files {
    char *pathIn;
    char *pathOut;
} Files;

typedef struct RandParams {
    int tries;
    int size;
} RandParams;

void appendStudents(Students *students, Student student);
void freeStudents(Students *students);

#endif //INCLUDE_OBJECTS_H

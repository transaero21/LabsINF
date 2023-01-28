#ifndef INCLUDE_SORTER_H
#define INCLUDE_SORTER_H

#include "objects.h"

size_t sortStudents(Students *students, int a, int f, int d);
void oddEvenSort(Students *students, int (*cmp)(const void *, const void *));
void doubleSelectionSort(Students *students, int (*cmp)(const void *, const void *));
void swap(Student *obj1, Student *obj2);
int nameComparator(const void *obj1, const void *obj2);
int reversedNameComparator(const void *obj1, const void *obj2);
int groupComparator(const void *obj1, const void *obj2);
int reversedGroupComparator(const void *obj1, const void *obj2);
int scoreComparator(const void *obj1, const void *obj2);
int reversedScoreComparator(const void *obj1, const void *obj2);

#endif //INCLUDE_SORTER_H

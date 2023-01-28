#include <string.h>
#include <stdlib.h>
#include <printf.h>
#include <time.h>

#include "include/args.h"
#include "include/sorter.h"

size_t sortStudents(Students *students, int a, int f, int d) {
    int (*cmp)(const void *, const void *) = NULL;
    size_t time = clock();

    switch (f) {
        case GROUP:
            if (d == INCREASE) cmp = groupComparator;
            else cmp = reversedGroupComparator;
            break;
        case SCORE:
            if (d == INCREASE) cmp = scoreComparator;
            else cmp = reversedScoreComparator;
            break;
        default:
            if (d == INCREASE) cmp = nameComparator;
            else cmp = reversedNameComparator;
    }
    switch (a) {
        case ODD_EVEN_SORT:
            oddEvenSort(students, cmp);
            break;
        case DOUBLE_SELECTION_SORT:
            doubleSelectionSort(students, cmp);
            break;
        default:
            qsort(students->ptr, students->size, sizeof(Student), cmp);
    }

    return clock() - time;
}

void oddEvenSort(Students *students, int (*cmp)(const void *, const void *)) {
    int isOk = 0;

    while (!isOk) {
        isOk = 1;
        for (int i = 0; i < students->size - 1; i += 2) {
            if (cmp(&students->ptr[i], &students->ptr[i + 1]) > 0) {
                swap(&students->ptr[i], &students->ptr[i + 1]);
                isOk = 0;
            }
        }
        for (int i = 1; i < students->size - 1; i += 2) {
            if (cmp(&students->ptr[i], &students->ptr[i + 1]) > 0) {
                swap(&students->ptr[i], &students->ptr[i + 1]);
                isOk = 0;
            }
        }
    }
}

void doubleSelectionSort(Students *students, int (*cmp)(const void *, const void *)) {
    for (int i = 0, j = students->size - 1; i < j; i++, j--) {
        int min = i, max = i;
        for (int k = i; k <= j; k++) {
            if (cmp(&students->ptr[k], &students->ptr[min]) < 0) {
                min = k;
            } else if (cmp(&students->ptr[k], &students->ptr[max]) > 0) {
                max = k;
            }
        }

        if (i != min) {
            swap(&students->ptr[i], &students->ptr[min]);
        }

        if (i == max) {
            swap(&students->ptr[j], &students->ptr[min]);
        } else {
            swap(&students->ptr[j], &students->ptr[max]);
        }
    }
}

void swap(Student *obj1, Student *obj2) {
    Student tmp = *obj1;
    *obj1 = *obj2;
    *obj2 = tmp;
}

int nameComparator(const void *obj1, const void *obj2) {
    return strcmp(((Student *) obj1)->name, ((Student *) obj2)->name);
}

int reversedNameComparator(const void *obj1, const void *obj2) {
    return nameComparator(obj1, obj2) * -1;
}

int groupComparator(const void *obj1, const void *obj2) {
    return (((Student *) obj1)->group - ((Student *) obj2)->group);
}

int reversedGroupComparator(const void *obj1, const void *obj2) {
    return groupComparator(obj1, obj2) * -1;
}

int scoreComparator(const void *obj1, const void *obj2) {
    float diff = ((Student *) obj1)->score - ((Student *) obj2)->score;
    return !diff ? 0 : diff > 0 ? 1 : -1;
}

int reversedScoreComparator(const void *obj1, const void *obj2) {
    return scoreComparator(obj1, obj2) * -1;
}


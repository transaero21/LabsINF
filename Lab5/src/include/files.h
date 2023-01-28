#ifndef INCLUDE_FILES_H
#define INCLUDE_FILES_H

#include "objects.h"

FILE *openFile(char *path, char *mode);
void scanFile(FILE *f, Students *students);
void writeFile(FILE *f, Students *students);

#endif //INCLUDE_FILES_H

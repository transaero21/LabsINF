#ifndef INCLUDE_RANDOMIZER_H
#define INCLUDE_RANDOMIZER_H

#include "objects.h"

Students getRandomStudents(int size);
Student getRandomStudent();
int getRandomInt(int from, int to);
float getRandomFloat(float to);
char *getRandomName();
char *getRandomString(int size, int afterSpace);

#endif //INCLUDE_RANDOMIZER_H

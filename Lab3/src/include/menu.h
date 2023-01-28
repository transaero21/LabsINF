#ifndef INCLUDE_MENU_H
#define INCLUDE_MENU_H

#include "arrays.h"

int initMenuDialog(Array*);

static void exitMenuDialog(int);
static void printMenuOptions();
static int parseUserInput(Array*);

#endif //INCLUDE_MENU_H

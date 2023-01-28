#ifndef INCLUDE_PARSE_H
#define INCLUDE_PARSE_H

#include "object.h"

void cleanUpLine(LinkedList *list);
void doubleEvenWords(LinkedList *list);

static int isSpace(char value);
static void fixupSpace(Node *node);

#endif //INCLUDE_PARSE_H

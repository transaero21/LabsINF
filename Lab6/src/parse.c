#include "include/parse.h"
#include "include/object.h"

void cleanUpLine(LinkedList *list) {
    Node *node = list->base;
    int j = 0, start = 1;
    char prev;

    while (node) {
        int delete = 0;
        if (isSpace(node->value)) {
            if (start || isSpace(prev)) delete = 1;
            else fixupSpace(node);
        } else if (start) start = 0;
        prev = node->value;
        node = node->next;
        if (delete) {
            deleteElement(list, j);
        } else j++;
    }
    if (prev == ' ' && j > 0) deleteElement(list, --j);
}

void doubleEvenWords(LinkedList *list) {
    Node *node = list->base, *startNode = node;
    int j = 0, start = 0, space;

    while (node) {
        if ((space = isSpace(node->value)) || !node->next) {
            int length = (space ? -1 : 0) + j - start + 1;
            if (length > 0 && !(length % 2)) {
                if (!space) insertElement(list, ++j, ' ');
                int until = j + length;
                for (j++; j <= until; j++) {
                    node = insertElement(list, j, startNode->value);
                    startNode = startNode->next;
                }
                if (node->next) insertElement(list, j--, ' ');
            } else {
                startNode = node->next;
            }
            if (node->next) start = j + 1;
        }
        node = node->next;
        j++;
    }
}

static int isSpace(char value) {
    return value == ' ' || value == '\t';
}

static void fixupSpace(Node *node) {
    if (node && node->value == '\t') node->value = ' ';
}
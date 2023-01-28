#ifndef INCLUDE_OBJECT_H
#define INCLUDE_OBJECT_H

typedef struct Node {
    char value;
    struct Node *next;
} Node;

typedef struct LinkedList {
    Node *base;
} LinkedList;

Node *insertElement(LinkedList *list, int index, char value);
void deleteElement(LinkedList *list, int index);
void eraseList(LinkedList *list);
void printList(LinkedList *list);
Node *initNode();

static void copyNode(const Node *origin, Node *dest);

#endif //INCLUDE_OBJECT_H

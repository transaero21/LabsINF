#include <stdio.h>
#include <stdlib.h>

#include "include/object.h"
#include "include/utils.h"

Node *insertElement(LinkedList *list, int index, char value) {
    if (index < 0) {
        printErrorMsg("Index (%d) is out of bounds!\n", index);
        return NULL;
    }

    if (!list->base) {
        printErrorMsg("Linked list is NOT initialized!\n");
        return NULL;
    }

    Node *node = list->base, *tmpNode;


    for (int i = 0; i < index; i++) {
        if (!node->next) {
            node->next = initNode();
        }
        node = node->next;
    }

    if (node->value) {
        tmpNode = initNode();
        copyNode(node, tmpNode);
        node->next = tmpNode;
    }
    node->value = value;

    return node;
}

void deleteElement(LinkedList *list, int index) {
    if (index < 0) {
        printErrorMsg("Index (%d) is out of bounds!\n", index);
        return;
    }

    if (!list->base) {
        printErrorMsg("Linked list is NOT initialized!\n");
        return;
    }

    Node *node = list->base, *tmpNode = NULL;

    if (index) {
        for (int i = 0; i < index - 1 && node; i++) {
            node = node->next;
        }

        if (!node || !node->next) {
            printErrorMsg("Index (%d) is out of bounds!\n", index);
        } else {
            tmpNode = node->next;
            node->next = node->next->next;
            free(tmpNode);
        }
    } else {
        list->base = node->next;
        free(node);
    }
}

void eraseList(LinkedList *list) {
    Node *node = list->base;

    while (node) {
        Node *tmp = node->next;
        free(node);
        node = tmp;
    }
}

void printList(LinkedList *list) {
    Node *node = list->base;

    printf("Result: ");
    while (node) {
        if (node->value) printf("%c", node->value);
        node = node->next;
    }
    printf("\n");
}

Node *initNode() {
    Node *node = malloc(sizeof(Node));
    node->next = NULL;
    node->value = 0;
    return node;
}

void copyNode(const Node *origin, Node *dest) {
    dest->next = origin->next;
    dest->value = origin->value;
}

#include <stdio.h>

#include "include/object.h"
#include "include/parse.h"
#include "include/utils.h"

int scanLine(LinkedList *list);

int main() {
    int ret;

    do {
        LinkedList list = {.base = initNode()};
        ret = scanLine(&list);
        if (ret) {
            cleanUpLine(&list);
            doubleEvenWords(&list);
            printList(&list);
            printDelimiterMsg();
        } else {
            printExitMsg();
        }
        eraseList(&list);
    } while (ret);

    return 0;
}

int scanLine(LinkedList *list) {
    int value, j = 0;

    printf("Enter any string: ");
    while ((value = getchar()) != EOF) {
        if (value == '\n') break;
        insertElement(list, j, (char) value);
        j++;
    }

    return value == EOF ? 0 : 1;
}

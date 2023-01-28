#include <stdio.h>

#include "include/input.h"
#include "include/utils.h"

void getInt(int *i) {
    while(!scanf("%d", i)) {
        onBadInput();
    }
}

void onBadInput() {
    scanf("%*[^\n]");
    printError("That is NOT a valid input, try again: ");
}
#include <stdlib.h>

#include "include/menu.h"
#include "include/arrays.h"

int main() {
    Array array = { .ptr = NULL, .size = 0};
    int ret = initMenuDialog(&array);
    free(array.ptr);
    return ret;
}

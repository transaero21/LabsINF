#include "include/utils.h"

void memoryCopy(const char *src, int srcPos, char *dest, int destPos, int length) {
    for (int i = 0; i < length; i++) {
        dest[destPos + i] = src[srcPos + i];
    }
}

int getStringLength(const char *string) {
    int length = 0;
    while (string[length] != '\0') length++;
    return length;
}

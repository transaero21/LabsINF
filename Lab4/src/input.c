#include <stdlib.h>
#include <stdio.h>

#include "include/input.h"
#include "include/utils.h"
#include "include/output.h"

char *getString() {
    char *string = NULL, *buffer = NULL;
    int ret, bufLength, length = 0;

    do {
        buffer = malloc((MAX_BUF + 1) * sizeof(char));
        ret = scanf("%128[^\n]", buffer);
        if (ret < 0) {
            free(string);
            string = NULL;
        } else if (!ret) {
            scanf("%*c");
            if (!string) {
                printErrorMsg("String cannot be empty, try again: ");
                ret = 1;
            }
        } else {
            bufLength = getStringLength(buffer);
            string = realloc(string, length + bufLength + 1);
            memoryCopy(buffer, 0, string, length, bufLength);
            length += bufLength;
        }
        free(buffer);
    } while (ret == 1);
    if (!ret && length > 0) string[length] = '\0';

    return string;
}



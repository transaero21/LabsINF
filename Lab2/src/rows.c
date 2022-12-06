#include <stdio.h>
#include <math.h>

#include "include/common.h"

float calculateRowByCount(float, int);

int main() {
    float arg = 0;
    int n = 1;

    clearOutput();
    printf("Specify the value (float) of function argument: ");
    getFloat(&arg);
    printf("Specify the value (int) of rows count: ");
    while (1) {
        getInt(&n);
        if (n > 0) break;
        printError("Rows count can't be less than or equals zero, try again: ");
    }

    printf("\n");
    printf("Calculated sin(%g)^3 with %d rows: %.16lf\n", arg, n, calculateRowByCount(arg, n));
    printf("Expected value (calculated with default impl) is: %.16lf\n", pow(sin((double) arg), 3));

    return 0;
}

float calculateRowByCount(float arg, int n) {
    float x = arg, y = arg, z = arg * arg, ret = 0;

    for (int i = 1; i <= n; i++) {
        ret -= promoteRow(&x, &y, z, i);
    }

    return ret * 0.75f;
}



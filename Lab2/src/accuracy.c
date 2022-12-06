#include <stdio.h>
#include <math.h>

#include "include/common.h"

float calculateRowByAccuracy(float arg, float acc);

int main() {
    float arg = 0, acc = 0;

    clearOutput();
    printf("Specify the value (float) of function argument: ");
    getFloat(&arg);
    printf("Specify the value (float) of function accuracy: ");
    while (1) {
        getFloat(&acc);
        if (acc < 1) break;
        printError("Accuracy cannot be more than or equal one, try again: ");
    }

    printf("\n");
    printf("Calculated sin(%g)^3 with %g accuracy: %.16lf\n", arg, acc, calculateRowByAccuracy(arg, acc));
    printf("Expected value (calculated with default impl) is: %.16lf\n", pow(sin((double) arg), 3));

    return 0;
}

float calculateRowByAccuracy(float arg, float acc) {
    float x = arg, y = arg, z = arg * arg, ret = 0;
    float new = promoteRow(&x, &y, z, 1), prev, diff;

    int i = 1;
    do {
        i++;
        prev = new;
        ret -= prev;
        new = promoteRow(&x, &y, z, i);
        diff = new > prev ? new - prev : prev - new;
    } while (diff > acc);

    return ret * 0.75f;
}

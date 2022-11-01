#include <stdio.h>

int getDifference(int k) {
    int a = 0;
    if (k < 0) {
        k = k * -1;
    }
    while(k >= 1) {
        a = a + k % 10;
        k = k / 10;
        a = a - k % 10;
        k = k / 10;
    }
    return a;
}

int main() {
    int N = 0;
    printf("Enter an integer divisible by 11:\n");
    while(!scanf("%d", &N)) {
        scanf("%*[^\n]");
        printf("That is NOT a valid input, try again:\n");
    }
    if (N % 11 != 0) {
        printf("%d is not divisble by 11!\n", N);
    } else {
        if (getDifference(N) % 11 == 0) {
            printf("True!\n");
        } else {
            printf("False!\n");
        }
    }
    return 0;
}

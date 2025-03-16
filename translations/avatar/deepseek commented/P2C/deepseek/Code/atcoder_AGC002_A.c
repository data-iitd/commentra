#include <stdio.h>
#include <stdlib.h>

int readInt() {
    int num;
    scanf("%d", &num);
    return num;
}

int readInts() {
    int a, b;
    scanf("%d %d", &a, &b);
    return a, b;
}

int main() {
    int a, b;
    a = readInts();
    b = a % 1000000007;
    if (a > 0) {
        printf("Positive\n");
    } else if (a <= 0 && b >= 0) {
        printf("Zero\n");
    } else {
        if ((a + b) % 2 == 0) {
            printf("Negative\n");
        } else {
            printf("Positive\n");
        }
    }
    return 0;
}

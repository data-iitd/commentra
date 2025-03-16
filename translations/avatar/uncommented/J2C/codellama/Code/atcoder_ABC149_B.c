
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    long A, B, K;
    long x, y;
    char line[100];

    fgets(line, 100, stdin);
    sscanf(line, "%ld %ld %ld", &A, &B, &K);

    x = A;
    y = B;
    x = A - K;
    if (x < 0) {
        y = B + x;
        x = 0;
        if (y < 0) {
            y = 0;
        }
    }

    printf("%ld %ld\n", x, y);

    return 0;
}


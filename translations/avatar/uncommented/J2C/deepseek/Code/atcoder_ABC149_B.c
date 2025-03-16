#include <stdio.h>
#include <stdlib.h>

int main() {
    long A, B, K;
    long x, y;

    // Read input
    scanf("%ld %ld %ld", &A, &B, &K);

    // Calculate x and y
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

    // Output the result
    printf("%ld %ld\n", x, y);

    return 0;
}

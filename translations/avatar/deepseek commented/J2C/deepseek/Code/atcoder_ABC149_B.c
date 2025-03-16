#include <stdio.h>
#include <stdlib.h>

int main() {
    long A, B, K;
    long x, y;

    scanf("%ld %ld %ld", &A, &B, &K);

    x = A;
    y = B;
    x = A - K; // Subtract K from A to get the new value of x
    if (x < 0) {
        y = B + x; // Adjust B by the negative value of x
        x = 0; // Set x to 0 if it becomes negative
        if (y < 0) {
            y = 0; // Set y to 0 if it becomes negative
        }
    }

    printf("%ld %ld\n", x, y); // Print the final values of x and y

    return 0;
}

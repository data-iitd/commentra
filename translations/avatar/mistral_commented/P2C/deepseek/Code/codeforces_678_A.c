#include <stdio.h>

int main() {
    int vamshi, z;

    // Read two integers from the standard input stream
    scanf("%d %d", &vamshi, &z);

    // Calculate the number of complete divisions of z into vamshi
    // Add 1 to account for the remainder
    // Multiply the result by z
    int result = ((vamshi / z) + 1) * z;

    // Print the result to the standard output stream
    printf("%d\n", result);

    return 0;
}


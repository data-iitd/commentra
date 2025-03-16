#include <stdio.h>

int main() {
    int a, b, ret;

    // Read two integers from standard input
    scanf("%d %d", &a, &b);

    // Calculate the sum
    ret = a + b;

    // Compare with subtraction
    if (ret < (a - b)) {
        ret = a - b;
    }
    // Compare with multiplication
    if (ret < (a * b)) {
        ret = a * b;
    }

    // Print the result
    printf("%d\n", ret);

    return 0;
}

// <END-OF-CODE>

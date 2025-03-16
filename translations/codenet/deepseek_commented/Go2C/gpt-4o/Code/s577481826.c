#include <stdio.h>

int main() {
    int a, b, ret;

    // Read the first integer from input
    scanf("%d", &a);
    // Read the second integer from input
    scanf("%d", &b);

    // Perform addition of the two integers
    ret = a + b;

    // Check if the result is less than the difference between the two integers
    if (ret < (a - b)) {
        ret = a - b;
    }
    // Check if the updated result is less than the product of the two integers
    if (ret < (a * b)) {
        ret = a * b;
    }

    // Print the final result
    printf("%d\n", ret);

    return 0;
}

// <END-OF-CODE>

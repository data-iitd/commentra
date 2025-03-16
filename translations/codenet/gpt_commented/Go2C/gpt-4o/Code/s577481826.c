#include <stdio.h>

int main() {
    int a, b, ret;

    // Read two integers from input
    scanf("%d %d", &a, &b);

    // Initialize ret with the sum of a and b
    ret = a + b;

    // Check if ret is less than the difference of a and b
    if (ret < (a - b)) {
        ret = a - b; // Update ret to the difference if it's smaller
    }
    // Check if ret is less than the product of a and b
    if (ret < (a * b)) {
        ret = a * b; // Update ret to the product if it's smaller
    }

    // Print the final result
    printf("%d\n", ret);

    return 0;
}

// <END-OF-CODE>

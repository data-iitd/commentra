#include <stdio.h>

int main() {
    int a, b;

    // Read two integers from input
    scanf("%d %d", &a, &b);

    // Check if the first integer 'a' is positive
    if (a > 0) {
        printf("Positive\n");  // Output 'Positive' if 'a' is greater than 0
    } else if (a <= 0 && b >= 0) {
        printf("Zero\n");  // Output 'Zero' if 'a' is non-positive and 'b' is non-negative
    } else {
        // If 'a' is negative and 'b' is also negative
        if ((a + b) % 2 == 0) {
            printf("Negative\n");  // Output 'Negative' if the sum of 'a' and 'b' is even
        } else {
            printf("Positive\n");  // Output 'Positive' if the sum of 'a' and 'b' is odd
        }
    }

    return 0;
}
// <END-OF-CODE>

#include <stdio.h>

int main() {
    int a, b;
    // Read two integers a and b
    scanf("%d %d", &a, &b);

    if (a > 0) {
        // If a is greater than 0, print 'Positive'
        printf("Positive\n");
    } else if (a <= 0 && b >= 0) {
        // If a is less than or equal to 0 and b is greater than or equal to 0, print 'Zero'
        printf("Zero\n");
    } else {
        // If neither of the above conditions is met, check if the sum of a and b is even or odd
        if ((a + b) % 2 == 0) {
            // If it's even, print 'Negative'
            printf("Negative\n");
        } else {
            // If it's odd, print 'Positive'
            printf("Positive\n");
        }
    }

    return 0;
}
// <END-OF-CODE>

#include <stdio.h>

int main() {
    // Declare variables to store the two integers
    int a, b, sum = 0;

    // Read two integers from the input
    scanf("%d %d", &a, &b);

    // Loop runs twice, each time adding the larger of the two numbers to sum
    // and decrementing that number by 1
    for (int i = 0; i < 2; i++) {
        if (a >= b) {
            sum += a;
            a = a - 1;
        } else {
            sum += b;
            b = b - 1;
        }
    }

    // Print the final sum to the console
    printf("%d\n", sum);

    return 0;
}

// <END-OF-CODE>

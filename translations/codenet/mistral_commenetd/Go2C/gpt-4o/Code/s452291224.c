#include <stdio.h>

int main() {
    // Declare variables A, B, and C of type int
    int A, B, C;

    // Read three integers from the standard input using scanf function
    scanf("%d %d %d", &A, &B, &C);

    // Check if the condition C-A+B is less than zero
    if (C - A + B < 0) {
        // If the condition is true, print zero as output
        printf("0\n");
    } else {
        // If the condition is false, calculate the value of C-A+B and print it as output
        printf("%d\n", C - A + B);
    }

    return 0;
}

// <END-OF-CODE>

#include <stdio.h>
#include <math.h>

void solve(int A, int B, int n) {
    // Check if A is zero
    if (A == 0) {
        // If both A and B are zero, print 1 (indeterminate case)
        if (B == 0) {
            printf("1\n");
        } else {
            // If A is zero and B is not, print "No solution"
            printf("No solution\n");
        }
        return;
    }

    // Check if B is not divisible by A
    if (B % A != 0) {
        // If B is not divisible by A, print "No solution"
        printf("No solution\n");
        return;
    }

    // Divide B by A to simplify the equation
    B /= A;

    // Determine if B is negative
    int neg = B < 0;

    // Check if B is negative and n is even
    if (neg && n % 2 == 0) {
        // If both conditions are true, print "No solution"
        printf("No solution\n");
        return;
    }

    // If B is negative, make it positive for further calculations
    if (neg) {
        B = -B;
    }

    // Iterate through possible values of x from 0 to B
    for (int x = 0; x <= B; x++) {
        // Check if x raised to the power of n equals B
        if (pow(x, n) == B) {
            // If found, print the result considering the sign of B
            printf("%d\n", neg ? -x : x);
            return;
        }
    }

    // If no valid x is found, print "No solution"
    printf("No solution\n");
}

int main() {
    int A, B, n;
    // Read three integers A, B, and n from the input
    scanf("%d %d %d", &A, &B, &n);
    // Call the solve function with the read values
    solve(A, B, n);
    return 0;
}

// <END-OF-CODE>

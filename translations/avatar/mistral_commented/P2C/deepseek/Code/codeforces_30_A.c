#include <stdio.h>
#include <math.h>

// Function to find a number X raised to the power n such that A * X^n equals B
int task4(int A, int B, int n) {

    // Iterate through all possible values of X from -1000 to 1000
    for (int X = -1000; X <= 1000; X++) {

        // Check if the condition A * X^n equals B is satisfied
        if (A * pow(X, n) == B) {

            // If the condition is satisfied, return the value of X
            return X;
        }
    }

    // If no solution is found, return a message indicating that
    return -1; // Using -1 to indicate no solution
}

int main() {

    // Get input values of A, B, and n from the user
    int A, B, n;
    scanf("%d %d %d", &A, &B, &n);

    // Call the function and print the result
    int result = task4(A, B, n);
    if (result != -1) {
        printf("%d\n", result);
    } else {
        printf("No solution\n");
    }

    return 0;
}

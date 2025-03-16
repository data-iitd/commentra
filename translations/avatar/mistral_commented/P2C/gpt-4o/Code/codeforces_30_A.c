#include <stdio.h>

int task4(int A, int B, int n) {
    // Iterate through all possible values of X from -1000 to 1000
    for (int X = -1000; X <= 1000; X++) {
        // Check if the condition A * X^n equals B is satisfied
        if (A * (int)pow(X, n) == B) {
            // If the condition is satisfied, return the value of X
            return X;
        }
    }
    // If no solution is found, return a special value (e.g., -1)
    return -1; // Indicating no solution found
}

int main() {
    int A, B, n;

    // Get input values of A, B, and n from the user
    scanf("%d %d %d", &A, &B, &n);

    // Call the function and print the result
    int result = task4(A, B, n);
    if (result == -1) {
        printf("No solution\n");
    } else {
        printf("%d\n", result);
    }

    return 0;
}

// <END-OF-CODE>

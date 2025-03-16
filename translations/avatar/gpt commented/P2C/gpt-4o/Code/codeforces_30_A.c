#include <stdio.h>

int task4(int A, int B, int n) {
    // Iterate through a range of possible values for X from -1000 to 1000
    for (int X = -1000; X <= 1000; X++) {
        // Check if the equation A * (X ^ n) equals B
        int power = 1;
        for (int i = 0; i < n; i++) {
            power *= X; // Calculate X^n
        }
        if (A * power == B) {
            // If a solution is found, return the value of X
            return X;
        }
    }
    // If no solution is found in the range, return a message indicating no solution
    return -1; // Using -1 to indicate no solution found
}

int main() {
    int A, B, n;
    // Take input from the user
    scanf("%d %d %d", &A, &B, &n);
    
    int result = task4(A, B, n);
    if (result == -1) {
        printf("No solution\n");
    } else {
        printf("%d\n", result);
    }
    
    return 0;
}

// <END-OF-CODE>

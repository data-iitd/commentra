#include <stdio.h>
#include <math.h>

int task4(int A, int B, int n) {
    // Iterate through a range of possible values for X from -1000 to 1000
    for (int X = -1000; X <= 1000; X++) {
        // Check if the equation A * (X ** n) equals B
        if (A * pow(X, n) == B) {
            // If a solution is found, return the value of X
            return X;
        }
    }
    // If no solution is found in the range, return a message indicating no solution
    return -1; // Using -1 to indicate no solution as per the original Python code
}

int main() {
    int A, B, n;
    // Take input from the user and split it into three variables A, B, and n
    scanf("%d %d %d", &A, &B, &n);

    // Call the task4 function with the converted integer values of A, B, and n, and print the result
    int result = task4(A, B, n);
    if (result == -1) {
        printf("No solution\n");
    } else {
        printf("%d\n", result);
    }

    return 0;
}

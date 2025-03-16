#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to read an integer from standard input
int nextInt() {
    int value;
    scanf("%d", &value);
    return value;
}

// Function to output an integer to standard output
void out(int value) {
    printf("%d\n", value);
}

// Function to find the maximum of two integers
int max(int x, int y) {
    return (x > y) ? x : y;
}

// Function to solve the problem
void solve() {
    // Read two integers N and K from standard input
    int N = nextInt();
    int K = nextInt(); // K is read but not used in the solution

    // Initialize an array A of size N
    int *A = (int *)malloc(N * sizeof(int));
    // Read N integers from standard input and store them in the array A
    for (int i = 0; i < N; i++) {
        A[i] = nextInt();
    }

    // Initialize variables maxProfit, maxCnt, and maxA
    int maxProfit = 0;
    int maxCnt = 0;
    int maxA = A[N - 1];

    // Iterate through the array A from the last index to the first index
    for (int i = N - 2; i >= 0; i--) {
        // Calculate the profit of the current transaction
        int profit = max(0, maxA - A[i]);
        // If the current profit is greater than the maximum profit found so far, update maxProfit and maxCnt
        if (maxProfit < profit) {
            maxProfit = profit;
            maxCnt = 1;
        } else if (maxProfit == profit) {
            maxCnt++;
        }
        // Update maxA with the maximum of the current element and maxA
        maxA = max(maxA, A[i]);
    }

    // Write the output to standard output
    out(maxCnt);

    // Free the allocated memory
    free(A);
}

// Main function is the entry point of the program
int main() {
    // Call the solve function to solve the problem
    solve();
    return 0;
}

// <END-OF-CODE>

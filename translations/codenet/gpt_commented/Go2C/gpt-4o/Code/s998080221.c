#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to read an integer from standard input
int nextInt() {
    int value;
    scanf("%d", &value);
    return value;
}

// Function to calculate the maximum of two integers
int max(int x, int y) {
    return (x > y) ? x : y;
}

<<<<<<< HEAD
// Function to solve the problem
=======
// Function to calculate the maximum profit and count
>>>>>>> 98c87cb78a (data updated)
void solve() {
    int N = nextInt(); // Read number of elements
    int *A = (int *)malloc(N * sizeof(int)); // Allocate memory for the array
    for (int i = 0; i < N; i++) {
        A[i] = nextInt(); // Read each element into the array
    }

    int maxProfit = 0; // Initialize maximum profit
    int maxCnt = 0;    // Initialize count of maximum profit occurrences
    int maxA = A[N - 1]; // Start with the last element as the maximum

    for (int i = N - 2; i >= 0; i--) { // Iterate backwards through the array
        int profit = max(0, maxA - A[i]); // Calculate profit based on the current element
        if (maxProfit < profit) { // If we found a new maximum profit
            maxProfit = profit; // Update maximum profit
<<<<<<< HEAD
            maxCnt = 1; // Reset count to 1
=======
            maxCnt = 1;         // Reset count to 1
>>>>>>> 98c87cb78a (data updated)
        } else if (maxProfit == profit) { // If we found another occurrence of the maximum profit
            maxCnt++; // Increment the count
        }
        maxA = max(maxA, A[i]); // Update the maximum element seen so far
    }

    printf("%d\n", maxCnt); // Output the count of maximum profit occurrences
    free(A); // Free allocated memory
}

// Main function to execute the program
int main() {
    solve(); // Call the solve function
    return 0; // Return success
}

// <END-OF-CODE>

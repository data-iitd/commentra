#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 200100 // Define the maximum size for the arrays

<<<<<<< HEAD
=======
// Macro to print the answer followed by a newline
#define fin(ans) printf("%lld\n", (ans))

>>>>>>> 98c87cb78a (data updated)
int main() {
    long long N, K; // Declare variables for number of elements and steps
    long long A[MAX_SIZE]; // Array to store the input values
    long long B[MAX_SIZE]; // Array to track the first visit time to each position
    int now = 1; // Current position, starting at 1
    long long cnt = 0; // Counter for the number of steps taken

    // Read the number of elements (N) and the number of steps (K)
    scanf("%lld %lld", &N, &K);

    // Read the elements into array A
    for (int i = 1; i <= N; i++) {
        scanf("%lld", &A[i]); // Store input values in A, starting from index 1
    }

    // Initialize array B to -1 to indicate unvisited positions
    for (int i = 0; i < MAX_SIZE; i++) {
        B[i] = -1;
    }

    // Mark the starting position as visited at step 0
    long long j;
    B[1] = 0; // Starting point is visited at step 0

    // Traverse the positions based on the values in A
    for (j = 1; j <= K; j++) {
        now = A[now]; // Move to the next position based on the current position

        // Check if the current position has been visited before
        if (B[now] == -1) {
            B[now] = j; // Mark the position with the current step count
        } else {
            // If the position has been visited, calculate the cycle length
            cnt = j; // Store the current step count
            break; // Exit the loop as we found a cycle
        }
    }

    // If we did not reach the maximum steps K
    if (j < K) {
        long long tmp;
        // Calculate how many additional steps to take within the cycle
        tmp = (K - B[now]) % (cnt - B[now]);
        
        // Move to the final position after the calculated additional steps
        for (long long j = 0; j < tmp; j++) {
            now = A[now]; // Continue moving to the next position
        }
    }

    // Output the final position after all movements
<<<<<<< HEAD
    printf("%lld\n", now);
=======
    fin(now);
>>>>>>> 98c87cb78a (data updated)
    return 0; // End of the program
}

// <END-OF-CODE>

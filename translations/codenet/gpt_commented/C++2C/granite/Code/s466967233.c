
#include <stdio.h>

int main()
{
    int N, K; // Declare variables for number of elements and steps
    int A[200100]; // Array to store the input values
    int B[200100] = {-1}; // Array to track the first visit time to each position, initialized to -1
    int now = 1; // Current position, starting at 1
    int cnt = 0; // Counter for the number of steps taken

    // Read the number of elements (N) and the number of steps (K)
    scanf("%d %d", &N, &K);

    // Read the elements into array A
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i + 1]); // Store input values in A, starting from index 1
    }

    // Initialize array B to -1 to indicate unvisited positions
    for (int i = 0; i < 200100; i++) {
        B[i] = -1;
    }

    // Mark the starting position as visited at step 0
    int j;
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
        int tmp;
        // Calculate how many additional steps to take within the cycle
        tmp = (K - B[now]) % (cnt - B[now]);
        
        // Move to the final position after the calculated additional steps
        for (int j = 0; j < tmp; j++) {
            now = A[now]; // Continue moving to the next position
        }
    }

    // Output the final position after all movements
    printf("%d\n", now);
    return 0; // End of the program
}

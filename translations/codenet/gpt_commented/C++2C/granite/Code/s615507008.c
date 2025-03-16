
#include <stdio.h>
#define REP(i, n) for (int i = 0; i < (n); i++)

// Function to solve the problem based on the given parameters
void solve(int N, int* T, int M, int* P, int* X) {
    // Iterate over each modification request
    REP(i, M) {
        int ans = 0; // Initialize the answer for the current modification
        // Calculate the total time considering the current modification
        REP(j, N) {
            // If the current index matches the modified position, add the new time value
            if (j == P[i] - 1) ans += X[i];
            // Otherwise, add the original time value
            else ans += T[j];
        }
        // Output the result for the current modification
        printf("%d\n", ans);
    }
}

int main() {
    int N; // Number of original time values
    scanf("%d", &N); // Read the number of time values
    int T[N]; // Array to store the original time values
    REP(i, N) scanf("%d", &T[i]); // Read the original time values into the array

    int M; // Number of modifications
    scanf("%d", &M); // Read the number of modifications
    int P[M], X[M]; // Arrays to store the positions of modifications and new time values
    REP(i, M) scanf("%d%d", &P[i], &X[i]); // Read the modification positions and new time values

    // Call the solve function to process the modifications and output results
    solve(N, T, M, P, X);
    return 0; // Indicate successful completion of the program
}




#include <stdio.h>
#include <algorithm>
using namespace std;

// Declare global variables
long long N, A[1 << 18]; // N is the number of elements, A is the array to hold the elements
long long dp[1 << 18][2][20]; // dp array for dynamic programming

int main() {
    // Read the number of elements
    scanf("%lld", &N);

    // Read the elements into the array A
    for (int i = 1; i <= N; i++) scanf("%lld", &A[i]);

    // Initialize the dp array with a very small value
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j < 20; j++) {
            dp[i][0][j] = -(1LL << 60); // Initialize dp for state 0
            dp[i][1][j] = -(1LL << 60); // Initialize dp for state 1
        }
    }

    // Base case: when no elements are considered, the value at dp[0][0][10] is 0
    dp[0][0][10] = 0;

    // Fill the dp array based on previous states
    for (int i = 1; i <= N; i++) {
        for (int j = 6; j <= 14; j++) {
            // If the previous state in dp[i-1][0][j] is valid
            if (dp[i - 1][0][j]!= (1LL << 60)) {
                // Update the state dp[i][1][j + 1] by adding the current element A[i]
                dp[i][1][j + 1] = max(dp[i][1][j + 1], dp[i - 1][0][j] + A[i]);
                // Update the state dp[i][0][j - 1] without adding the current element
                dp[i][0][j - 1] = max(dp[i][0][j - 1], dp[i - 1][0][j]);
            }
            // If the previous state in dp[i-1][1][j] is valid
            if (dp[i - 1][1][j]!= (1LL << 60)) {
                // Update the state dp[i][0][j - 1] without adding the current element
                dp[i][0][j - 1] = max(dp[i][0][j - 1], dp[i - 1][1][j]);
            }
        }
    }

    // Calculate the target value V based on the number of elements
    long long V = 10LL + (N / 2) - (N - (N / 2));
    
    // Retrieve the maximum values from the last state of dp
    long long T1 = dp[N][0][V];
    long long T2 = dp[N][1][V];

    // Output the maximum value obtained from the two states
    printf("%lld\n", max(T1, T2));

    return 0; // End of the program
}



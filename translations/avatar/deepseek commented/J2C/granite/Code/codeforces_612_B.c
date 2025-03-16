
#include <stdio.h> // Include the standard input/output library

int main() {
    int n; // Declare an integer variable n
    scanf("%d", &n); // Read the integer n from the input

    int dp[200001]; // Declare an array to store positions
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x); // Read the integer x from the input
        dp[x] = i; // Store the position of x in the array dp
    }

    long long ans = 0; // Declare a long long variable ans
    for (int i = 2; i <= n; i++) {
        ans += abs(dp[i] - dp[i - 1]); // Calculate the absolute difference between consecutive positions and add it to ans
    }

    printf("%lld\n", ans); // Print the final answer
    return 0; // Return 0 to indicate successful execution
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

// Function to find the minimum value among a variable number of integers
int min(int a, int b) {
    return (a < b) ? a : b; // Return the smaller of the two values
}

int main() {
    int H, N, A, B; // Declare variables to store input values
    cin >> H >> N; // Read the values of H and N from standard input

    vector<int> dp(H + 10001, numeric_limits<int>::max()); // Create a vector for dynamic programming with a large initial value
    dp[0] = 0; // Initialize the cost for health 0 to 0

    int amax = 0; // Initialize variable to keep track of the maximum attack value
    for (int i = 0; i < N; i++) {
        cin >> A >> B; // Read the attack value A and the cost B for each attack
        if (A >= amax) {
            amax = A; // Update amax if the current attack value is greater than or equal to the current amax
        }
        dp[A] = min(dp[A], B); // Update the cost for attack value A
        for (int j = A + 1; j <= H + amax + 1; j++) {
            dp[j] = min(dp[j], dp[j - A] + B); // Update the cost for all possible health values using the current attack
        }
    }

    // Print the minimum cost to reduce health H to zero or below
    int result = numeric_limits<int>::max();
    for (int i = H; i <= H + amax; i++) {
        result = min(result, dp[i]);
    }
    cout << result << endl; // Output the result

    return 0;
}

// <END-OF-CODE>

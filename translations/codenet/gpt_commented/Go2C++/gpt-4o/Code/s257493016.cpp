#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

// min function returns the minimum value from a variable number of integer arguments.
// It throws an exception if no arguments are provided.
int min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    int H, N, A, B;
    // Read the total height H and the number of items N from input
    cin >> H >> N;

    // Initialize a dynamic programming array to store the minimum cost for each height
    vector<int> dp(H + 10001, numeric_limits<int>::max()); // Represents a large value (infinity)
    
    int amax = 0; // Variable to track the maximum height of items
    // Process each item
    for (int i = 0; i < N; i++) {
        // Read the height A and cost B of the current item
        cin >> A >> B;
        // Update amax if the current item's height is greater
        if (A >= amax) {
            amax = A;
        }
        // Update the minimum cost for achieving height A
        dp[A] = min(dp[A], B);
        // Update the minimum cost for all heights from A+1 to H+A+1
        for (int j = A + 1; j <= H + amax + 1; j++) {
            dp[j] = min(dp[j], dp[j - A] + B); // Calculate the minimum cost for height j
        }
    }

    // Print the minimum cost to achieve height H considering all possible heights up to amax
    int result = numeric_limits<int>::max();
    for (int i = H; i <= H + amax; i++) {
        result = min(result, dp[i]);
    }
    cout << result << endl;

    return 0;
}

// <END-OF-CODE>

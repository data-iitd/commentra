#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

// Function to find minimum number in a vector
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Main function
int main() {
    // Initialize variables for number of floors H, number of jumps N, and variables A and B for each jump
    int H, N, A, B;
    cin >> H >> N;

    // Initialize a vector dp of size H+10001 with initial value 2100000000
    vector<int> dp(H + 10001, 2100000000);

    // Initialize maximum reachable floor amax to 0
    int amax = 0;

    // Iterate through each jump
    for (int i = 0; i < N; i++) {
        // Read floor A and number of floors B that can be jumped from floor A
        cin >> A >> B;

        // If the maximum reachable floor is less than A, update maximum reachable floor
        if (A >= amax) {
            amax = A;
        }

        // Update dp[A] with minimum of current dp[A] and B
        dp[A] = min(dp[A], B);

        // Iterate through floors from A+1 to H+A and update dp[j] with minimum of current dp[j] and dp[j-A]+B
        for (int j = A + 1; j <= H + A + 1; j++) {
            dp[j] = min(dp[j], dp[j - A] + B);
        }
    }

    // Print the minimum number of jumps required to reach the last floor
    int result = *min_element(dp.begin() + H, dp.begin() + H + amax + 1);
    cout << result << endl;

    // End of code
    return 0;
}

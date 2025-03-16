
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    // Read the number of elements
    int N;
    cin >> N;
    // Read the heights into a vector
    vector<int> h(N);
    for (int i = 0; i < N; i++) {
        cin >> h[i];
    }

    // Initialize a dynamic programming vector to store minimum costs
    vector<int> dp(N);
    for (int i = 0; i < N; i++) {
        dp[i] = 0; // Set initial values to zero
    }
    
    // Base case: cost to jump from the first to the second height
    dp[1] = abs(h[0] - h[1]);

    // Fill the dp vector with minimum costs for each position
    for (int i = 2; i < N; i++) {
        dp[i] = min(dp[i-1] + abs(h[i] - h[i-1]), dp[i-2] + abs(h[i] - h[i-2]));
    }

    // Output the minimum cost to reach the last height
    cout << dp[N-1] << endl;

    return 0;
}


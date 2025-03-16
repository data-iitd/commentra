#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <sstream>

using namespace std;

int nextInt() {
    int x;
    cin >> x;
    return x;
}

vector<int> nextInts(int N) {
    vector<int> h(N);
    for (int i = 0; i < N; i++) {
        cin >> h[i];
    }
    return h;
}

int main() {
    // Read the number of elements
    int N = nextInt();
    // Read the heights into a vector
    vector<int> h = nextInts(N);

    // Initialize a dynamic programming vector to store minimum costs
    vector<int> dp(N, 0);

    // Base case: cost to jump from the first to the second height
    dp[1] = abs(h[0] - h[1]);

    // Fill the dp vector with minimum costs for each position
    for (int i = 2; i < N; i++) {
        dp[i] = min(
            dp[i-1] + abs(h[i] - h[i-1]), // Cost from the previous height
            dp[i-2] + abs(h[i] - h[i-2])  // Cost from two heights back
        );
    }

    // Output the minimum cost to reach the last height
    cout << dp[N-1] << endl;

    return 0;
}


#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// Utility function to find the absolute value of an integer
int Abs(int a) {
    return a < 0 ? -a : a;
}

// Utility function to find the minimum value in a vector of integers
int Min(const vector<int>& a) {
    return *min_element(a.begin(), a.end());
}

// Main function to solve the problem
int main() {
    // Reads the number of steps N
    int N;
    cin >> N;

    // Reads the list of heights h
    vector<int> h(N);
    for (int i = 0; i < N; i++) {
        cin >> h[i];
    }

    // Initializes the DP array with zeros
    vector<int> dp(N, 0);

    // Sets the cost to reach the second step
    dp[1] = Abs(h[0] - h[1]);

    // Computes the minimum cost to reach each step using dynamic programming
    for (int i = 2; i < N; i++) {
        dp[i] = Min({dp[i - 1] + Abs(h[i] - h[i - 1]),
                      dp[i - 2] + Abs(h[i] - h[i - 2])});
    }

    // Prints the minimum cost to reach the last step
    cout << dp[N - 1] << endl;

    return 0;
}

// <END-OF-CODE>

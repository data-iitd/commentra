#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// Function to read an integer from input
int nextInt() {
    int v;
    cin >> v;
    return v;
}

// Function to read a vector of integers from input
vector<int> nextInts(int n) {
    vector<int> r(n);
    for (int i = 0; i < n; i++) {
        r[i] = nextInt();
    }
    return r;
}

// Function to calculate the absolute value
int Abs(int a) {
    return a < 0 ? -a : a;
}

// Function to find the minimum of two integers
int Min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    // Read the number of elements
    int N = nextInt();
    // Read the heights into a vector
    vector<int> h = nextInts(N);

    // Initialize a dynamic programming vector to store minimum costs
    vector<int> dp(N, 0);

    // Base case: cost to jump from the first to the second height
    dp[1] = Abs(h[0] - h[1]);

    // Fill the dp vector with minimum costs for each position
    for (int i = 2; i < N; i++) {
        dp[i] = Min(dp[i - 1] + Abs(h[i] - h[i - 1]), // Cost from the previous height
                    dp[i - 2] + Abs(h[i] - h[i - 2])); // Cost from two heights back
    }

    // Output the minimum cost to reach the last height
    cout << dp[N - 1] << endl;

    return 0;
}

/* <END-OF-CODE> */

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

// Reads the next integer from the input
int nextInt() {
    int x;
    cin >> x;
    return x;
}

// Reads a slice of integers of length N
vector<int> nextInts(int N) {
    vector<int> r(N);
    for (int i = 0; i < N; i++) {
        cin >> r[i];
    }
    return r;
}

// Main function to solve the problem
int main() {
    // Reads the number of steps N
    int N = nextInt(); // Comment: Reads the number of steps N
    
    // Reads the list of heights h
    vector<int> h = nextInts(N); // Comment: Reads the list of heights h
    
    // Initializes the DP array with zeros
    vector<int> dp(N, 0); // Comment: Initializes the DP array with zeros
    
    // Sets the cost to reach the second step
    dp[1] = abs(h[0] - h[1]); // Comment: Sets the cost to reach the second step
    
    // Computes the minimum cost to reach each step using dynamic programming
    for (int i = 2; i < N; i++) {
        dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]),
                    dp[i - 2] + abs(h[i] - h[i - 2]));
    }
    
    // Prints the minimum cost to reach the last step
    cout << dp[N-1] << endl; // Comment: Prints the minimum cost to reach the last step
}

// Utility function to find the absolute value of an integer
int abs(int a) {
    return a < 0 ? -a : a;
}

// Utility function to find the minimum value in a slice of integers
int min(int a, int b) {
    return a < b ? a : b;
}

// Utility function to find the maximum value in a slice of integers
int max(const vector<int>& a) {
    int r = a[0];
    for (int i = 0; i < a.size(); i++) {
        if (r < a[i]) {
            r = a[i];
        }
    }
    return r;
}

// Utility function to calculate the sum of a slice of integers
int sum(const vector<int>& a) {
    int r = 0;
    for (int i : a) {
        r += i;
    }
    return r;
}

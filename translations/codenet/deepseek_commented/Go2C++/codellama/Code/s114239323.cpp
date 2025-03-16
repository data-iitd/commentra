
#include <bits/stdc++.h>

using namespace std;

// Reads the next integer from the input
int nextInt() {
    return nextInt(); // Comment: Reads the next integer from the input
}

// Reads a slice of integers of length N
vector<int> nextInts(int N) {
    return nextInts(N); // Comment: Reads a slice of integers of length N
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
    cout << dp[N - 1] << endl; // Comment: Prints the minimum cost to reach the last step
    
    return 0;
}

// Utility function to find the absolute value of an integer
int abs(int a) {
    if (a < 0) {
        return -a;
    }
    return a;
}

// Utility function to find the maximum value in a vector of integers
int max(vector<int> a) {
    int r = a[0];
    for (int i = 0; i < a.size(); i++) {
        if (r < a[i]) {
            r = a[i];
        }
    }
    return r;
}

// Utility function to find the minimum value in a vector of integers
int min(vector<int> a) {
    int r = a[0];
    for (int i = 0; i < a.size(); i++) {
        if (r > a[i]) {
            r = a[i];
        }
    }
    return r;
}

// Utility function to calculate the sum of a vector of integers
int sum(vector<int> a) {
    int r = 0;
    for (int i = 0; i < a.size(); i++) {
        r += a[i];
    }
    return r;
}

// Pair struct to represent a pair of integers
struct Pair {
    int a, b;
};

// Pairs vector to represent a vector of Pair
vector<Pair> pairs;

// Less function to compare two elements in the Pairs vector
bool less(Pair a, Pair b) {
    return a.b < b.b;
}

// nextString function to read the next string
string nextString() {
    return nextString();
}

// nextInt64 function to read the next 64-bit integer
long long nextInt64() {
    long long v;
    cin >> v;
    return v;
}

// nextInt function to read the next integer
int nextInt() {
    int v;
    cin >> v;
    return v;
}

// nextInts function to read a slice of integers of length N
vector<int> nextInts(int N) {
    vector<int> r(N);
    for (int i = 0; i < N; i++) {
        cin >> r[i];
    }
    return r;
}

// nextStrings function to read a slice of strings of length N
vector<string> nextStrings(int N) {
    vector<string> r(N);
    for (int i = 0; i < N; i++) {
        cin >> r[i];
    }
    return r;
}

// nextFloat64 function to read the next float64
double nextFloat64() {
    double f;
    cin >> f;
    return f;
}


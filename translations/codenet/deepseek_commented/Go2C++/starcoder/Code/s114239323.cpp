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
    for (int i = 0; i < N; i++) {
        dp[i] = 0;
    }
    
    // Sets the cost to reach the second step
    dp[1] = abs(h[0] - h[1]); // Comment: Sets the cost to reach the second step
    
    // Computes the minimum cost to reach each step using dynamic programming
    for (int i = 2; i < N; i++) {
        dp[i] = min({dp[i - 1] + abs(h[i] - h[i - 1]),
                     dp[i - 2] + abs(h[i] - h[i - 2])});
    }
    
    // Prints the minimum cost to reach the last step
    cout << dp[N - 1] << endl; // Comment: Prints the minimum cost to reach the last step
}

// Utility function to find the absolute value of an integer
int Abs(int a) {
    if (a < 0) {
        return -a;
    }
    return a;
}

// Utility function to find the maximum value in a slice of integers
int Max(vector<int> a) {
    int r = a[0];
    for (int i = 0; i < a.size(); i++) {
        if (r < a[i]) {
            r = a[i];
        }
    }
    return r;
}

// Utility function to find the minimum value in a slice of integers
int Min(vector<int> a) {
    int r = a[0];
    for (int i = 0; i < a.size(); i++) {
        if (r > a[i]) {
            r = a[i];
        }
    }
    return r;
}

// Utility function to calculate the sum of a slice of integers
int Sum(vector<int> a) {
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

// Pairs slice to represent a slice of Pair
typedef vector<Pair> Pairs;

// Len method to get the length of the Pairs slice
int (Pairs::*len)() const = &Pairs::size;

// Swap method to swap two elements in the Pairs slice
void (Pairs::*swap)(int, int) = &Pairs::swap;

// Less method to compare two elements in the Pairs slice
bool (Pairs::*less)(int, int) = &Pairs::operator[];

// Variable to hold the nextReader function
auto nextReader = []() {
    string s;
    cin >> s;
    return s;
};

// Initializes the nextReader function
void init() {
    nextReader = []() {
        string s;
        cin >> s;
        return s;
    };
}

// nextString function to read the next string
string nextString() {
    return nextReader();
}

// nextInt64 function to read the next 64-bit integer
int64_t nextInt64() {
    int64_t v;
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
vector<int> nextInts(int n) {
    vector<int> r(n);
    for (int i = 0; i < n; i++) {
        r[i] = nextInt();
    }
    return r;
}

// nextStrings function to read a slice of strings of length N
vector<string> nextStrings(int n) {
    vector<string> r(n);
    for (int i = 0; i < n; i++) {
        r[i] = nextString();
    }
    return r;
}

// nextFloat64 function to read the next float64
double nextFloat64() {
    double v;
    cin >> v;
    return v;
}



#include <bits/stdc++.h>
using namespace std;

// Reads the next integer from the input
int nextInt() {
    return nextInt(); // Comment: Reads the next integer from the input
}

// Reads a slice of integers of length N
vector<int> nextInts(int N) {
    vector<int> r(N);
    for (int i = 0; i < N; i++) {
        r[i] = nextInt();
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
    vector<int> dp(N);
    for (int i = 0; i < N; i++) {
        dp[i] = 0;
    }
    
    // Sets the cost to reach the second step
    dp[1] = abs(h[0] - h[1]); // Comment: Sets the cost to reach the second step
    
    // Computes the minimum cost to reach each step using dynamic programming
    for (int i = 2; i < N; i++) {
        dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]),
                     dp[i - 2] + abs(h[i] - h[i - 2]));
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

// Utility function to find the maximum value in a vector of integers
int Max(vector<int> a) {
    int r = a[0];
    for (int i = 0; i < a.size(); i++) {
        if (r < a[i]) {
            r = a[i];
        }
    }
    return r;
}

// Utility function to find the minimum value in a vector of integers
int Min(vector<int> a) {
    int r = a[0];
    for (int i = 0; i < a.size(); i++) {
        if (r > a[i]) {
            r = a[i];
        }
    }
    return r;
}

// Utility function to calculate the sum of a vector of integers
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

// Pairs vector to represent a vector of Pair
vector<Pair> Pairs;

// Len method to get the length of the Pairs vector
int Len() {
    return Pairs.size();
}

// Swap method to swap two elements in the Pairs vector
void Swap(int i, int j) {
    swap(Pairs[i], Pairs[j]);
}

// Less method to compare two elements in the Pairs vector
bool Less(int i, int j) {
    return Pairs[i].b < Pairs[j].b;
}

// Variable to hold the nextReader function
string (*nextReader)();

// Initializes the nextReader function
void init() {
    nextReader = NewScanner;
}

// NewScanner function to create a new scanner for reading input
string NewScanner() {
    string r;
    getline(cin, r);
    return r;
}

// nextString function to read the next string
string nextString() {
    return nextReader();
}

// nextInt64 function to read the next 64-bit integer
int64_t nextInt64() {
    int64_t r;
    cin >> r;
    return r;
}

// nextInt function to read the next integer
int nextInt() {
    int r;
    cin >> r;
    return r;
}

// nextInts function to read a vector of integers of length N
vector<int> nextInts(int n) {
    vector<int> r(n);
    for (int i = 0; i < n; i++) {
        cin >> r[i];
    }
    return r;
}

// nextStrings function to read a vector of strings of length N
vector<string> nextStrings(int n) {
    vector<string> r(n);
    for (int i = 0; i < n; i++) {
        cin >> r[i];
    }
    return r;
}

// nextFloat64 function to read the next float64
double nextFloat64() {
    double r;
    cin >> r;
    return r;
}

// Main function to solve the problem
int main() {
    // Reads the number of steps N
    int N = nextInt(); // Comment: Reads the number of steps N
    
    // Reads the list of heights h
    vector<int> h = nextInts(N); // Comment: Reads the list of heights h
    
    // Initializes the DP array with zeros
    vector<int> dp(N);
    for (int i = 0; i < N; i++) {
        dp[i] = 0;
    }
    
    // Sets the cost to reach the second step
    dp[1] = abs(h[0] - h[1]); // Comment: Sets the cost to reach the second step
    
    // Computes the minimum cost to reach each step using dynamic programming
    for (int i = 2; i < N; i++) {
        dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]),
                     dp[i - 2] + abs(h[i] - h[i - 2]));
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

// Utility function to find the maximum value in a vector of integers
int Max(vector<int> a) {
    int r = a[0];
    for (int i = 0; i < a.size(); i++) {
        if (r < a[i]) {
            r = a[i];
        }
    }
    return r;
}

// Utility function to find the minimum value in a vector of integers
int Min(vector<int> a) {
    int r = a[0];
    for (int i = 0; i < a.size(); i++) {
        if (r > a[i]) {
            r = a[i];
        }
    }
    return r;
}

// Utility function to calculate the sum of a vector of integers
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

// Pairs vector to represent a vector of Pair
vector<Pair> Pairs;

// Len method to get the length of the Pairs vector
int Len() {
    return Pairs.size();
}

// Swap method to swap two elements in the Pairs vector
void Swap(int i, int j) {
    swap(Pairs[i], Pairs[j]);
}

// Less method to compare two elements in the Pairs vector
bool Less(int i, int j) {
    return Pairs[i].b < Pairs[j].b;
}

// Variable to hold the nextReader function
string (*nextReader)();

// Initializes the nextReader function
void init() {
    nextReader = NewScanner;
}

// NewScanner function to create a new scanner for reading input
string NewScanner() {
    string r;
    getline(cin, r);
    return r;
}

// nextString function to read the next string
string nextString() {
    return nextReader();
}

// nextInt64 function to read the next 64-bit integer
int64_t nextInt64() {
    int64_t r;
    cin >> r;
    return r;
}

// nextInt function to read the next integer
int nextInt() {
    int r;
    cin >> r;
    return r;
}

// nextInts function to read a vector of integers of length N
vector<int> nextInts(int n) {
    vector<int> r(n);
    for (int i = 0; i < n; i++) {
        cin >> r[i];
    }
    return r;
}

// nextStrings function to read a vector of strings of length N
vector<string> nextStrings(int n) {
    vector<string> r(n);
    for (int i = 0; i < n; i++) {
        cin >> r[i];
    }
    return r;
}

// nextFloat64 function to read the next float64
double nextFloat64() {
    double r;
    cin >> r;
    return r;
}

// Main function to solve the problem
int main() {
    // Reads the number of steps N
    int N = nextInt(); // Comment: Reads the number of steps N
    
    // Reads the list of heights h
    vector<int> h = nextInts(N); // Comment: Reads the list of heights h
    
    // Initializes the DP array with zeros
    vector<int> dp(N);
    for (int i = 0; i < N; i++) {
        dp[i] = 0;
    }
    
    // Sets the cost to reach the second step
    dp[1] = abs(h[0] - h[1]); // Comment: Sets the cost to reach the second step
    
    // Computes the minimum cost to reach each step using dynamic programming
    for (int i = 2; i < N; i++) {
        dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]),
                     dp[i - 2] + abs(h[i] - h[i - 2]));
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

// Utility function to find the maximum value in a vector of integers
int Max(vector<int> a) {
    int r = a[0];
    for (int i = 0; i < a.size(); i++) {
        if (r < a[i]) {
            r = a[i];
        }
    }
    return r;
}

// Utility function to find the minimum value in a vector of integers
int Min(vector<int> a) {
    int r = a[0];
    for (int i = 0; i < a.size(); i++) {
        if (r > a[i]) {
            r = a[i];
        }
    }
    return r;
}

// Utility function to calculate the sum of a vector of integers
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

// Pairs vector to represent a vector of Pair
vector<Pair> Pairs;

// Len method to get the length of the Pairs vector
int Len() {
    return Pairs.size();
}

// Swap method to swap two elements in the Pairs vector
void Swap(int i, int j) {
    swap(Pairs[i], Pairs[j]);
}

// Less method to compare two elements in the Pairs vector
bool Less(int i, int j) {
    return Pairs[i].b < Pairs[j].b;
}

// Variable to hold the nextReader function
string (*nextReader)();

// Initializes the nextReader function
void init() {
    nextReader = NewScanner;
}

// NewScanner function to create a new scanner for reading input
string NewScanner() {
    string r;
    getline(cin, r);
    return r;
}

// nextString function to read the next string
string nextString() {
    return nextReader();
}

// nextInt64 function to read the next 64-bit integer
int64_t nextInt64() {
    int64_t r;
    cin >> r;
    return r;
}

// nextInt function to read the next integer
int nextInt() {
    int r;
    cin >> r;
    return r;
}

// nextInts function to read a vector of integers of length N
vector<int> nextInts(int n) {
    vector<int> r(n);
    for (int i = 0; i < n; i++) {
        cin >> r[i];
    }
    return r;
}

// nextStrings function to read a vector of strings o
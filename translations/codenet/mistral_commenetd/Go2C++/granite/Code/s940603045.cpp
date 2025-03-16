
#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;
const long long Inf = 1e18;
const int mod = 1;
template<typename T> using vec = vector<T>;
template<typename T> using mat = vector<vec<T>>;

// Constants and variables declaration
const int dx[9] = {1, 0, -1, 0, 1, -1, -1, 1, 0};
const int dy[9] = {0, 1, 0, -1, 1, 1, -1, -1, 0};

int N, m;

// Global variables declaration

// Function declarations

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Read input N as a string
    cin >> N;
    // Convert N to an integer
    stringstream ss;
    ss << N;
    int n = 0;
    // Iterate through each digit in the number N
    while (ss >> m) {
        n += m; // Convert each digit to an integer and add to the sum
    }
    // Read input m as an integer
    cin >> m;
    // Check if m is divisible by n
    if (m % n == 0) {
        cout << "Yes" << endl; // Print "Yes" if m is divisible by n
    } else {
        cout << "No" << endl; // Print "No" if m is not divisible by n
    }

    return 0;
}



#include <bits/stdc++.h>
using namespace std;

// Function to read input
void read(int &n, int &m, int a[]) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

// Function to write output
void write(long long ans) {
    cout << ans << endl;
}

// Function to solve the problem
void solve(int testNumber, int n, int m, int a[]) {
    // Initialize data structures
    long long ans = 0; // Answer variable
    int base = 0; // Base value for hashmap key
    map<int, int> dp; // Hashmap to store intermediate results

    // Process each element in array a
    for (int i = 0; i < n; i++) {
        // Update base value
        base = (base - a[i] % m + m) % m;

        // Update hashmap with current base and its count
        dp[base + a[i] % m]++;

        // Update answer variable
        ans += dp[base];
    }

    // Print the answer
    write(ans);
}

// Main function to start the program
int main() {
    int t; // Number of test cases
    cin >> t; // Read number of test cases
    for (int i = 0; i < t; i++) {
        int n, m; // Number of elements in array a and modulus value
        int a[100000]; // Array a
        read(n, m, a); // Read input
        solve(i + 1, n, m, a); // Solve the problem
    }
    return 0;
}



#include <bits/stdc++.h>
using namespace std;

// Define constants and global variables
int N;  // Number of inputs
vector<string> S;  // List of strings as inputs
vector<int> march = {0, 0, 0, 0, 0};  // List to store the count of each marching order
int ans = 0;  // Variable to store the answer
const int MOD = 1e9 + 7;  // Modulus value

// Define functions if any
// Function to read input as integer
int input() { int x; cin >> x; return x; }
// Function to read input as list of integers
vector<int> LIST(int n) { vector<int> res(n); for (auto &resolve : res) cin >> resolve; return res; }
// Function to read input as list of integers with given number of inputs
vector<vector<int>> ZIP(int n) { vector<vector<int>> res(n); for (int i = 0; i < n; i++) res[i] = LIST(n); return res; }

// Main logic of the code
// Initialize march with zeros
march = vector<int>(5, 0);
// Iterate through each string in S and increment the count of the corresponding marching order in march
for (auto &s : S) {
    if (s[0] >= 'A' && s[0] <= 'Z') {
        march[s[0] - 'A']++;
    }
}
// Calculate the answer by finding the triple product of the counts of each marching order
for (int i = 0; i < 3; i++) {
    for (int j = i + 1; j < 4; j++) {
        for (int k = j + 1; k < 5; k++) {
            ans += march[i] * march[j] * march[k];
        }
    }
}
// Print the answer
cout << ans << endl;


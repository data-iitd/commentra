#include <bits/stdc++.h>
using namespace std;

// Define constants and global variables
const int N = INT();  // Number of inputs
string S[N];  // List of strings as inputs
string march[] = {"M", "A", "R", "C", "H"};  // List of marching orders
int march_lis[5] = {0};  // List to store the count of each marching order
int ans = 0;  // Variable to store the answer
const int INF = 1e9 + 7;  // Modulus value

// Define functions if any
// Function to read input as integer
int input() {
    string s;
    cin >> s;
    return stoi(s);
}
// Function to read input as list of integers
vector<int> LIST() {
    string s;
    cin >> s;
    vector<int> v;
    for (int i = 0; i < s.size(); i++) {
        v.push_back(s[i] - '0');
    }
    return v;
}
// Function to read input as list of integers with given number of inputs
vector<vector<int>> ZIP(int n) {
    vector<vector<int>> v(n);
    for (int i = 0; i < n; i++) {
        v[i] = LIST();
    }
    return v;
}
// Set recursion limit
setRecursionLimit(1000000000);

// Main logic of the code
// Initialize march_lis with zeros
for (int i = 0; i < 5; i++) {
    march_lis[i] = 0;
}
// Iterate through each string in S and increment the count of the corresponding marching order in march_lis
for (int i = 0; i < N; i++) {
    for (int j = 0; j < 5; j++) {
        if (S[i][j] == march[j]) {
            march_lis[j]++;
        }
    }
}
// Calculate the answer by finding the triple product of the counts of each marching order
for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
        for (int k = 0; k < 5; k++) {
            ans += march_lis[i] * march_lis[j] * march_lis[k];
        }
    }
}
// Print the answer
cout << ans << endl;


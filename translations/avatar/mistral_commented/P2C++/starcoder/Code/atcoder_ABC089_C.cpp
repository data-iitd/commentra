#include <bits/stdc++.h>
using namespace std;

// Define constants and global variables
const int N = 100000;  // Number of inputs
string S[N];  // List of strings as inputs
int march[5] = {0, 0, 0, 0, 0};  // List of marching orders
int march_lis[5];  // List to store the count of each marching order
int ans = 0;  // Variable to store the answer
const int INF = 1e9;  // Infinity value
const int mod = 1e9 + 7;  # Modulus value

// Define functions if any
// Function to read input as integer
int input() { return int(cin.get()); }
// Function to read input as list of integers
vector<int> LIST() { return vector<int>(istream_iterator<int>(cin), istream_iterator<int>()); }
// Function to read input as list of integers with given number of inputs
vector<vector<int>> ZIP(int n) { return vector<vector<int>>(n, LIST()); }

// Main logic of the code
// Initialize march_lis with zeros
for (int i = 0; i < 5; i++) march_lis[i] = 0;
// Iterate through each string in S and increment the count of the corresponding marching order in march_lis
for (int i = 0; i < N; i++) {
    if (S[i][0] == 'M' || S[i][0] =='m') march_lis[0]++;
    else if (S[i][0] == 'A' || S[i][0] == 'a') march_lis[1]++;
    else if (S[i][0] == 'R' || S[i][0] == 'r') march_lis[2]++;
    else if (S[i][0] == 'C' || S[i][0] == 'c') march_lis[3]++;
    else if (S[i][0] == 'H' || S[i][0] == 'h') march_lis[4]++;
}
// Calculate the answer by finding the triple product of the counts of each marching order
for (int x = 0; x < 5; x++) {
    for (int y = 0; y < 5; y++) {
        for (int z = 0; z < 5; z++) {
            ans += march_lis[x] * march_lis[y] * march_lis[z];
        }
    }
}
// Print the answer
cout << ans << endl;


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <sstream>

using namespace std;

// Initialize input and output streams
istream& in = cin;
ostream& out = cout;

// Declare global variables
int N, ss, ans, A, B, C;

// Recursive function to explore all distributions of items
void dfs(vector<int>& dp, int times, const vector<int>& arr) {
    // Base case: if all items have been considered
    if (times >= N) {
        ans = min(ans, calc(dp, arr)); // Calculate cost and update answer
        return;
    }

    // Explore all possible distributions (0 to 3)
    for (int i = 0; i < 4; i++) {
        dp[times] = i; // Assign current item to one of the four groups
        dfs(dp, times + 1, arr); // Recur for the next item
    }
}

// Calculate the cost of the current distribution
int calc(const vector<int>& dp, const vector<int>& arr) {
    int cost = 0; // Initialize cost

    // Count items in each group and calculate their sums
    vector<int> memo(4, 0);
    int AA = 0, BB = 0, CC = 0;
    for (int i = 0; i < N; i++) {
        memo[dp[i]]++; // Count items in each group
        if (dp[i] == 1) {
            AA += arr[i]; // Sum for group A
        } else if (dp[i] == 2) {
            BB += arr[i]; // Sum for group B
        } else if (dp[i] == 3) {
            CC += arr[i]; // Sum for group C
        }
    }

    // Calculate the cost based on the differences from target values
    cost += abs(A - AA) + abs(B - BB) + abs(C - CC);

    // Penalize for missing groups and excess items
    for (int i = 1; i < 4; i++) {
        int a = memo[i];
        if (a < 1) {
            cost += 10000; // High penalty for missing group
        } else {
            cost += (a - 1) * 10; // Penalty for excess items
        }
    }

    return cost; // Return the calculated cost
}

int main() {
    // Read input values and split them into a vector of strings
    string line;
    getline(in, line);
    stringstream ss(line);
    vector<string> X;
    string token;
    while (getline(ss, token, ' ')) {
        X.push_back(token);
    }

    // Parse the first four values from the input
    N = stoi(X[0]); // Number of elements
    A = stoi(X[1]); // Target value A
    B = stoi(X[2]); // Target value B
    C = stoi(X[3]); // Target value C

    // Initialize vector for dynamic programming and results
    vector<int> arr(N); // Array to hold input values
    vector<int> dp(N);  // DP array to store current state
    ans = 10000;        // Initialize answer with a large value
    ss = A + B + C;     // Sum of target values

    // Read N integers from input and populate the array
    for (int i = 0; i < N; i++) {
        getline(in, line);
        arr[i] = stoi(line); // Store the integer in the array
    }

    // Perform depth-first search to find the optimal distribution
    dfs(dp, 0, arr);

    // Output the final answer
    out << ans << endl;

    return 0;
}


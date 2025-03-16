
```cpp
#include <bits/stdc++.h>
using namespace std;

// Define global variables
int N, ss, ans, A, B, C;

// Define a function to read the next line of input
string nextLine() {
    string line;
    getline(cin, line);
    return line;
}

// Define a function to find the minimum of two integers
int min(int a, int b) {
    return a < b? a : b;
}

// Define a function to find the absolute value of an integer
int abs(int a) {
    return a < 0? a * -1 : a;
}

// Define a function to calculate the cost of the current distribution
int calc(vector<int>& dp, vector<int>& arr) {
    int cost = 0, AA = 0, BB = 0, CC = 0;
    vector<int> memo(4, 0);

    // Count items in each group and calculate their sums
    for (int i = 0; i < N; i++) {
        memo[dp[i]]++;
        if (dp[i] == 1) {
            AA += arr[i];
        } else if (dp[i] == 2) {
            BB += arr[i];
        } else if (dp[i] == 3) {
            CC += arr[i];
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

// Define a function to perform depth-first search to find the optimal distribution
void dfs(vector<int>& dp, int times, vector<int>& arr) {
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

int main() {
    // Read input values and split them into a vector of strings
    vector<string> X = {"4 10 10 10", "10", "20", "30", "40"};

    // Parse the first four values from the input
    N = stoi(X[0].substr(0, X[0].find(" "))); // Number of elements
    A = stoi(X[0].substr(X[0].find(" ") + 1, X[0].find(" ", X[0].find(" ") + 1))); // Target value A
    B = stoi(X[0].substr(X[0].find(" ", X[0].find(" ") + 1) + 1, X[0].find(" ", X[0].find(" ", X[0].find(" ") + 1) + 1))); // Target value B
    C = stoi(X[0].substr(X[0].find(" ", X[0].find(" ", X[0].find(" ") + 1) + 1) + 1)); // Target value C

    // Initialize vectors for dynamic programming and results
    vector<int> arr(N); // Array to hold input values
    vector<int> dp(N); // DP array to store current state
    ans = 10000; // Initialize answer with a large value
    ss = A + B + C; // Sum of target values

    // Read N integers from input and populate the vector
    for (int i = 1; i < X.size(); i++) {
        arr[i - 1] = stoi(X[i]); // Store the integer in the vector
    }

    // Perform depth-first search to find the optimal distribution
    dfs(dp, 0, arr);

    // Output the final answer
    cout << ans << endl;

    return 0;
}


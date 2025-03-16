
#include <bits/stdc++.h>
using namespace std;

// Scanner and Writer for efficient I/O operations
#define sc cin
#define wtr cout

// Global variables to store input values
int N, ss, ans, A, B, C;

// Main function to execute the program
int main() {
    // Read the input values for N, A, B, and C
    string X;
    getline(cin, X);
    stringstream ss(X);
    ss >> N >> A >> B >> C;

    // Initialize the array to store the values and a dp array for choices
    vector<int> arr(N);
    vector<int> dp(N);
    ans = 10000;
    ss = A + B + C;

    // Read the array values from input
    for (int i = 0; i < N; i++) {
        getline(cin, X);
        stringstream ss(X);
        ss >> arr[i];
    }

    // Start the depth-first search to find the minimum cost
    dfs(dp, 0, arr);

    // Print the minimum cost found
    cout << ans << endl;
    return 0;
}

// Depth-first search function to explore different combinations of choices
void dfs(vector<int> &dp, int times, vector<int> &arr) {
    if (times >= N) {
        ans = min(ans, calc(dp, arr));
        return;
    }

    for (int i = 0; i < 4; i++) {
        dp[times] = i;
        dfs(dp, times + 1, arr);
    }
}

// Function to calculate the cost based on the chosen combinations
int calc(vector<int> &dp, vector<int> &arr) {
    int cost = 0, AA = 0, BB = 0, CC = 0;

    // Create a memoization array to count the occurrences of each choice
    vector<int> memo(4);
    for (int i = 0; i < dp.size(); i++) {
        memo[dp[i]]++;
        if (dp[i] == 1) {
            AA += arr[i];
        } else if (dp[i] == 2) {
            BB += arr[i];
        } else if (dp[i] == 3) {
            CC += arr[i];
        }
    }
    cost += abs(A - AA) + abs(B - BB) + abs(C - CC);

    // Add additional cost for each choice that appears more than once
    for (int i = 1; i < 4; i++) {
        int a = memo[i];
        if (a < 1) {
            cost += 10000;
        } else {
            cost += (a - 1) * 10;
        }
    }

    return cost;
}

// Helper functions to read input, calculate minimum, and absolute value
string nextLine() {
    string str;
    getline(cin, str);
    return str;
}

int min(int a, int b) {
    if (a < b) {
        return a;
    }
    return b;
}

int abs(int a) {
    if (a < 0) {
        return a * -1;
    }
    return a;
}

// End of code

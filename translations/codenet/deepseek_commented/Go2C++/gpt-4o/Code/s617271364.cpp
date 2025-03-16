#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <limits>

using namespace std;

// Global variables to store input values
int N, ss, ans, A, B, C;

// Function to read a line of input
string nextLine() {
    string line;
    getline(cin, line);
    return line;
}

// Function to calculate the minimum of two integers
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Function to calculate the absolute value
int abs(int a) {
    return (a < 0) ? -a : a;
}

// Function to calculate the cost based on the chosen combinations
int calc(const vector<int>& dp, const vector<int>& arr) {
    int cost = 0, AA = 0, BB = 0, CC = 0;
    vector<int> memo(4, 0);

    for (size_t i = 0; i < dp.size(); i++) {
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

// Depth-first search function to explore different combinations of choices
void dfs(vector<int>& dp, int times, const vector<int>& arr) {
    if (times >= N) {
        ans = min(ans, calc(dp, arr));
        return;
    }

    for (int i = 0; i < 4; i++) {
        dp[times] = i;
        dfs(dp, times + 1, arr);
    }
}

// Main function to execute the program
int main() {
    // Read the input values for N, A, B, and C
    string line = nextLine();
    sscanf(line.c_str(), "%d %d %d %d", &N, &A, &B, &C);

    // Initialize the array to store the values and a dp array for choices
    vector<int> arr(N);
    vector<int> dp(N);
    ans = numeric_limits<int>::max();
    ss = A + B + C;

    // Read the array values from input
    for (int i = 0; i < N; i++) {
        line = nextLine();
        sscanf(line.c_str(), "%d", &arr[i]);
    }

    // Start the depth-first search to find the minimum cost
    dfs(dp, 0, arr);

    // Print the minimum cost found
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>

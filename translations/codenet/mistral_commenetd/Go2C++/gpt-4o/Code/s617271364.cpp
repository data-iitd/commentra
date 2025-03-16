// Include necessary headers
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <limits>

using namespace std;

// Global variables
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

// Function to calculate the absolute value of an integer
int abs(int a) {
    return (a < 0) ? -a : a;
}

// Function to calculate the cost
int calc(const vector<int>& dp, const vector<int>& arr) {
    int cost = 0, AA = 0, BB = 0, CC = 0;
    vector<int> memo(4, 0);

    for (int i = 0; i < dp.size(); i++) {
        int a = dp[i];
        memo[a]++;
        if (a == 1) {
            AA += arr[i];
        } else if (a == 2) {
            BB += arr[i];
        } else if (a == 3) {
            CC += arr[i];
        }
    }

    cost += abs(A - AA) + abs(B - BB) + abs(C - CC);

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

// Depth-first search function
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

// Main function
int main() {
    // Read the first line which contains the number of tests and the number of elements in the array
    string line = nextLine();
    sscanf(line.c_str(), "%d %d %d %d", &N, &A, &B, &C);
    ss = A + B + C;

    // Initialize the array and the dp array
    vector<int> arr(N);
    vector<int> dp(N);

    // Initialize the answer variable
    ans = 10000;

    // Read the next N lines which contain the elements of the array
    for (int i = 0; i < N; i++) {
        line = nextLine();
        sscanf(line.c_str(), "%d", &arr[i]);
    }

    // Call the dfs function to find the minimum cost
    dfs(dp, 0, arr);

    // Print the answer
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>

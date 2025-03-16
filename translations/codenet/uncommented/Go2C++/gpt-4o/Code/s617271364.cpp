#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;

int N, ss, ans, A, B, C;

// Function to read the next line of input
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

// Function to calculate the cost based on the current distribution
int calc(const vector<int>& dp, const vector<int>& arr) {
    int cost = 0, AA = 0, BB = 0, CC = 0;
    vector<int> memo(4, 0);

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

// Depth-first search function to explore all distributions
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

int main() {
    string input = nextLine();
    vector<string> X;
    size_t pos = 0;
    while ((pos = input.find(' ')) != string::npos) {
        X.push_back(input.substr(0, pos));
        input.erase(0, pos + 1);
    }
    X.push_back(input);

    N = stoi(X[0]);
    A = stoi(X[1]);
    B = stoi(X[2]);
    C = stoi(X[3]);

    vector<int> arr(N);
    vector<int> dp(N);
    ans = numeric_limits<int>::max();
    ss = A + B + C;

    for (int i = 0; i < N; i++) {
        string Y = nextLine();
        arr[i] = stoi(Y);
    }

    dfs(dp, 0, arr);

    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>

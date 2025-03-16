#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <limits>
#include <numeric>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <climits>
#include <cassert>

using namespace std;

#define MOD 1000000007

int input() {
    int n;
    cin >> n;
    return n;
}

vector<int> input_array() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    return arr;
}

string input_string() {
    string s;
    cin >> s;
    return s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string S = input_string();
    int n = S.size();
    if (n == 1) {
        if (S == "5" || S == "?") {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
        return 0;
    }

    vector<vector<int>> dp(n, vector<int>(13, 0));
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            if (S[i] != '?') {
                dp[i][stoi(S[i])] += 1;
            } else {
                for (int j = 0; j < 10; ++j) {
                    dp[i][j] += 1;
                }
            }
        } else {
            if (S[i] != '?') {
                for (int k = 0; k < 13; ++k) {
                    dp[i][(k * 10 + (S[i] - '0')) % 13] += dp[i - 1][k];
                }
            } else {
                for (int j = 0; j < 10; ++j) {
                    for (int k = 0; k < 13; ++k) {
                        dp[i][(k * 10 + j) % 13] += dp[i - 1][k];
                    }
                }
            }
            for (int k = 0; k < 13; ++k) {
                dp[i][k] %= MOD;
            }
        }
    }
    cout << dp[n - 1][5] << endl;
}


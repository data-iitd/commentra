
// C++ code
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, A, B, C, ans, ss;
vector<int> arr, dp;

void dfs(int times, vector<int> &dp, vector<int> &arr) {
    if (times >= N) {
        int cost = 0;
        int AA = 0, BB = 0, CC = 0;
        vector<int> memo(4, 0);
        for (int i = 0; i < N; i++) {
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
        ans = min(ans, cost);
        return;
    }
    for (int i = 0; i < 4; i++) {
        dp[times] = i;
        dfs(times + 1, dp, arr);
    }
}

int main() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    ss >> N >> A >> B >> C;
    ss.clear();
    arr.resize(N);
    dp.resize(N);
    ans = 10000;
    ss = A + B + C;
    for (int i = 0; i < N; i++) {
        getline(cin, line);
        stringstream ss(line);
        ss >> arr[i];
    }
    dfs(0, dp, arr);
    cout << ans << endl;
    return 0;
}

// 

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

int main() {
    int N, A, B, C;
    cin >> N >> A >> B >> C;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int ans = 10000;
    int ss = A + B + C;
    vector<int> dp(N);
    dfs(dp, 0, arr);

    cout << ans << endl;

    return 0;
}

void dfs(vector<int>& dp, int times, vector<int>& arr) {
    if (times >= N) {
        ans = min(ans, calc(dp, arr));
        return;
    }

    for (int i = 0; i < 4; i++) {
        dp[times] = i;
        dfs(dp, times + 1, arr);
    }
}

int calc(vector<int>& dp, vector<int>& arr) {
    int cost = 0;
    vector<int> memo(4);
    for (int i = 0; i < N; i++) {
        memo[dp[i]]++;
        if (dp[i] == 1) {
            cost += abs(A - arr[i]);
        } else if (dp[i] == 2) {
            cost += abs(B - arr[i]);
        } else if (dp[i] == 3) {
            cost += abs(C - arr[i]);
        }
    }

    for (int i = 1; i < 4; i++) {
        if (memo[i] < 1) {
            cost += 10000;
        } else {
            cost += (memo[i] - 1) * 10;
        }
    }

    return cost;
}


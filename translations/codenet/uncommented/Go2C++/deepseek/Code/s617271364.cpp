#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <sstream>

using namespace std;

int N, A, B, C;
vector<int> arr;
int ans = 10000;

void dfs(vector<int>& dp, int times) {
    if (times >= N) {
        ans = min(ans, calc(dp));
        return;
    }

    for (int i = 0; i < 4; i++) {
        dp[times] = i;
        dfs(dp, times + 1);
    }
}

int calc(const vector<int>& dp) {
    int cost = 0;
    vector<int> memo(4, 0);
    int AA = 0, BB = 0, CC = 0;

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

int main() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    ss >> N >> A >> B >> C;

    arr.resize(N);
    for (int i = 0; i < N; i++) {
        getline(cin, line);
        stringstream ss2(line);
        ss2 >> arr[i];
    }

    vector<int> dp(N);
    dfs(dp, 0);

    cout << ans << endl;

    return 0;
}

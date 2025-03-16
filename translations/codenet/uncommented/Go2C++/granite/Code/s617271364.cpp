
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    // A := strings.Split(nextLine(), " ")

    vector<int> X(4);
    // Z := strings.Split(nextLine(), " ")
    // n, _ := strconv.Atoi(input[0])

    int N, A, B, C;
    cin >> N >> A >> B >> C;

    // K, _ := strconv.Atoi(X[2]) //strconv.ParseInt(X[2], 10, 64)

    // Y := strings.Split(nextLine(), " ")

    vector<int> arr(N);
    vector<int> dp(N);
    int ans = 10000;
    int ss = A + B + C;
    // sort.Sort(sort.Reverse(sort.IntSlice(arr)))
    for (int i = 0; i < N; i++) {
        vector<string> Y(4);
        cin >> Y[0];
        arr[i] = stoi(Y[0]);
    }
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
    int cost = 0, AA = 0, BB = 0, CC = 0;

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


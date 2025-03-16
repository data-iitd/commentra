#include <bits/stdc++.h>
using namespace std;

int main() {
    // Create a Scanner object to read input from the user
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(ios::badbit);
    int N, T;
    cin >> N >> T;
    int AB[N][2];
    for (int i = 0; i < N; i++) {
        cin >> AB[i][0] >> AB[i][1];
    }
    sort(AB, AB + N, [](int a, int b) { return a[0] < b[0]; });
    int dp[N + 1][6001];
    for (int i = 1; i <= N; i++) {
        for (int timeAfterEat = 0; timeAfterEat <= 6000; timeAfterEat++) {
            dp[i][timeAfterEat] = max(dp[i][timeAfterEat], dp[i - 1][timeAfterEat]);
            int time = AB[i - 1][0];
            int value = AB[i - 1][1];
            if (0 <= timeAfterEat - time && timeAfterEat - time < T) {
                dp[i][timeAfterEat] = max(dp[i][timeAfterEat], dp[i - 1][timeAfterEat - time] + value);
            }
        }
    }
    cout << *max_element(dp[N], dp[N] + 6001);
    return 0;
}


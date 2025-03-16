#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, T;
    cin >> N >> T;
    int AB[N][2];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> AB[i][j];
        }
    }
    sort(AB, AB + N, [](int a, int b) {
        return a[0] < b[0];
    });
    int dp[N + 1][6001];
    for (int i = 0; i <= N; i++) {
        for (int timeAfterEat = 0; timeAfterEat <= 6000; timeAfterEat++) {
            dp[i][timeAfterEat] = 0;
        }
    }
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
    cout << dp[N][6000];
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int max(int lhs, int rhs) {
    return std::max(lhs, rhs);
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> values(N);
    vector<int> weights(N);
    for (int i = 0; i < N; i++) {
        cin >> weights[i] >> values[i];
    }
    vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= weights[i - 1]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - weights[i - 1]] + values[i - 1]);
            }
        }
    }
    cout << dp[N][M] << endl;
}

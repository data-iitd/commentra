
#include <iostream>
#include <cmath>

int max(int lhs, int rhs) {
    return static_cast<int>(std::max(static_cast<double>(lhs), static_cast<double>(rhs)));
}

int main() {
    int N, M;
    std::cin >> N >> M;
    int values[N], weights[N];
    for (int i = 0; i < N; i++) {
        std::cin >> weights[i] >> values[i];
    }
    int dp[N+1][M+1];
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            dp[i][j] = dp[i-1][j];
            if (j >= weights[i-1]) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-weights[i-1]]+values[i-1]);
            }
        }
    }
    std::cout << dp[N][M] << std::endl;
    return 0;
}

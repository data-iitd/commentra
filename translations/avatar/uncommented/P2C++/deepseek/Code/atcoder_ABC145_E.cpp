#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, T;
    std::cin >> N >> T;

    std::vector<std::tuple<int, int>> time_value(N + 1, {-1, -1});
    for (int i = 1; i <= N; ++i) {
        int time, value;
        std::cin >> time >> value;
        time_value[i] = {time, value};
    }

    std::sort(time_value.begin() + 1, time_value.end(), [](const std::tuple<int, int>& a, const std::tuple<int, int>& b) {
        return std::get<1>(a) < std::get<1>(b);
    });

    std::vector<std::vector<int>> dp(N + 1, std::vector<int>(T, -1));
    for (int t = 0; t < T; ++t) {
        dp[0][t] = 0;
    }
    for (int n = 1; n <= N; ++n) {
        dp[n][0] = 0;
        for (int t = 1; t < T; ++t) {
            if (std::get<0>(time_value[n]) > t) {
                dp[n][t] = dp[n - 1][t];
            } else {
                dp[n][t] = std::max(dp[n - 1][t], std::get<1>(time_value[n]) + dp[n - 1][t - std::get<0>(time_value[n])]);
            }
        }
    }

    int val_acum = std::get<1>(time_value[N]);
    int t = T - 1;
    int max_val = val_acum + dp[N - 1][t];
    for (int n = N - 1; n > 0; --n) {
        val_acum += std::get<1>(time_value[n]);
        t -= std::get<0>(time_value[n + 1]);
        if (t < 0) {
            break;
        } else {
            max_val = std::max(max_val, val_acum + dp[n - 1][t]);
        }
    }

    std::cout << max_val << '\n';
    return 0;
}

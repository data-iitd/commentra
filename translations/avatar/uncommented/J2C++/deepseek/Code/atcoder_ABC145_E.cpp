#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    int N, T;
    std::cin >> N >> T;
    std::vector<std::vector<int>> AB(N, std::vector<int>(2));
    for (int i = 0; i < N; ++i) {
        std::cin >> AB[i][0] >> AB[i][1];
    }

    std::sort(AB.begin(), AB.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
        return a[0] < b[0];
    });

    std::vector<std::vector<int>> dp(N + 1, std::vector<int>(6001, 0));
    for (int i = 1; i <= N; ++i) {
        for (int timeAfterEat = 0; timeAfterEat <= 6000; ++timeAfterEat) {
            dp[i][timeAfterEat] = std::max(dp[i][timeAfterEat], dp[i - 1][timeAfterEat]);
            int time = AB[i - 1][0];
            int value = AB[i - 1][1];
            if (0 <= timeAfterEat - time && timeAfterEat - time < T) {
                dp[i][timeAfterEat] = std::max(dp[i][timeAfterEat], dp[i - 1][timeAfterEat - time] + value);
            }
        }
    }

    int result = *std::max_element(dp[N].begin(), dp[N].end());
    std::cout << result << std::endl;

    return 0;
}

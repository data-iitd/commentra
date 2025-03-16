#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    int N, T;
    std::cin >> N >> T;

    // Initialize the vector to store dishes with their time and value
    std::vector<std::pair<int, int>> AB(N);
    for (int i = 0; i < N; i++) {
        std::cin >> AB[i].first >> AB[i].second;
    }

    // Sort the dishes based on their eating time
    std::sort(AB.begin(), AB.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.first < b.first;
    });

    // Initialize the DP table with dimensions (N+1) x 6001
    std::vector<std::vector<int>> dp(N + 1, std::vector<int>(6001, 0));

    // Fill the DP table
    for (int i = 1; i <= N; i++) {
        for (int timeAfterEat = 0; timeAfterEat <= 6000; timeAfterEat++) {
            // Inherit the maximum value from the previous dish
            dp[i][timeAfterEat] = std::max(dp[i][timeAfterEat], dp[i - 1][timeAfterEat]);

            // Get the time and value of the current dish
            int time = AB[i - 1].first;
            int value = AB[i - 1].second;

            // If the dish can be eaten after the given time, update the DP table
            if (0 <= timeAfterEat - time && timeAfterEat - time < T) {
                dp[i][timeAfterEat] = std::max(dp[i][timeAfterEat], dp[i - 1][timeAfterEat - time] + value);
            }
        }
    }

    // Print the maximum value that can be obtained within the time limit
    int maxValue = *std::max_element(dp[N].begin(), dp[N].end());
    std::cout << maxValue << std::endl;

    return 0;
}

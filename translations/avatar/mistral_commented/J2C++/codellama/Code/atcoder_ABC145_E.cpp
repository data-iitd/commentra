// Include necessary C++ utility libraries
#include <iostream>
#include <vector>
#include <algorithm>

// Main function to start the program
int main() {
    // Initialize a Scanner object to read input from the console
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    // Read the number of activities N and the time limit T from the console
    int N, T;
    std::cin >> N >> T;

    // Initialize a 2D vector AB to store the start time and value of each activity
    std::vector<std::vector<int>> AB(N, std::vector<int>(2));

    // Read the start time and value of each activity from the console and store it in the AB vector
    for (int i = 0; i < N; i++) {
        std::cin >> AB[i][0] >> AB[i][1];
    }

    // Sort the AB vector based on the start time of each activity
    std::sort(AB.begin(), AB.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
        return a[0] < b[0];
    });

    // Initialize a 2D vector dp to store the maximum value that can be obtained up to a certain time after eating an activity
    std::vector<std::vector<int>> dp(N + 1, std::vector<int>(6001, 0));

    // For each activity i from 1 to N, calculate the maximum value that can be obtained up to a certain time after eating the activity
    for (int i = 1; i <= N; i++) {
        for (int timeAfterEat = 0; timeAfterEat <= 6000; timeAfterEat++) {
            // Set the value of dp[i][timeAfterEat] to be the maximum of its previous value and the value obtained by eating the activity i at timeAfterEat
            dp[i][timeAfterEat] = std::max(dp[i][timeAfterEat], dp[i - 1][timeAfterEat]);

            // If the timeAfterEat is within the time limit T after the start time of activity i, update the value of dp[i][timeAfterEat] with the maximum value that can be obtained by eating activity i at timeAfterEat and adding the value of the activity to the previous value
            int time = AB[i - 1][0];
            int value = AB[i - 1][1];
            if (timeAfterEat >= time && timeAfterEat < time + T) {
                dp[i][timeAfterEat] = std::max(dp[i][timeAfterEat], dp[i - 1][timeAfterEat - time] + value);
            }
        }
    }

    // Print the maximum value that can be obtained after eating all the activities
    std::cout << *std::max_element(dp[N].begin(), dp[N].end()) << std::endl;

    return 0;
}


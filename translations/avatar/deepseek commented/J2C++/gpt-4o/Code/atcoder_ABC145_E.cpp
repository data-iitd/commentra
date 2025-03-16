#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, T;
    cin >> N >> T; // Read the number of dishes and the time limit for eating dishes

    // Initialize the vector to store dishes with their time and value
    vector<pair<int, int>> AB(N);
    for (int i = 0; i < N; i++) {
        cin >> AB[i].first >> AB[i].second; // Read the time and value for each dish
    }

    // Sort the dishes based on their eating time
    sort(AB.begin(), AB.end());

    // Initialize the DP table with dimensions (N+1) x 6001
    vector<vector<int>> dp(N + 1, vector<int>(6001, 0));

    // Fill the DP table
    for (int i = 1; i <= N; i++) {
        for (int timeAfterEat = 0; timeAfterEat <= 6000; timeAfterEat++) {
            // Inherit the maximum value from the previous dish
            dp[i][timeAfterEat] = max(dp[i][timeAfterEat], dp[i - 1][timeAfterEat]);

            // Get the time and value of the current dish
            int time = AB[i - 1].first;
            int value = AB[i - 1].second;

            // If the dish can be eaten after the given time, update the DP table
            if (0 <= timeAfterEat - time && timeAfterEat - time < T) {
                dp[i][timeAfterEat] = max(dp[i][timeAfterEat], dp[i - 1][timeAfterEat - time] + value);
            }
        }
    }

    // Print the maximum value that can be obtained within the time limit
    cout << *max_element(dp[N].begin(), dp[N].end()) << endl;

    return 0;
}

// <END-OF-CODE>

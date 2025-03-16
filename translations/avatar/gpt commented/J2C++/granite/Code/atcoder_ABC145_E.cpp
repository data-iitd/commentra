
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Create a Scanner object to read input from the user
    // Read the number of items (N) and the time limit (T)
    int N, T;
    cin >> N >> T;

    // Initialize a 2D vector to store the time and value of each item
    vector<vector<int>> AB(N, vector<int>(2));

    // Read the time and value for each item from the input
    for (int i = 0; i < N; i++) {
        cin >> AB[i][0] >> AB[i][1];
    }

    // Sort the items based on the time required in ascending order
    sort(AB.begin(), AB.end());

    // Initialize a DP table where dp[i][j] represents the maximum value
    // that can be obtained using the first i items within j time
    vector<vector<int>> dp(N + 1, vector<int>(6001, 0));

    // Fill the DP table
    for (int i = 1; i <= N; i++) {
        for (int timeAfterEat = 0; timeAfterEat <= 6000; timeAfterEat++) {
            // Carry forward the maximum value from the previous item
            dp[i][timeAfterEat] = max(dp[i][timeAfterEat], dp[i - 1][timeAfterEat]);

            // Get the time and value of the current item
            int time = AB[i - 1][0];
            int value = AB[i - 1][1];

            // Check if the current item can be taken within the remaining time
            if (0 <= timeAfterEat - time && timeAfterEat - time < T) {
                // Update the DP table with the maximum value obtained by taking the current item
                dp[i][timeAfterEat] = max(dp[i][timeAfterEat], dp[i - 1][timeAfterEat - time] + value);
            }
        }
    }

    // Output the maximum value that can be obtained using all items
    cout << *max_element(dp[N].begin(), dp[N].end()) << endl;

    return 0;
}

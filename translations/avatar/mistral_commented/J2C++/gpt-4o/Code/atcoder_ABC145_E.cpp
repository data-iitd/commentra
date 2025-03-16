// Include necessary C++ headers
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

// Main function to start the program
int main() {
    // Initialize variables for the number of activities N and the time limit T
    int N, T;
    cin >> N >> T;

    // Initialize a vector of pairs to store the start time and value of each activity
    vector<pair<int, int>> AB(N);

    // Read the start time and value of each activity from the console and store it in the AB vector
    for (int i = 0; i < N; i++) {
        cin >> AB[i].first;  // Read the start time of activity i
        cin >> AB[i].second; // Read the value of activity i
    }

    // Sort the AB vector based on the start time of each activity
    sort(AB.begin(), AB.end());

    // Initialize a 2D vector dp to store the maximum value that can be obtained up to a certain time after eating an activity
    vector<vector<int>> dp(N + 1, vector<int>(6001, 0));

    // For each activity i from 1 to N, calculate the maximum value that can be obtained up to a certain time after eating the activity
    for (int i = 1; i <= N; i++) {
        for (int timeAfterEat = 0; timeAfterEat <= 6000; timeAfterEat++) {
            // Set the value of dp[i][timeAfterEat] to be the maximum of its previous value and the value obtained by eating the activity i at timeAfterEat
            dp[i][timeAfterEat] = dp[i - 1][timeAfterEat];

            // If the timeAfterEat is within the time limit T after the start time of activity i, update the value of dp[i][timeAfterEat]
            int time = AB[i - 1].first;
            int value = AB[i - 1].second;
            if (timeAfterEat >= time && timeAfterEat < time + T) {
                dp[i][timeAfterEat] = max(dp[i][timeAfterEat], dp[i - 1][timeAfterEat - time] + value);
            }
        }
    }

    // Print the maximum value that can be obtained after eating all the activities
    cout << *max_element(dp[N].begin(), dp[N].end()) << endl;

    return 0;
}

// <END-OF-CODE>

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Create a variable to keep track of the maximum number of beacons
    int max = 0;

    // Read the number of beacons
    int n;
    cin >> n;

    // Create a vector to store the positions of the beacons
    vector<int> beacon(1000001, 0);

    // Create a dynamic programming vector to store the maximum beacons that can be placed
    vector<int> dp(1000001, 0);

    // Read the beacon positions and their corresponding values
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a; // Read the position of the beacon
        cin >> beacon[a]; // Read the value associated with the beacon at that position
    }

    // Initialize the dp vector for the first position if there is a beacon
    if (beacon[0] != 0)
        dp[0] = 1;

    // Iterate through all possible positions to calculate the maximum beacons that can be placed
    for (int i = 1; i < 1000001; i++) {
        // If there is a beacon at position i and its value is less than i
        if (beacon[i] != 0 && beacon[i] < i) {
            // Update the dp vector based on the previous values
            dp[i] = dp[i - beacon[i] - 1] + 1;
        }
        // If there is a beacon at position i but its value is greater than or equal to i
        else if (beacon[i] != 0) {
            dp[i] = 1; // Only this beacon can be placed
        }
        // If there is no beacon at position i
        else {
            dp[i] = dp[i - 1]; // Carry forward the previous maximum
        }
        // Update the maximum number of beacons found so far
        max = std::max(max, dp[i]);
    }

    // Output the minimum number of beacons that need to be removed
    cout << n - max;

    return 0;
}

// <END-OF-CODE>

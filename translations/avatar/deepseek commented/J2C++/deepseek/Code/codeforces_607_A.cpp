#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int max = 0;
    int n;
    cin >> n;
    vector<int> beacon(1000001, 0);
    vector<int> dp(1000001, 0);

    // Read the positions and strengths of the beacons
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        beacon[a] = b;
    }

    // Check if the first beacon's strength is not zero and initialize dp[0] to 1
    if (beacon[0] != 0) dp[0] = 1;

    // Iterate through the range of 1 to 1000000, updating the dp array based on the beacon strengths
    for (int i = 1; i < 1000001; i++) {
        if (beacon[i] != 0 && beacon[i] < i) {
            dp[i] = dp[i - beacon[i] - 1] + 1;
        } else if (beacon[i] != 0) {
            dp[i] = 1;
        } else {
            dp[i] = dp[i - 1];
        }
        max = std::max(max, dp[i]);
    }

    // Print the result
    cout << n - max << endl;

    return 0;
}

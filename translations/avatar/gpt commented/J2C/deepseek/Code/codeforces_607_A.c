#include <stdio.h>
#include <stdlib.h>

#define MAXN 1000001

int main() {
    int n, max = 0;
    int beacon[MAXN] = {0};
    int dp[MAXN] = {0};

    // Read the number of beacons
    scanf("%d", &n);

    // Read the beacon positions and their corresponding values
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        beacon[a] = b;
    }

    // Initialize the dp array for the first position if there is a beacon
    if (beacon[0] != 0)
        dp[0] = 1;

    // Iterate through all possible positions to calculate the maximum beacons that can be placed
    for (int i = 1; i < MAXN; i++) {
        // If there is a beacon at position i and its value is less than i
        if (beacon[i] != 0 && beacon[i] < i) {
            // Update the dp array based on the previous values
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
        if (dp[i] > max)
            max = dp[i];
    }

    // Output the minimum number of beacons that need to be removed
    printf("%d\n", n - max);

    return 0;
}

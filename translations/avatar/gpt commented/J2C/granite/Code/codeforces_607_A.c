
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Create a Scanner object to read input from the console
    int n;
    scanf("%d", &n);

    // Create an array to store the positions of the beacons
    int beacon[1000001];
    for (int i = 0; i < 1000001; i++) {
        beacon[i] = 0;
    }

    // Read the beacon positions and their corresponding values
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        beacon[a] = b;
    }

    // Create a dynamic programming array to store the maximum beacons that can be placed
    int dp[1000001];
    for (int i = 0; i < 1000001; i++) {
        dp[i] = 0;
    }

    // Initialize the dp array for the first position if there is a beacon
    if (beacon[0]!= 0) {
        dp[0] = 1;
    }

    // Iterate through all possible positions to calculate the maximum beacons that can be placed
    for (int i = 1; i < 1000001; i++) {
        // If there is a beacon at position i and its value is less than i
        if (beacon[i]!= 0 && beacon[i] < i) {
            // Update the dp array based on the previous values
            dp[i] = dp[i - beacon[i] - 1] + 1;
        }
        // If there is a beacon at position i but its value is greater than or equal to i
        else if (beacon[i]!= 0) {
            dp[i] = 1; // Only this beacon can be placed
        }
        // If there is no beacon at position i
        else {
            dp[i] = dp[i - 1]; // Carry forward the previous maximum
        }
    }

    // Output the minimum number of beacons that need to be removed
    int max = 0;
    for (int i = 0; i < 1000001; i++) {
        max = (dp[i] > max)? dp[i] : max;
    }
    printf("%d\n", n - max);

    return 0;
}

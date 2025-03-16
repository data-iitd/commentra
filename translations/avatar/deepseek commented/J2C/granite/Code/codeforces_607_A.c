

#include <stdio.h>
#include <stdlib.h>

int main() {
    int max = 0;
    int n;
    scanf("%d", &n);
    int beacon[1000001] = {0};
    int dp[1000001] = {0};

    // Step 6: Read the positions and strengths of the beacons
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        scanf("%d", &beacon[a]);
    }

    // Step 7: Check if the first beacon's strength is not zero and initialize dp[0] to 1
    if (beacon[0]!= 0) dp[0] = 1;

    // Step 8: Iterate through the range of 1 to 1000000, updating the dp array based on the beacon strengths
    for (int i = 1; i < 1000001; i++) {
        if (beacon[i]!= 0 && beacon[i] < i) {
            dp[i] = dp[i - beacon[i] - 1] + 1;
        } else if (beacon[i]!= 0) {
            dp[i] = 1;
        } else {
            dp[i] = dp[i - 1];
        }
        max = (max > dp[i])? max : dp[i]; // Step 9: Update the maximum value in dp array
    }

    // Step 9: Print the result
    printf("%d\n", n - max);
    return 0;
}

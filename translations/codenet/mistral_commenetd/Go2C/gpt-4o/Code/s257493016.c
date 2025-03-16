#include <stdio.h>
#include <limits.h>

// Function to find minimum number in an array
int min(int count, int arr[]) {
    if (count == 0) {
        // Panic if the array is empty
        fprintf(stderr, "len == 0\n");
        return -1; // Return an error value
    }
    int r = arr[0];
    // Initialize minimum value with first element of the array
    for (int i = 1; i < count; i++) {
        // Compare current element with minimum value and update minimum value if current element is smaller
        if (arr[i] < r) {
            r = arr[i];
        }
    }
    // Return the minimum value
    return r;
}

int main() {
    // Initialize variables for number of floors H, number of jumps N, and variables A and B for each jump
    int H, N, A, B;
    scanf("%d %d", &H, &N);

    // Initialize an array dp of size H+10001 with initial value INT_MAX
    int dp[H + 10001];
    for (int l = 1; l < H + 10001; l++) {
        dp[l] = INT_MAX;
    }

    // Initialize maximum reachable floor amax to 0
    int amax = 0;
    // Iterate through each jump
    for (int i = 0; i < N; i++) {
        // Read floor A and number of floors B that can be jumped from floor A
        scanf("%d %d", &A, &B);

        // If the maximum reachable floor is less than A, update maximum reachable floor
        if (A >= amax) {
            amax = A;
        }

        // Update dp[A] with minimum of current dp[A] and B
        if (dp[A] > B) {
            dp[A] = B;
        }

        // Iterate through floors from A+1 to H+A and update dp[j] with minimum of current dp[j] and dp[j-A]+B
        for (int j = A + 1; j <= H + A + 1; j++) {
            if (dp[j] > dp[j - A] + B) {
                dp[j] = dp[j - A] + B;
            }
        }
    }

    // Prepare an array to find the minimum value in the range dp[H] to dp[H + amax]
    int min_values[amax + 1];
    for (int i = 0; i <= amax; i++) {
        min_values[i] = dp[H + i];
    }

    // Print the minimum number of jumps required to reach the last floor
    printf("%d\n", min(amax + 1, min_values));

    return 0;
}

// <END-OF-CODE>

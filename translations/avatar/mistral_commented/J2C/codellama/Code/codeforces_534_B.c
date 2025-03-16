#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    int v1, v2, t, d; // Declaring variables v1, v2, t, d
    scanf("%d %d %d %d", &v1, &v2, &t, &d); // Reading input variables from the user

    long **dp = (long **)malloc(sizeof(long *) * (t - 1)); // Creating a 2D array dp of size (t-1) x 1150 for dynamic programming table
    for (int i = 0; i < t - 1; i++) {
        dp[i] = (long *)malloc(sizeof(long) * 1150); // Initializing each row of the dp table with 1150 long values
        memset(dp[i], LONG_MIN, sizeof(long) * 1150); // Initializing all elements of the current row with minimum long value
        dp[i][v1] = v1; // Setting the value of the cell (i, v1) to v1
    }

    long sum = 0; // Initializing a variable sum to 0

    // Filling the dp table using dynamic programming
    for (int i = 1; i < t - 1; i++) {
        for (int j = 0; j < 1150; j++) {
            for (int x = 0; x <= d; x++) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j + x] + j); // Filling the current cell with the maximum value of itself and the sum of the previous cell and the current element plus the jump
            }
            for (int x = d; x >= 0; x--) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - x] + j); // Filling the current cell with the maximum value of itself and the sum of the previous cell and the current element minus the jump
            }
        }
        sum += dp[i][1149]; // Adding the value of the last cell of the current row to the sum
    }

    long ans = LONG_MIN; // Initializing a variable ans with minimum long value

    // Finding the maximum value that can be obtained by jumping from any cell in the last but one row to the last row and adding the value of the last cell of the last row
    for (int i = t - 2; i < t - 1; i++) {
        for (int j = 0; j < 1150; j++) {
            if (abs(j - v2) <= d) { // Checking if the absolute difference between j and v2 is less than or equal to d
                ans = max(ans, dp[i][j] + v2); // Updating the value of ans with the maximum of itself and the sum of the current cell and v2
            }
        }
    }

    printf("%ld\n", ans); // Printing the final answer

    for (int i = 0; i < t - 1; i++) {
        free(dp[i]); // Freeing the memory allocated for each row of the dp table
    }
    free(dp); // Freeing the memory allocated for the dp table

    return 0;
}


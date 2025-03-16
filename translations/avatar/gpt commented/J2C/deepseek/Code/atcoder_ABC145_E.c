#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int N, T;
    scanf("%d %d", &N, &T);

    int AB[N][2];
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &AB[i][0], &AB[i][1]);
    }

    // Sort the items based on the time required in ascending order
    qsort(AB, N, sizeof(int[2]), (int (*)(const void *, const void *))compare);

    // Initialize a DP table where dp[i][j] represents the maximum value
    // that can be obtained using the first i items within j time
    int dp[N + 1][6001];
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= 6000; j++) {
            dp[i][j] = 0;
        }
    }

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
    int maxValue = 0;
    for (int j = 0; j <= 6000; j++) {
        if (dp[N][j] > maxValue) {
            maxValue = dp[N][j];
        }
    }
    printf("%d\n", maxValue);

    return 0;
}

int compare(const void *a, const void *b) {
    int *itemA = (int *)a;
    int *itemB = (int *)b;
    return itemA[0] - itemB[0];
}

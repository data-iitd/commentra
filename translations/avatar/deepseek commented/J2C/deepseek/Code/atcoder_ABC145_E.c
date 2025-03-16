#include <stdio.h>
#include <stdlib.h>

// Define a structure to hold the dishes
typedef struct {
    int time;
    int value;
} Dish;

// Compare function for sorting dishes by time
int compare(const void *a, const void *b) {
    Dish *dishA = (Dish *)a;
    Dish *dishB = (Dish *)b;
    return dishA->time - dishB->time;
}

int main() {
    int N, T;
    scanf("%d %d", &N, &T);

    // Allocate memory for dishes
    Dish dishes[N];
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &dishes[i].time, &dishes[i].value);
    }

    // Sort dishes by their eating time
    qsort(dishes, N, sizeof(Dish), compare);

    // Initialize the DP table with dimensions (N+1) x 6001
    int dp[N + 1][6001];

    // Fill the DP table
    for (int i = 1; i <= N; i++) {
        for (int timeAfterEat = 0; timeAfterEat <= 6000; timeAfterEat++) {
            // Inherit the maximum value from the previous dish
            dp[i][timeAfterEat] = dp[i - 1][timeAfterEat];

            // Get the time and value of the current dish
            int time = dishes[i - 1].time;
            int value = dishes[i - 1].value;

            // If the dish can be eaten after the given time, update the DP table
            if (0 <= timeAfterEat - time && timeAfterEat - time < T) {
                dp[i][timeAfterEat] = (dp[i][timeAfterEat] > dp[i - 1][timeAfterEat - time] + value) ? dp[i][timeAfterEat] : dp[i - 1][timeAfterEat - time] + value;
            }
        }
    }

    // Find the maximum value in the last row of the DP table
    int maxValue = 0;
    for (int timeAfterEat = 0; timeAfterEat <= 6000; timeAfterEat++) {
        if (dp[N][timeAfterEat] > maxValue) {
            maxValue = dp[N][timeAfterEat];
        }
    }

    // Print the maximum value that can be obtained within the time limit
    printf("%d\n", maxValue);

    return 0;
}

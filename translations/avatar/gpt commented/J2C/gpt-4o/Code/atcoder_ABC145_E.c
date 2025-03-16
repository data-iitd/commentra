#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int time;
    int value;
} Item;

int compare(const void *a, const void *b) {
    return ((Item *)a)->time - ((Item *)b)->time;
}

int main() {
    // Read the number of items (N) and the time limit (T)
    int N, T;
    scanf("%d %d", &N, &T);
    
    // Initialize an array to store the time and value of each item
    Item *AB = (Item *)malloc(N * sizeof(Item));
    
    // Read the time and value for each item from the input
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &AB[i].time, &AB[i].value);
    }
    
    // Sort the items based on the time required in ascending order
    qsort(AB, N, sizeof(Item), compare);
    
    // Initialize a DP table where dp[i][j] represents the maximum value 
    // that can be obtained using the first i items within j time
    int dp[N + 1][6001] = {0};
    
    // Fill the DP table
    for (int i = 1; i <= N; i++) {
        for (int timeAfterEat = 0; timeAfterEat <= 6000; timeAfterEat++) {
            // Carry forward the maximum value from the previous item
            dp[i][timeAfterEat] = dp[i - 1][timeAfterEat];
            
            // Get the time and value of the current item
            int time = AB[i - 1].time;
            int value = AB[i - 1].value;
            
            // Check if the current item can be taken within the remaining time
            if (0 <= timeAfterEat - time && timeAfterEat - time < T) {
                // Update the DP table with the maximum value obtained by taking the current item
                dp[i][timeAfterEat] = (dp[i][timeAfterEat] > dp[i - 1][timeAfterEat - time] + value) ? 
                                      dp[i][timeAfterEat] : 
                                      (dp[i - 1][timeAfterEat - time] + value);
            }
        }
    }
    
    // Output the maximum value that can be obtained using all items
    int max_value = 0;
    for (int j = 0; j <= 6000; j++) {
        if (dp[N][j] > max_value) {
            max_value = dp[N][j];
        }
    }
    printf("%d\n", max_value);
    
    // Free allocated memory
    free(AB);
    
    return 0;
}

// <END-OF-CODE>

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include <stdbool.h> 

int main() { 
    // Create a Scanner object to read input from the user
    int N, T; 
    scanf("%d %d", &N, &T); 
    
    // Initialize a 2D array to store the time and value of each item
    int AB[N][2]; 
    
    // Read the time and value for each item from the input
    for (int i = 0; i < N; i++) { 
        scanf("%d %d", &AB[i][0], &AB[i][1]); 
    } 
    
    // Sort the items based on the time required in ascending order
    qsort(AB, N, sizeof(AB[0]), compare); 
    
    // Initialize a DP table where dp[i][j] represents the maximum value 
    // that can be obtained using the first i items within j time
    int dp[N + 1][6001]; 
    
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
    printf("%d\n", max(dp[N])); 
    
    return 0; 
} 

int compare(const void *a, const void *b) { 
    return (*(int*)a)[0] - (*(int*)b)[0]; 
} 

int max(int arr[]) { 
    int max = arr[0]; 
    for (int i = 1; i < 6001; i++) { 
        if (arr[i] > max) { 
            max = arr[i]; 
        } 
    } 
    return max; 
} 


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    // Create a Scanner object to read input from the console
    int N;
    long x;
    scanf("%d %ld", &N, &x);
    
    // Read N long values into the srimeList
    long *srimeList = (long *)malloc(N * sizeof(long));
    for (int i = 0; i < N; i++) {
        scanf("%ld", &srimeList[i]);
    }
    
    // Initialize a 2D list to store costs
    long **costList = (long **)malloc(N * sizeof(long *));
    for (int i = 0; i < N; i++) {
        costList[i] = (long *)malloc(N * sizeof(long));
    }
    
    // Populate the costList with minimum values based on the srimeList
    for (int i = 0; i < N; i++) {
        // Set the first column of costList to the corresponding values from srimeList
        costList[i][0] = srimeList[i];
        // Calculate the minimum costs for each subsequent column
        for (int castNum = 1; castNum < N; castNum++) {
            costList[i][castNum] = fmin(costList[i][castNum - 1], srimeList[(i - castNum + N) % N]);
        }
    }
    
    // Initialize a list to store the final results
    long *result = (long *)malloc(N * sizeof(long));
    
    // Calculate the result for each index based on the costs and the value of x
    for (int i = 0; i < N; i++) {
        result[i] = i * x + costList[i][i];
    }
    
    // Print the minimum value from the result list
    printf("%ld\n", *min_element(result, result + N));
    
    // Free memory
    free(srimeList);
    for (int i = 0; i < N; i++) {
        free(costList[i]);
    }
    free(costList);
    free(result);
    
    return 0;
}


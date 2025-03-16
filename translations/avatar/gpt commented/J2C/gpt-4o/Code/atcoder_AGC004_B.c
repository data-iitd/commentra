#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    // Read the number of elements (N) and a long value (x) from input
    int N;
    long x;
    scanf("%d %ld", &N, &x);
    
    // Initialize an array to store the prime numbers
    long *srimeList = (long *)malloc(N * sizeof(long));
    
    // Read N long values into the srimeList
    for (int i = 0; i < N; i++) {
        scanf("%ld", &srimeList[i]);
    }
    
    // Initialize a 2D array for costs
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
            costList[i][castNum] = (costList[i][castNum - 1] < srimeList[(i - castNum + N) % N]) ? 
                                    costList[i][castNum - 1] : 
                                    srimeList[(i - castNum + N) % N];
        }
    }
    
    // Initialize a variable to store the minimum result
    long minResult = LONG_MAX;
    
    // Calculate the result for each index based on the costs and the value of x
    for (int i = 0; i < N; i++) {
        long sumCosts = 0;
        for (int j = 0; j < N; j++) {
            sumCosts += costList[j][i];
        }
        long result = i * x + sumCosts;
        if (result < minResult) {
            minResult = result;
        }
    }
    
    // Print the minimum value from the result
    printf("%ld\n", minResult);
    
    // Free allocated memory
    for (int i = 0; i < N; i++) {
        free(costList[i]);
    }
    free(costList);
    free(srimeList);
    
    return 0;
}

// <END-OF-CODE>

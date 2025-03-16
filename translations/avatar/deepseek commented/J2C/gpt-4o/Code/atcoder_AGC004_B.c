#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int N;
    long x;
    
    // Read the number of elements N and the cost multiplier x
    scanf("%d", &N);
    scanf("%ld", &x);

    long *srimeList = (long *)malloc(N * sizeof(long)); // Allocate memory for srimeList
    for (int i = 0; i < N; i++) {
        scanf("%ld", &srimeList[i]); // Read N long integers and add to srimeList
    }

    long **costList = (long **)malloc(N * sizeof(long *)); // Allocate memory for costList
    for (int i = 0; i < N; i++) {
        costList[i] = (long *)malloc(N * sizeof(long)); // Initialize each array in costList with size N
    }

    // Fill costList with the minimum costs for each element in srimeList
    for (int i = 0; i < N; i++) {
        costList[i][0] = srimeList[i]; // Initialize the first element of the cost array
        for (int castNum = 1; castNum < N; castNum++) {
            costList[i][castNum] = (costList[i][castNum - 1] < srimeList[(i - castNum + N) % N]) ? 
                                    costList[i][castNum - 1] : 
                                    srimeList[(i - castNum + N) % N];
        }
    }

    long minCost = LONG_MAX; // Initialize minCost to the maximum possible value
    for (int i = 0; i < N; i++) {
        long currentCost = i * x; // Calculate the current cost
        for (int j = 0; j < N; j++) {
            currentCost += costList[j][i]; // Sum the costs
        }
        if (currentCost < minCost) {
            minCost = currentCost; // Update minCost if currentCost is lower
        }
    }

    // Print the minimum cost found
    printf("%ld\n", minCost);

    // Free allocated memory
    free(srimeList);
    for (int i = 0; i < N; i++) {
        free(costList[i]);
    }
    free(costList);

    return 0;
}

// <END-OF-CODE>

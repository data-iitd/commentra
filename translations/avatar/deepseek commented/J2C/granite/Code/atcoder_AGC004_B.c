
#include <stdio.h> // Include the standard input/output library
#include <stdlib.h> // Include the standard library for dynamic memory allocation

int main() {
    int N; // Declare and initialize the number of elements N
    long x; // Declare and initialize the cost multiplier x
    scanf("%d %ld", &N, &x); // Read N and x from the user using scanf

    long *srimeList = (long *)malloc(N * sizeof(long)); // Allocate memory for srimeList
    for (int i = 0; i < N; i++) {
        scanf("%ld", &srimeList[i]); // Read N long integers and store in srimeList
    }

    long **costList = (long **)malloc(N * sizeof(long *)); // Allocate memory for costList
    for (int i = 0; i < N; i++) {
        costList[i] = (long *)malloc(N * sizeof(long)); // Allocate memory for each inner array in costList
    }

    // Fill costList with the minimum costs for each element in srimeList
    for (int i = 0; i < N; i++) {
        costList[i][0] = srimeList[i]; // Initialize the first element of the cost array
        for (int castNum = 1; castNum < N; castNum++) {
            costList[i][castNum] = costList[i][castNum - 1] < srimeList[(i - castNum + N) % N]? costList[i][castNum - 1] : srimeList[(i - castNum + N) % N];
        }
    }

    long *result = (long *)malloc(N * sizeof(long)); // Allocate memory for the result array
    for (int i = 0; i < N; i++) {
        long minCost = 0; // Initialize the minimum cost
        for (int j = 0; j < N; j++) {
            minCost += costList[j][i]; // Sum the costs for each element in srimeList
        }
        result[i] = minCost + i * x; // Calculate the minimum cost for each element in srimeList and store in result
    }

    // Find the minimum cost found and print it
    long minResult = result[0];
    for (int i = 1; i < N; i++) {
        if (result[i] < minResult) {
            minResult = result[i];
        }
    }
    printf("%ld\n", minResult); // Print the minimum cost found

    // Free the allocated memory
    for (int i = 0; i < N; i++) {
        free(costList[i]); // Free the memory for each inner array in costList
    }
    free(costList); // Free the memory for costList
    free(srimeList); // Free the memory for srimeList
    free(result); // Free the memory for the result array

    return 0; // Return 0 to indicate successful execution
}



#include <stdio.h> // Including the standard input/output library
#include <stdlib.h> // Including the standard library for memory allocation and deallocation

int main() {
    int N; // Variable to store the number of elements in the array
    long x; // Variable to store the multiplier

    // Reading input from the console
    scanf("%d %ld", &N, &x);

    long *srimeList = (long *)malloc(N * sizeof(long)); // Allocating memory for the array of size N
    if (srimeList == NULL) { // Checking if memory allocation was successful
        printf("Memory allocation failed");
        return 1;
    }

    // Reading elements of the array and storing them in the allocated memory
    for (int i = 0; i < N; i++) {
        scanf("%ld", &srimeList[i]);
    }

    long **costList = (long **)malloc(N * sizeof(long *)); // Allocating memory for the array of pointers to cost arrays
    if (costList == NULL) { // Checking if memory allocation was successful
        printf("Memory allocation failed");
        free(srimeList); // Deallocating the memory allocated for the array of elements
        return 1;
    }

    for (int i = 0; i < N; i++) {
        costList[i] = (long *)malloc(N * sizeof(long)); // Allocating memory for the cost array of size N
        if (costList[i] == NULL) { // Checking if memory allocation was successful
            printf("Memory allocation failed");
            for (int j = 0; j < i; j++) { // Deallocating the memory allocated for the cost arrays
                free(costList[j]);
            }
            free(srimeList); // Deallocating the memory allocated for the array of elements
            return 1;
        }
    }

    // Filling the cost arrays with the minimum cost for each index and each cast number
    for (int i = 0; i < N; i++) {
        costList[i][0] = srimeList[i]; // Setting the first element of the cost array to the original element
        for (int castNum = 1; castNum < N; castNum++) {
            costList[i][castNum] = (costList[i][castNum - 1] < srimeList[(i - castNum + N) % N])? costList[i][castNum - 1] : srimeList[(i - castNum + N) % N];
        }
    }

    long *result = (long *)malloc(N * sizeof(long)); // Allocating memory for the array to store the final result
    if (result == NULL) { // Checking if memory allocation was successful
        printf("Memory allocation failed");
        for (int i = 0; i < N; i++) { // Deallocating the memory allocated for the cost arrays
            free(costList[i]);
        }
        free(costList); // Deallocating the memory allocated for the array of pointers to cost arrays
        free(srimeList); // Deallocating the memory allocated for the array of elements
        return 1;
    }

    // Calculating the result for each index and storing it in the allocated memory
    for (int i = 0; i < N; i++) {
        long temp = i * x; // Multiplying the index with the multiplier
        for (int j = 0; j < N; j++) { // Iterating through the cost array and adding the costs
            temp += costList[i][j];
        }
        result[i] = temp;
    }

    // Printing the minimum result
    long min = result[0];
    for (int i = 1; i < N; i++) {
        if (result[i] < min) {
            min = result[i];
        }
    }
    printf("%ld", min);

    // Deallocating the memory allocated for the result array
    free(result);

    // Deallocating the memory allocated for the cost arrays
    for (int i = 0; i < N; i++) {
        free(costList[i]);
    }

    // Deallocating the memory allocated for the array of pointers to cost arrays
    free(costList);

    // Deallocating the memory allocated for the array of elements
    free(srimeList);

    return 0;
}


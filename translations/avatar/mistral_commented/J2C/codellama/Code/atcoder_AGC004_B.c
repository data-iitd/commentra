#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    int N; // Variable to store the number of elements in the array
    long x; // Variable to store the multiplier

    // Reading input from the console
    scanf("%d", &N);
    scanf("%ld", &x);

    long *srimeList = (long *)malloc(N * sizeof(long)); // Creating an array of size N to store the elements

    // Reading elements of the array and adding them to the array
    for (int i = 0; i < N; i++) {
        scanf("%ld", &srimeList[i]);
    }

    long **costList = (long **)malloc(N * sizeof(long *)); // Creating an array of size N to store the cost arrays

    // Creating cost arrays of size N x N for each element in the original array
    for (int i = 0; i < N; i++) {
        costList[i] = (long *)malloc(N * sizeof(long));
    }

    // Filling the cost arrays with the minimum cost for each index and each cast number
    for (int i = 0; i < N; i++) {
        costList[i][0] = srimeList[i]; // Setting the first element of the cost array to the original element
        for (int castNum = 1; castNum < N; castNum++) {
            costList[i][castNum] = fmin(costList[i][castNum - 1], srimeList[(i - castNum + N) % N]);
        }
    }

    long *result = (long *)malloc(N * sizeof(long)); // Creating an array to store the final result

    // Calculating the result for each index and adding it to the array
    for (int i = 0; i < N; i++) {
        long temp = i * x; // Multiplying the index with the multiplier
        for (int j = 0; j < N; j++) { // Iterating through the cost array and adding the costs
            temp += costList[i][j];
        }
        result[i] = temp;
    }

    // Printing the minimum result
    printf("%ld\n", *min_element(result, result + N));

    // Freeing memory
    free(srimeList);
    for (int i = 0; i < N; i++) {
        free(costList[i]);
    }
    free(costList);
    free(result);

    return 0;
}


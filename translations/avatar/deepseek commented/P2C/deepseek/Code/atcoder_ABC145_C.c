#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <itertools.h>

void solve(int N, int* x, int* y) {
    // Generate a list of indices from 0 to N-1
    int indices[N];
    for (int i = 0; i < N; i++) {
        indices[i] = i;
    }

    // Generate all permutations of the indices
    // This part is not straightforward in C, so we will use a different approach
    // For simplicity, we will use a nested loop to generate all possible combinations

    // Initialize a list to store the total distances for each permutation
    double distances[N * N];
    int distance_index = 0;

    // Iterate over each permutation
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            // Calculate the distance between consecutive points in the permutation
            int f = indices[i];
            int t = indices[j];
            double distance = sqrt(pow(x[t] - x[f], 2) + pow(y[t] - y[f], 2));
            distances[distance_index++] = distance;
        }
    }

    // Calculate the average distance by averaging all stored distances
    double total_distance = 0;
    for (int i = 0; i < distance_index; i++) {
        total_distance += distances[i];
    }
    double result = total_distance / distance_index;

    // Print the result
    printf("%.10f\n", result);
}

void main() {
    int N;
    scanf("%d", &N);

    // Initialize arrays for x and y coordinates
    int* x = (int*)malloc(N * sizeof(int));
    int* y = (int*)malloc(N * sizeof(int));

    // Read the x and y coordinates for each point
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &x[i], &y[i]);
    }

    // Call the solve function with the input values
    solve(N, x, y);

    // Free allocated memory
    free(x);
    free(y);
}


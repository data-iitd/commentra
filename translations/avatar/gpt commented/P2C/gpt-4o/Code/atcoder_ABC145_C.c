#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void solve(int N, int *x, int *y) {
    // Create an array of indices from 0 to N-1
    int *indices = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        indices[i] = i;
    }

    // Initialize a variable to store the total distance
    double total_distance_sum = 0.0;
    long long permutation_count = 0;

    // Generate all possible permutations of the indices
    // Using a recursive function to generate permutations
    void permute(int *arr, int start, int end) {
        if (start == end) {
            double total_distance = 0.0;
            for (int i = 0; i < N - 1; i++) {
                int f = arr[i];
                int t = arr[i + 1];
                // Calculate the Euclidean distance between the two points
                double distance = sqrt(pow(x[t] - x[f], 2) + pow(y[t] - y[f], 2));
                total_distance += distance;  // Accumulate the total distance
            }
            total_distance_sum += total_distance;
            permutation_count++;
            return;
        }
        for (int i = start; i <= end; i++) {
            // Swap
            int temp = arr[start];
            arr[start] = arr[i];
            arr[i] = temp;

            // Recur
            permute(arr, start + 1, end);

            // Backtrack
            temp = arr[start];
            arr[start] = arr[i];
            arr[i] = temp;
        }
    }

    // Call the permutation function
    permute(indices, 0, N - 1);

    // Calculate the average distance across all permutations
    double result = total_distance_sum / permutation_count;

    // Print the average distance
    printf("%lf\n", result);

    // Free allocated memory
    free(indices);
}

int main() {
    // Read the number of points
    int N;
    scanf("%d", &N);

    // Initialize arrays to store x and y coordinates
    int *x = (int *)malloc(N * sizeof(int));
    int *y = (int *)malloc(N * sizeof(int));

    // Read the x and y coordinates for each point
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &x[i], &y[i]);
    }

    // Call the solve function with the number of points and their coordinates
    solve(N, x, y);

    // Free allocated memory
    free(x);
    free(y);

    return 0;
}

// <END-OF-CODE>

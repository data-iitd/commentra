#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void solve(int N, int *x, int *y) {
    // Initialize an empty array to store distances
    double *distances = (double *)malloc(sizeof(double) * 40320); // 8! = 40320 for N=8, adjust as needed
    int count = 0;

    // Generate all possible permutations of indices from 0 to N-1
    int *indices = (int *)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        indices[i] = i;
    }

    // Function to calculate the total distance for a given permutation
    double calculate_distance(int *permutation) {
        double total_distance = 0.0;
        for (int i = 0; i < N - 1; i++) {
            int f = permutation[i];
            int t = permutation[i + 1];
            // Calculate the Euclidean distance
            double distance = sqrt(pow(x[t] - x[f], 2) + pow(y[t] - y[f], 2));
            total_distance += distance;
        }
        return total_distance;
    }

    // Recursive function to generate permutations
    void permute(int *arr, int l, int r) {
        if (l == r) {
            distances[count++] = calculate_distance(arr);
        } else {
            for (int i = l; i <= r; i++) {
                // Swap
                int temp = arr[l];
                arr[l] = arr[i];
                arr[i] = temp;

                // Recur
                permute(arr, l + 1, r);

                // Backtrack
                temp = arr[l];
                arr[l] = arr[i];
                arr[i] = temp;
            }
        }
    }

    // Generate permutations
    permute(indices, 0, N - 1);

    // Calculate the average distance from all permutations
    double result = 0.0;
    for (int i = 0; i < count; i++) {
        result += distances[i];
    }
    result /= count;

    // Print the result
    printf("%lf\n", result);

    // Free allocated memory
    free(distances);
    free(indices);
}

int main() {
    // Read the number of points and their coordinates from input
    int N;
    scanf("%d", &N);
    int *x = (int *)malloc(sizeof(int) * N);
    int *y = (int *)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &x[i], &y[i]);
    }

    // Call the solve function with the given input
    solve(N, x, y);

    // Free allocated memory
    free(x);
    free(y);

    return 0;
}

// <END-OF-CODE>

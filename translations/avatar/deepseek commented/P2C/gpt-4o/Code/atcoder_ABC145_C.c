#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void solve(int N, int *x, int *y) {
    // Generate a list of indices from 0 to N-1
    int *indices = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        indices[i] = i;
    }

    // Initialize a variable to store the total distance
    double total_distance = 0.0;
    int count = 0;

    // Generate all permutations of the indices
    int *permutation = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        permutation[i] = indices[i];
    }

    // Function to calculate the distance between two points
    double distance(int f, int t) {
        return sqrt(pow(x[t] - x[f], 2) + pow(y[t] - y[f], 2));
    }

    // Generate permutations using a recursive function
    void permute(int *arr, int l, int r) {
        if (l == r) {
            // Calculate the total distance for the current permutation
            double current_distance = 0.0;
            for (int i = 0; i < N - 1; i++) {
                current_distance += distance(arr[i], arr[i + 1]);
            }
            total_distance += current_distance;
            count++;
        } else {
            for (int i = l; i <= r; i++) {
                // Swap
                int temp = arr[l];
                arr[l] = arr[i];
                arr[i] = temp;

                // Recursion
                permute(arr, l + 1, r);

                // Backtrack
                temp = arr[l];
                arr[l] = arr[i];
                arr[i] = temp;
            }
        }
    }

    // Call the permutation function
    permute(permutation, 0, N - 1);

    // Calculate the average distance
    double result = total_distance / count;

    // Print the result
    printf("%lf\n", result);

    // Free allocated memory
    free(indices);
    free(permutation);
}

int main() {
    // Read the number of points N
    int N;
    scanf("%d", &N);

    // Initialize arrays for x and y coordinates
    int *x = (int *)malloc(N * sizeof(int));
    int *y = (int *)malloc(N * sizeof(int));

    // Read the x and y coordinates for each point
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &x[i], &y[i]);
    }

    // Call the solve function with the input values
    solve(N, x, y);

    // Free allocated memory
    free(x);
    free(y);

    return 0;
}

// <END-OF-CODE>

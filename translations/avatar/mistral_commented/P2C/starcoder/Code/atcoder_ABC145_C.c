#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to find the solution
void solve(int N, int x[], int y[]) {
    // Initialize an empty list to store distances
    int distances[N];

    // Generate all possible permutations of indices from 0 to N-1
    int indices[N];
    for (int i = 0; i < N; i++) {
        indices[i] = i;
    }
    int permutations[N];
    int count = 0;
    do {
        for (int i = 0; i < N; i++) {
            permutations[i] = indices[i];
        }
        count++;

        // For each permutation, calculate the total distance between adjacent points
        int total_distance = 0;
        for (int i = 0; i < N - 1; i++) {
            // Get the first and second indices of the current pair
            int f = permutations[i];
            int t = permutations[i + 1];
            // Calculate the Euclidean distance between the points (x[f], y[f]) and (x[t], y[t])
            double distance = sqrt(pow(x[t] - x[f], 2) + pow(y[t] - y[f], 2));
            // Add the distance to the total distance
            total_distance += distance;
        }

        // Append the total distance to the distances list
        distances[count - 1] = total_distance;
    } while (next_permutation(indices, indices + N));

    // Calculate the average distance from all permutations
    double result = 0;
    for (int i = 0; i < N; i++) {
        result += distances[i];
    }
    result /= N;

    // Print the result
    printf("%.10lf\n", result);
}

// Main function to read input and call the solve function
int main() {
    // Read the number of points and their coordinates from input
    int N;
    scanf("%d", &N);
    int x[N];
    int y[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &x[i]);
        scanf("%d", &y[i]);
    }

    // Call the solve function with the given input
    solve(N, x, y);

    // Return from main function
    return 0;
}


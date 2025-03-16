
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void solve(int N, int* x, int* y) {
    // Create a list of indices from 0 to N-1
    int* indices = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        indices[i] = i;
    }
    
    // Generate all possible permutations of the indices
    int* permutations = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        permutations[i] = indices[i];
    }
    
    // Initialize a list to store the total distances for each permutation
    double* distances = (double*)malloc(N * sizeof(double));
    
    // Iterate through each permutation of indices
    for (int i = 0; i < N; i++) {
        double total_distance = 0;
        
        // Calculate the total distance for the current permutation
        for (int j = 0; j < N - 1; j++) {
            int f = permutations[j];
            int t = permutations[j + 1];
            // Calculate the Euclidean distance between the two points
            double distance = sqrt(pow(x[t] - x[f], 2) + pow(y[t] - y[f], 2));
            total_distance += distance;  // Accumulate the total distance
        }
        
        // Append the total distance for the current permutation to the list
        distances[i] = total_distance;
    }
    
    // Calculate the average distance across all permutations
    double result = 0;
    for (int i = 0; i < N; i++) {
        result += distances[i];
    }
    result /= N;
    
    // Print the average distance
    printf("%f\n", result);
    
    // Free allocated memory
    free(indices);
    free(permutations);
    free(distances);
}

int main() {
    // Generator function to iterate over tokens from standard input
    char* token = NULL;
    char* saveptr = NULL;
    
    // Read the number of points
    int N = strtol(strptime(NULL, "%d", &token), &saveptr, 10);
    
    // Initialize lists to store x and y coordinates
    int* x = (int*)malloc(N * sizeof(int));
    int* y = (int*)malloc(N * sizeof(int));
    
    // Read the x and y coordinates for each point
    for (int i = 0; i < N; i++) {
        x[i] = strtol(strptime(NULL, "%d", &token), &saveptr, 10);
        y[i] = strtol(strptime(NULL, "%d", &token), &saveptr, 10);
    }
    
    // Call the solve function with the number of points and their coordinates
    solve(N, x, y);
    
    // Free allocated memory
    free(x);
    free(y);
    
    return 0;
}


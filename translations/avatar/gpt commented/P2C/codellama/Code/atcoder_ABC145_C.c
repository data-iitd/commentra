#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Generator function to iterate over tokens from standard input
void iterate_tokens(char **token) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    while ((read = getline(&line, &len, stdin)) != -1) {
        char *word = strtok(line, " ");
        while (word != NULL) {
            *token = word;
            word = strtok(NULL, " ");
            yield;
        }
    }
    free(line);
}

// Calculate the Euclidean distance between two points
double distance(int x1, int y1, int x2, int y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

// Calculate the average distance across all permutations
double average_distance(int N, int *x, int *y) {
    // Create a list of indices from 0 to N-1
    int *indices = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        indices[i] = i;
    }
    
    // Generate all possible permutations of the indices
    int *permutation = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        permutation[i] = i;
    }
    
    // Initialize a list to store the total distances for each permutation
    double *distances = (double *)malloc(N * sizeof(double));
    
    // Iterate through each permutation of indices
    for (int i = 0; i < N; i++) {
        double total_distance = 0;
        
        // Calculate the total distance for the current permutation
        for (int j = 0; j < N - 1; j++) {
            int f = permutation[j];
            int t = permutation[j + 1];
            // Calculate the Euclidean distance between the two points
            double distance = sqrt((x[t] - x[f]) * (x[t] - x[f]) + (y[t] - y[f]) * (y[t] - y[f]));
            total_distance += distance;
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
    printf("%lf\n", result);
    
    // Free memory
    free(indices);
    free(permutation);
    free(distances);
    
    return result;
}

// Entry point of the program
int main() {
    // Create an iterator for the input tokens
    char *token;
    iterate_tokens(&token);
    
    // Read the number of points
    int N = atoi(token);
    
    // Initialize lists to store x and y coordinates
    int *x = (int *)malloc(N * sizeof(int));
    int *y = (int *)malloc(N * sizeof(int));
    
    // Read the x and y coordinates for each point
    for (int i = 0; i < N; i++) {
        x[i] = atoi(token);
        y[i] = atoi(token);
    }
    
    // Call the solve function with the number of points and their coordinates
    average_distance(N, x, y);
    
    // Free memory
    free(x);
    free(y);
    
    return 0;
}


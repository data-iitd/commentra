#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Function to calculate the Euclidean distance between two points
double calculate_distance(int x1, int y1, int x2, int y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

// Function to solve the problem
void solve(int N, int* x, int* y) {
    double total_distance = 0.0;
    int indices[N];
    
    // Initialize the indices array with values from 0 to N-1
    for (int i = 0; i < N; i++) {
        indices[i] = i;
    }
    
    // Generate all possible permutations of the indices
    do {
        double current_distance = 0.0;
        
        // Calculate the total distance for the current permutation
        for (int i = 0; i < N - 1; i++) {
            int f = indices[i];
            int t = indices[i + 1];
            // Calculate the Euclidean distance between the two points
            current_distance += calculate_distance(x[f], y[f], x[t], y[t]);
        }
        
        // Accumulate the total distance
        total_distance += current_distance;
    } while (next_permutation(indices, indices + N));
    
    // Calculate the average distance across all permutations
    double result = total_distance / (double)N;
    
    // Print the average distance
    printf("%.10f\n", result);
}

// Function to generate the next permutation in lexicographical order
int next_permutation(int* array, int size) {
    int i = size - 2;
    while (i >= 0 && array[i] >= array[i + 1]) {
        i--;
    }
    if (i < 0) {
        return 0;
    }
    int j = size - 1;
    while (array[j] <= array[i]) {
        j--;
    }
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
    int left = i + 1;
    int right = size - 1;
    while (left < right) {
        temp = array[left];
        array[left] = array[right];
        array[right] = temp;
        left++;
        right--;
    }
    return 1;
}

// Main function to read input and call the solve function
int main() {
    int N;
    scanf("%d", &N);
    
    int* x = (int*)malloc(N * sizeof(int));
    int* y = (int*)malloc(N * sizeof(int));
    
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

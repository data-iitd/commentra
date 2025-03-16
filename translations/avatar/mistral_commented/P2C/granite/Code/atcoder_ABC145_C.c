
#include <stdio.h>
#include <math.h>

// Function to find the solution
void solve(int N, int* x, int* y) {
    // Initialize an empty list to store distances
    double distances[N] = {0};

    // Generate all possible permutations of indices from 0 to N-1
    int indices[N];
    for (int i = 0; i < N; i++) {
        indices[i] = i;
    }
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            // Swap the elements at indices i and j
            int temp = indices[i];
            indices[i] = indices[j];
            indices[j] = temp;

            // Calculate the total distance between adjacent points
            double total_distance = 0;
            for (int k = 0; k < N - 1; k++) {
                // Get the first and second indices of the current pair
                int f = indices[k];
                int t = indices[k + 1];
                // Calculate the Euclidean distance between the points (x[f], y[f]) and (x[t], y[t])
                double distance = sqrt(pow(x[t] - x[f], 2) + pow(y[t] - y[f], 2));
                // Add the distance to the total distance
                total_distance += distance;
            }
            // Store the total distance in the distances array
            distances[i] = total_distance;

            // Swap the elements back to their original positions
            temp = indices[i];
            indices[i] = indices[j];
            indices[j] = temp;
        }
    }

    // Calculate the average distance from all permutations
    double result = 0;
    for (int i = 0; i < N; i++) {
        result += distances[i];
    }
    result /= N;

    // Print the result
    printf("%f\n", result);
}

// Main function to read input and call the solve function
int main() {
    // Read the number of points and their coordinates from input
    int N;
    scanf("%d", &N);
    int x[N];
    int y[N];
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &x[i], &y[i]);
    }

    // Call the solve function with the given input
    solve(N, x, y);

    return 0;
}

Translate the above C code to Rust and end with comment "
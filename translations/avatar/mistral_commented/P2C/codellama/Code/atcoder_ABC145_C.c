#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to find the solution
void solve(int N, int x[], int y[]) {
    // Initialize an empty list to store distances
    double distances[N];

    // Generate all possible permutations of indices from 0 to N-1
    int indices[N];
    for (int i = 0; i < N; i++) {
        indices[i] = i;
    }
    int permutations[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            permutations[i][j] = indices[j];
        }
    }

    // For each permutation, calculate the total distance between adjacent points
    for (int i = 0; i < N; i++) {
        double total_distance = 0;
        for (int j = 0; j < N - 1; j++) {
            // Get the first and second indices of the current pair
            int f = permutations[i][j];
            int t = permutations[i][j + 1];
            // Calculate the Euclidean distance between the points (x[f], y[f]) and (x[t], y[t])
            double distance = sqrt((x[t] - x[f]) * (x[t] - x[f]) + (y[t] - y[f]) * (y[t] - y[f]));
            // Add the distance to the total distance
            total_distance += distance;
        }
        // Append the total distance to the distances list
        distances[i] = total_distance;
    }

    // Calculate the average distance from all permutations
    double result = 0;
    for (int i = 0; i < N; i++) {
        result += distances[i];
    }
    result /= N;

    // Print the result
    printf("%.2lf\n", result);
}

// Main function to read input and call the solve function
int main() {
    // Function to read tokens from standard input
    int iterate_tokens() {
        char line[1000];
        fgets(line, 1000, stdin);
        char* token = strtok(line, " ");
        int i = 0;
        while (token != NULL) {
            if (i == 0) {
                int N = atoi(token);
                int x[N];
                int y[N];
                for (int i = 0; i < N; i++) {
                    token = strtok(NULL, " ");
                    x[i] = atoi(token);
                    token = strtok(NULL, " ");
                    y[i] = atoi(token);
                }
                solve(N, x, y);
            }
            token = strtok(NULL, " ");
            i++;
        }
    }

    // Read the number of points and their coordinates from input
    iterate_tokens();

    return 0;
}

// END-OF-CODE

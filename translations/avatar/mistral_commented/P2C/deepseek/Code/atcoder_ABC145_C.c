#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <algorithm>

// Function to find the solution
void solve(int N, std::vector<int>& x, std::vector<int>& y) {
    // Initialize an empty list to store distances
    std::vector<double> distances;

    // Generate all possible permutations of indices from 0 to N-1
    std::vector<int> indices(N);
    for (int i = 0; i < N; ++i) {
        indices[i] = i;
    }

    do {
        double total_distance = 0;
        for (int i = 0; i < N - 1; ++i) {
            // Get the first and second indices of the current pair
            int f = indices[i];
            int t = indices[i + 1];
            // Calculate the Euclidean distance between the points (x[f], y[f]) and (x[t], y[t])
            double distance = sqrt(pow(x[t] - x[f], 2) + pow(y[t] - y[f], 2));
            // Add the distance to the total distance
            total_distance += distance;
        }
        // Append the total distance to the distances list
        distances.push_back(total_distance);
    } while (std::next_permutation(indices.begin(), indices.end()));

    // Calculate the average distance from all permutations
    double result = 0;
    for (double distance : distances) {
        result += distance;
    }
    result /= distances.size();

    // Print the result
    printf("%.10f\n", result);
}

// Main function to read input and call the solve function
int main() {
    int N;
    std::vector<int> x, y;

    // Read the number of points and their coordinates from input
    scanf("%d", &N);
    x.resize(N);
    y.resize(N);
    for (int i = 0; i < N; ++i) {
        scanf("%d %d", &x[i], &y[i]);
    }

    // Call the solve function with the given input
    solve(N, x, y);

    return 0;
}

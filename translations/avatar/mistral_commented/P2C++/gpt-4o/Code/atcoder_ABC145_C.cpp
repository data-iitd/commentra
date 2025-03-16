#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>

using namespace std;

// Function to find the solution
void solve(int N, const vector<int>& x, const vector<int>& y) {
    // Initialize a variable to store the total distance
    double total_distance_sum = 0;
    int permutation_count = 0;

    // Generate all possible permutations of indices from 0 to N-1
    vector<int> indices(N);
    iota(indices.begin(), indices.end(), 0); // Fill indices with 0, 1, ..., N-1

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
        // Add the total distance to the sum
        total_distance_sum += total_distance;
        permutation_count++;
    } while (next_permutation(indices.begin(), indices.end()));

    // Calculate the average distance from all permutations
    double result = total_distance_sum / permutation_count;

    // Print the result
    cout << result << endl;
}

// Main function to read input and call the solve function
int main() {
    // Read the number of points and their coordinates from input
    int N;
    cin >> N;
    vector<int> x(N), y(N);
    for (int i = 0; i < N; ++i) {
        cin >> x[i] >> y[i];
    }

    // Call the solve function with the given input
    solve(N, x, y);

    return 0;
}

// <END-OF-CODE>

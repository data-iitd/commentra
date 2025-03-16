#include <bits/stdc++.h>
using namespace std;

// Function to find the solution
void solve(int N, int x[], int y[]) {
    // Initialize an empty list to store distances
    vector<double> distances;

    // Generate all possible permutations of indices from 0 to N-1
    vector<int> indices(N);
    for (int i = 0; i < N; i++) {
        indices[i] = i;
    }
    do {
        // For each permutation, calculate the total distance between adjacent points
        double total_distance = 0;
        for (int i = 0; i < N - 1; i++) {
            // Get the first and second indices of the current pair
            int f = indices[i];
            int t = indices[i + 1];
            // Calculate the Euclidean distance between the points (x[f], y[f]) and (x[t], y[t])
            double distance = sqrt((x[t] - x[f]) * (x[t] - x[f]) + (y[t] - y[f]) * (y[t] - y[f]));
            // Add the distance to the total distance
            total_distance += distance;
        }
        // Append the total distance to the distances list
        distances.push_back(total_distance);
    } while (next_permutation(indices.begin(), indices.end()));

    // Calculate the average distance from all permutations
    double result = 0;
    for (double distance : distances) {
        result += distance;
    }
    result /= distances.size();

    // Print the result
    cout << result << endl;
}

// Main function to read input and call the solve function
int main() {
    // Read the number of points and their coordinates from input
    int N;
    cin >> N;
    int x[N], y[N];
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }

    // Call the solve function with the given input
    solve(N, x, y);

    return 0;
}


#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <cmath>

using namespace std;

int main() {
    // Read the number of points
    int N;
    cin >> N;
    
    // Initialize lists to store x and y coordinates
    vector<int> x(N), y(N);
    
    // Read the x and y coordinates for each point
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }
    
    // Call the solve function with the number of points and their coordinates
    solve(N, x, y);
}

// Function to calculate the average distance across all permutations
void solve(int N, vector<int> &x, vector<int> &y) {
    // Create a list of indices from 0 to N-1
    vector<int> indices(N);
    iota(indices.begin(), indices.end(), 0);
    
    // Generate all possible permutations of the indices
    vector<vector<int>> permutations;
    do {
        permutations.push_back(indices);
    } while (next_permutation(indices.begin(), indices.end()));
    
    // Initialize a list to store the total distances for each permutation
    vector<double> distances;
    
    // Iterate through each permutation of indices
    for (vector<int> &permutation : permutations) {
        double total_distance = 0;
        
        // Calculate the total distance for the current permutation
        for (int i = 0; i < N - 1; i++) {
            int f = permutation[i], t = permutation[i + 1];  // Get the current and next index
            // Calculate the Euclidean distance between the two points
            double distance = sqrt(pow(x[t] - x[f], 2) + pow(y[t] - y[f], 2));
            total_distance += distance;  // Accumulate the total distance
        }
        
        // Append the total distance for the current permutation to the list
        distances.push_back(total_distance);
    }
    
    // Calculate the average distance across all permutations
    double result = accumulate(distances.begin(), distances.end(), 0.0) / distances.size();
    
    // Print the average distance
    cout << result << endl;
}


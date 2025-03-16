#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <iterator>

using namespace std;

void solve(int N, vector<int>& x, vector<int>& y) {
    // Generate a list of indices from 0 to N-1
    vector<int> indices(N);
    iota(indices.begin(), indices.end(), 0);
    
    // Initialize a vector to store the total distances for each permutation
    vector<double> distances;
    
    // Generate all permutations of the indices
    do {
        // Initialize the total distance for the current permutation
        double total_distance = 0.0;
        
        // Calculate the distance between consecutive points in the permutation
        for (int i = 0; i < N - 1; ++i) {
            int f = indices[i];
            int t = indices[i + 1];
            double distance = sqrt(pow(x[t] - x[f], 2) + pow(y[t] - y[f], 2));
            total_distance += distance;
        }
        
        // Append the total distance of the current permutation to the distances vector
        distances.push_back(total_distance);
    } while (next_permutation(indices.begin(), indices.end()));
    
    // Calculate the average distance by averaging all stored distances
    double result = accumulate(distances.begin(), distances.end(), 0.0) / distances.size();
    
    // Print the result
    cout << result << endl;
}

int main() {
    // Read the number of points N
    int N;
    cin >> N;
    
    // Initialize vectors for x and y coordinates
    vector<int> x(N), y(N);
    
    // Read the x and y coordinates for each point
    for (int i = 0; i < N; ++i) {
        cin >> x[i] >> y[i];
    }
    
    // Call the solve function with the input values
    solve(N, x, y);
    
    return 0;
}

// <END-OF-CODE>

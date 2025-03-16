#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

void solve(int N, vector<int> x, vector<int> y) {
    // Create a list of indices from 0 to N-1
    vector<int> indices(N);
    iota(indices.begin(), indices.end(), 0);
    
    // Generate all possible permutations of the indices
    vector<vector<int>> permutations(N);
    do {
        // Calculate the total distance for the current permutation
        double total_distance = 0;
        for (int i = 0; i < N - 1; i++) {
            int f = permutations[i];
            int t = permutations[i + 1];
            // Calculate the Euclidean distance between the two points
            double distance = sqrt(pow(x[t] - x[f], 2) + pow(y[t] - y[f], 2));
            total_distance += distance;
        }
        
        // Append the total distance for the current permutation to the list
        distances.push_back(total_distance);
    } while (next_permutation(permutations.begin(), permutations.end()));
    
    // Calculate the average distance across all permutations
    double result = accumulate(distances.begin(), distances.end(), 0.0) / distances.size();
    
    // Print the average distance
    cout << result << endl;
    return;
}

int main() {
    // Generator function to iterate over tokens from standard input
    auto iterate_tokens() {
        string line;
        while (getline(cin, line)) {
            istringstream iss(line);
            for (string word; iss >> word; ) {
                yield word;
            }
        }
    }
    
    // Create an iterator for the input tokens
    auto tokens = iterate_tokens();
    
    // Read the number of points
    int N = stoi(next(tokens));
    
    // Initialize lists to store x and y coordinates
    vector<int> x(N);
    vector<int> y(N);
    
    // Read the x and y coordinates for each point
    for (int i = 0; i < N; i++) {
        x[i] = stoi(next(tokens));
        y[i] = stoi(next(tokens));
    }
    
    // Call the solve function with the number of points and their coordinates
    solve(N, x, y);
    
    return 0;
}


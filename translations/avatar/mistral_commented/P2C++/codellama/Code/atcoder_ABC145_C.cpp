#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

// Function to find the solution
void solve(int N, vector<int> x, vector<int> y) {
    // Initialize an empty list to store distances
    vector<double> distances;

    // Generate all possible permutations of indices from 0 to N-1
    vector<int> indices(N);
    iota(indices.begin(), indices.end(), 0);
    do {
        // Calculate the total distance between adjacent points
        double total_distance = 0;
        for (int i = 0; i < N - 1; i++) {
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
    } while (next_permutation(indices.begin(), indices.end()));

    // Calculate the average distance from all permutations
    double result = accumulate(distances.begin(), distances.end(), 0.0) / distances.size();

    // Print the result
    cout << result << endl;
}

// Main function to read input and call the solve function
int main() {
    // Function to read tokens from standard input
    auto iterate_tokens = [](istream& in) {
        string line;
        while (getline(in, line)) {
            istringstream iss(line);
            for (string word; iss >> word; ) {
                yield word;
            }
        }
    };

    // Read the number of points and their coordinates from input
    auto tokens = iterate_tokens(cin);
    int N = stoi(next(tokens));
    vector<int> x(N);
    vector<int> y(N);
    for (int i = 0; i < N; i++) {
        x[i] = stoi(next(tokens));
        y[i] = stoi(next(tokens));
    }

    // Call the solve function with the given input
    solve(N, x, y);

    return 0;
}

// 
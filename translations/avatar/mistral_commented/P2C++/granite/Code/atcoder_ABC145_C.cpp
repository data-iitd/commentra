
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

// Function to find the solution
void solve(int N, std::vector<int> x, std::vector<int> y) {
    // Initialize an empty vector to store distances
    std::vector<double> distances;

    // Generate all possible permutations of indices from 0 to N-1
    std::vector<int> indices(N);
    std::iota(indices.begin(), indices.end(), 0);
    do {
        // Calculate the total distance between adjacent points
        double total_distance = 0;
        for (int i = 0; i < N - 1; i++) {
            // Get the first and second indices of the current pair
            int f = indices[i], t = indices[i + 1];
            // Calculate the Euclidean distance between the points (x[f], y[f]) and (x[t], y[t])
            double distance = std::sqrt(std::pow(x[t] - x[f], 2) + std::pow(y[t] - y[f], 2));
            // Add the distance to the total distance
            total_distance += distance;
        }
        // Append the total distance to the distances vector
        distances.push_back(total_distance);
    } while (std::next_permutation(indices.begin(), indices.end()));

    // Calculate the average distance from all permutations
    double result = std::accumulate(distances.begin(), distances.end(), 0.0) / distances.size();

    // Print the result
    std::cout << result << std::endl;
}

// Main function to read input and call the solve function
int main() {
    // Function to read tokens from standard input
    std::istringstream iss;
    auto read_token = [&iss]() {
        std::string token;
        iss >> token;
        return token;
    };

    // Read the number of points and their coordinates from input
    int N = std::stoi(read_token());
    std::vector<int> x(N), y(N);
    for (int i = 0; i < N; i++) {
        x[i] = std::stoi(read_token());
        y[i] = std::stoi(read_token());
    }

    // Call the solve function with the given input
    solve(N, x, y);

    return 0;
}

// End of code
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>

using namespace std;

double calculateDistance(int f, int t, const vector<int>& x, const vector<int>& y) {
    return sqrt(pow(x[t] - x[f], 2) + pow(y[t] - y[f], 2));
}

double solve(int N, const vector<int>& x, const vector<int>& y) {
    vector<int> indices(N);
    iota(indices.begin(), indices.end(), 0); // Fill indices with 0, 1, ..., N-1

    double totalDistanceSum = 0.0;
    int permutationCount = 0;

    // Generate all permutations of indices
    do {
        double totalDistance = 0.0;

        // Calculate the total distance for the current permutation
        for (int i = 0; i < N - 1; ++i) {
            int f = indices[i];
            int t = indices[i + 1];
            totalDistance += calculateDistance(f, t, x, y);
        }

        totalDistanceSum += totalDistance;
        permutationCount++;
    } while (next_permutation(indices.begin(), indices.end()));

    // Calculate the average distance across all permutations
    double result = totalDistanceSum / permutationCount;

    // Print the average distance
    cout << result << endl;
    return result;
}

int main() {
    int N;
    cin >> N;

    vector<int> x(N);
    vector<int> y(N);

    // Read the x and y coordinates for each point
    for (int i = 0; i < N; ++i) {
        cin >> x[i] >> y[i];
    }

    // Call the solve function with the number of points and their coordinates
    solve(N, x, y);

    return 0;
}

// <END-OF-CODE>
